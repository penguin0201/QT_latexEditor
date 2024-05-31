#include "widget.h"
#include "ui_widget.h"
#include <QFileInfo>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    server = new QTcpServer;
    isStart = true;

    server->listen(QHostAddress::AnyIPv4, PORT);

    qDebug() << server->serverAddress();
    connect(server, &QTcpServer::newConnection, this, &Widget::newClientHandler);

    myTimer = new QTimer(this);
    connect(myTimer, &QTimer::timeout, this, &Widget::onTimeOut);

    //链接数据库
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:/SQlite_test/myFileDB.db");
    query = new QSqlQuery("D:/SQlite_test/myFileDB.db");

    if(db.open()){
        qDebug() << "db链接成功";
        m = new QSqlTableModel;
        m->setTable("file");
        ui->tableView->setModel(m);
    } else{
        qDebug() << "db链接失败";
    }


}

Widget::~Widget()
{
    delete ui;
}

void Widget::newClientHandler()
{
    qDebug() << 4;
    socket = server->nextPendingConnection();
    QString clientIP = socket->peerAddress().toString();
    QString clientPort =QString::number(socket->peerPort());

    qDebug() << 5;
    ui->ipLineEdit->setText(clientIP);
    ui->portLineEdit->setText(clientPort);

    connect(socket, &QTcpSocket::readyRead, this, &Widget::readPendingData);
}

void Widget::readPendingData()
{
    QByteArray array = socket->readAll();
    QString arrstr1 = QString(array).section("##",0,0);
    QString arrstr2 = QString(array).section("##",1,1);
    if(arrstr1 == "qqquery"){
        //tttttttttttt   bbbback
        query->exec("select * from file");
        isFind = false;
        while (query->next()) {
            if(query->value(0) == arrstr2){
                QString m_fileName = QString((myFilePath+arrstr2))+".tex";
                sendFile(m_fileName);
                isFind = true;
                break;
            }
        }
        if(isFind == false){
            QMessageBox::warning(this,"警告","未找到此文件");
        }
    }
    if(isStart == true && arrstr1!="qqquery"){
        isStart = false;
        //fileName##fileSize 拆包
        fileName = arrstr1;
        fileSize = arrstr2.toInt();

        recvSize = 0;
        file.setFileName(fileName);
        bool isOk =file.open(QIODevice::WriteOnly);
        if(isOk == false){
            qDebug() << "文件打开失败";
            socket->disconnectFromHost();
            socket->close();
        }
    } else if(isStart == false && arrstr1!="qqquery"){
        isStart = true;
        qint64 len = file.write(array);
        recvSize = len;
        if(recvSize == fileSize){
            file.close();
            qDebug() << "success";
            if(fileName.section(".",1,1) != "tex"){
                qDebug() << "not .tex";
                return;
            }
            std::string mycommand = "pdflatex " + (myFilePath+fileName).toStdString();
            qDebug() << mycommand;
            std::system(mycommand.c_str());
            qDebug() << "pdf compiling success";
            // fileListText += myFilePath+fileName+"\n";
            // ui->fileList->setText(fileListText);

            QList<QString> fileToDelete;
            query->exec("select * from file");
            while (query->next()) {
                if(query->value(0) == fileName.section(".",0,0)){
                    // query->exec("DELETE FROM file WHERE filename = "+fileName.section('.',0,0)+";");
                    qDebug() << "     Add delete "+fileName.section('.',0,0);
                    fileToDelete.append(fileName.section(".",0,0));
                }
            }
            foreach(QString fileStr, fileToDelete) {
                QString sql = QString("DELETE FROM file WHERE filename = '%1';").arg(fileStr);
                query->exec(sql);
                qDebug() << "     删除 delete "+fileStr+"    -----    "+"DELETE FROM file WHERE filename = "+fileStr+";";
            }
        }

        QString sql = QString("insert into file (filename, filepath) values ('%1', '%2');").arg(fileName.section(".",0,0), myFilePath+fileName);
        qDebug() << sql;
        if(query->exec(sql)){
            qDebug() << "插入成功";
        }
        m->select();
        //tttttttttttt   bbbback
        QString m_fileName = QString((myFilePath+fileName)).section(".",0,0)+".pdf";
        qDebug() << m_fileName;
        sendFile(m_fileName);
    }
}

void Widget::sendFile(const QString &m_fileName)
{
    QFileInfo info(m_fileName);
    fileName = info.fileName();
    fileSize = info.size();

    file.setFileName(m_fileName);

    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "文件未成功打开";
    }

    //发送文件头
    QString str = QString("%1##%2").arg(fileName).arg(fileSize);
    qint64 len = socket->write(str.toUtf8().data());
    if(len > 0){
        //发送真正内容，防止黏包
        myTimer->start(40);//间隔40ms，触发TimeOut信号
    } else{
        qDebug() << "发送文件内容失败";
        file.close();
        socket->disconnectFromHost();
        socket->close();
    }
}

void Widget::onTimeOut()
{
    myTimer->stop();
    qDebug() << "onTimeOut";
    sendData();
}

void Widget::sendData()
{
    qint64 len = 0;
    do{
        char buf[4*1024] = {0};
        //读取文件内容
        len = file.read(buf, sizeof(buf));
        //读多少发多少
        len = socket->write(buf, len);
        sendSize += len;
    }while (len>0);
    if(sendSize == fileSize){qDebug() << "send finished";}
}
