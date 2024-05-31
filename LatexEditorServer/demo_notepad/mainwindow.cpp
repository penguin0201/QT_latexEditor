#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "QFileDialog"
#include "QMessageBox"
#include "QFontDialog"
#include "QSettings"
#include "mytextedit.h"
#include <QFileInfo>
#include <highlighter.h>


QSettings * mSettings;

//获取历史记录
QList<QString> getHistory();
//保存打开历史记录
void saveHistory(QString path);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 初始化QPdfDocument和QPdfView
    pdfDocument = new QPdfDocument(this);
    pdfView = new QPdfView(this);

    if(mSettings==NULL){
        mSettings = new QSettings("settings.ini",QSettings::IniFormat);
    }

    isStart = true;

    initMenu();

    createSocket();

    ui->centralwidget->layout()->addWidget(ui->tabWidget);
    // 加载PDF文档
    QString pdfFilePath = "D:\\QTsoftware\\demo_notepad\\welcome.pdf";
    pdfDocument->load(pdfFilePath);
    pdfView->setDocument(pdfDocument);
    pdfView->setPageMode(QPdfView::PageMode::MultiPage);
    pdfView->setZoomMode(QPdfView::ZoomMode::FitToWidth);
    // 将QPdfView添加到中心部件的布局中
    ui->widget->layout()->addWidget(pdfView);
    ui->centralwidget->layout()->addWidget(ui->widget);

    //进度条
    ui->progressBar->setValue(0);

    myTimer = new QTimer(this);
    connect(myTimer, &QTimer::timeout, this, &MainWindow::onTimeOut);
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::readPendingData);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sendData()
{
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);
    ui->progressBar->setValue(0);
    qint64 len = 0;
    do{
        char buf[4*1024] = {0};
        //读取文件内容
        len = file.read(buf, sizeof(buf));
        //读多少发多少
        len = socket->write(buf, len);

        sendSize+=len;//已发送内容
        ui->progressBar->setValue(sendSize/fileSize*90);
    }while (len>0);

    if(sendSize == fileSize){
        ui->progressBar->setValue(90);
    }
}

//初始化菜单 有BUG
//BBBBBUG
void MainWindow::initMenu()
{
    //获取Menu
    QMenu * recent = this->findChild<QMenu *>("recent");
    //获取Action
    QList<QObject *> chLists =recent->children();
    foreach(QObject * ch,chLists){
        qDebug() << "333";
        QAction *action = (QAction *)ch;
        //清空子菜单Action
        qDebug() << "444";
        recent->removeAction(action);
        qDebug()<< "555";
    }

    qDebug() << "ssss";
    QList<QString> lists = getHistory();

    for(int i=lists.size()-1 ;i>=0;i--){
        //生成子菜单Action
        recent->addAction(lists[i],this,&MainWindow::on_open_rencent_file);
    }

    if(lists.size()>0){
        recent->addAction("清除历史记录", QKeySequence("Ctrl+Alt+Shift+C"), this, &MainWindow::on_clear_history_triggered);
    }

}

void MainWindow::createSocket()
{
    // 192.168.137.1
    //Port 6969
    socket = new QTcpSocket;
    QString IP = "127.0.0.1";
    QString port = "6969";

    socket->connectToHost(QHostAddress(IP), port.toShort());

    //连接成功，socket发出信号
    connect(socket, &QTcpSocket::connected, this, [this]() {
        QMessageBox::information(this, "socket链接提示", "链接成功");
    }, Qt::DirectConnection);

    //连接断开，socket也发出信号
    connect(socket, &QTcpSocket::disconnected, this, [this](){
        QMessageBox::warning(this, "socket链接提示", "链接断开");
    }, Qt::DirectConnection);
}


//获取历史记录
QList<QString> getHistory(){
    //打开开始读
    int size =mSettings->beginReadArray("history");

    //创建返回对象
    QList<QString> lists;
    for(int i = 0;i<size;i++){
        mSettings->setArrayIndex(i);
        QString path = mSettings->value("path").toString();
        lists.append(path);
        // qDebug()<<i<<":"<<path;
    }
    //关闭读
    mSettings->endArray();

    return lists;
}


//保存打开历史记录
void saveHistory(QString path){

    //获取历史
    QList<QString> lists = getHistory();
    foreach(QString str,lists){
        if(str==path){
            lists.removeOne(str);
        }
    }
    lists.append(path);

    //打开开始写入
    mSettings->beginWriteArray("history");
    for(int i =0;i<lists.size();i++){
        mSettings->setArrayIndex(i);
        //保存字符串
        mSettings->setValue("path",lists[i]);
    }

    //关闭开始写入
    mSettings->endArray();
}



//新建文件
void MainWindow::on_new_file_triggered()
{
    MyTextEdit* mmyTextEdit = new MyTextEdit(this);
    highlighter = new Highlighter(mmyTextEdit->getTextEdit()->document());
    ui->tabWidget->addTab(mmyTextEdit, "NewTab");
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);
}


//打开最近文件
void MainWindow::on_open_rencent_file()
{
    QAction * action = (QAction *)sender();

    QString fileName = action->text();

    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly|QFile::Text)){
        QMessageBox::warning(this,"警告","无法打开此文件"+file.errorString());
        return;
    }
    currentFile = fileName;
    QTextStream in(&file);
    QString text = in.readAll();
    MyTextEdit* myTextEdit = new MyTextEdit(this);
    myTextEdit->setText(text);
    myTextEdit->openFile(fileName);
    ui->tabWidget->addTab(myTextEdit,currentFile);
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);
    file.close();
    saveHistory(currentFile);
    initMenu();
}

//打开文件
void MainWindow::on_open_file_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,"打开文件", QCoreApplication::applicationFilePath(), "Text files (*.tex *.txt );;All files (*)");
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly|QFile::Text)){
        QMessageBox::warning(this,"警告","无法打开此文件:"+file.errorString());
        return;
    }
    currentFile = fileName;
    QTextStream in(&file);
    QString text = in.readAll();
    MyTextEdit* myTextEdit = new MyTextEdit(this);
    myTextEdit->setText(text);
    myTextEdit->openFile(fileName);
    ui->tabWidget->addTab(myTextEdit,currentFile);
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);
    file.close();
    qDebug() << "openFile";
    saveHistory(currentFile);
    qDebug() << "saveHistory";
    initMenu();
    qDebug() << "initMenu";
}


//保存文件
void MainWindow::on_save_file_triggered()
{
    MyTextEdit *myTextEdit = (MyTextEdit* )ui->tabWidget->currentWidget();
    if(myTextEdit){
        if(myTextEdit->saveFile()){
            QString fileName = myTextEdit->getFileName();
            saveHistory(fileName);
            ui->tabWidget->setTabText(ui->tabWidget->currentIndex(),fileName);
            initMenu();
        }
    }

}

//另存为
void MainWindow::on_save_as_triggered()
{
    MyTextEdit *myTextEdit = (MyTextEdit* )ui->tabWidget->currentWidget();
    if(myTextEdit){
        if(myTextEdit->saveAsFile()){
            QString fileName = myTextEdit->getFileName();
            saveHistory(fileName);
            ui->tabWidget->setTabText(ui->tabWidget->currentIndex(),fileName);
            initMenu();
        }
    }
}

//打印
void MainWindow::on_print_triggered()
{
    MyTextEdit *myTextEdit = (MyTextEdit* )ui->tabWidget->currentWidget();
    if(myTextEdit->getFileName().isEmpty()){
        QMessageBox::warning(this,"警告","文件未保存");
    }else {
        sendFile(myTextEdit->getFileName());
    }
}

void MainWindow::sendFile(const QString &m_fileName)
{
    // QFile file(m_fileName);
    qDebug() << "m_fileName:  "+m_fileName;
    QFileInfo info(m_fileName);
    fileName = info.fileName();
    fileSize = info.size();

    sendSize = 0;//初始化发送文件大小

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

//复制
void MainWindow::on_copy_triggered()
{
    MyTextEdit* myTextEdit = (MyTextEdit*) ui->tabWidget->currentWidget();
    if(myTextEdit){
        myTextEdit->getTextEdit()->copy();
    }
}

//粘贴
void MainWindow::on_paste_triggered()
{
    MyTextEdit* myTextEdit = (MyTextEdit*) ui->tabWidget->currentWidget();
    if(myTextEdit){
        myTextEdit->getTextEdit()->paste();
    }
}

//剪切
void MainWindow::on_cut_triggered()
{
    MyTextEdit* myTextEdit = (MyTextEdit*) ui->tabWidget->currentWidget();
    if(myTextEdit){
        myTextEdit->getTextEdit()->cut();
    }
}

//斜体
void MainWindow::on_italics_triggered()
{
    MyTextEdit* myTextEdit = (MyTextEdit*) ui->tabWidget->currentWidget();
    if(myTextEdit){
        QTextCursor cursor = myTextEdit->getTextEdit()->textCursor();
        QString selectedText = cursor.selectedText();
        // 检查是否有文本被选中
        if (!cursor.hasSelection()) {
            // 如果没有选中的文本，可以在这里处理，例如提示用户
            qDebug() << "No text selected";
        } else {
            // 删除选中的文本
            cursor.removeSelectedText();
            // 插入"test"
            cursor.insertText("\\textit{"+selectedText+"}");
        }
    }
}

//下划线
void MainWindow::on_underline_triggered()
{
    MyTextEdit* myTextEdit = (MyTextEdit*) ui->tabWidget->currentWidget();
    if(myTextEdit){
        QTextCursor cursor = myTextEdit->getTextEdit()->textCursor();
        QString selectedText = cursor.selectedText();
        // 检查是否有文本被选中
        if (!cursor.hasSelection()) {
            // 如果没有选中的文本，可以在这里处理，例如提示用户
            qDebug() << "No text selected";
        } else {
            // 删除选中的文本
            cursor.removeSelectedText();
            // 插入"test"
            cursor.insertText("\\underline{"+selectedText+"}");
        }
    }
}

//加粗
void MainWindow::on_bolder_triggered()
{
    MyTextEdit* myTextEdit = (MyTextEdit*) ui->tabWidget->currentWidget();
    if(myTextEdit){
        QTextCursor cursor = myTextEdit->getTextEdit()->textCursor();
        QString selectedText = cursor.selectedText();
        // 检查是否有文本被选中
        if (!cursor.hasSelection()) {
            // 如果没有选中的文本，可以在这里处理，例如提示用户
            qDebug() << "No text selected";
        } else {
            // 删除选中的文本
            cursor.removeSelectedText();
            // 插入"test"
            cursor.insertText("\\textbf{"+selectedText+"}");
        }
    }
}

//撤销
void MainWindow::on_undo_triggered()
{
    MyTextEdit* myTextEdit = (MyTextEdit*) ui->tabWidget->currentWidget();
    if(myTextEdit){
        // ui->textEdit->undo();
        myTextEdit->getTextEdit()->undo();
    }
}

//取消撤销
void MainWindow::on_redo_triggered()
{
    MyTextEdit* myTextEdit = (MyTextEdit*) ui->tabWidget->currentWidget();
    if(myTextEdit){
        myTextEdit->getTextEdit()->redo();
    }
}

//模版
void MainWindow::on_font_triggered()
{
    MyTextEdit* myTextEdit = (MyTextEdit*) ui->tabWidget->currentWidget();
    if(myTextEdit){
        myTextEdit->getTextEdit()->setText("\\documentclass[a4paper, 12pt]{article}\n\n\\begin{document}\n\n\\title{My First Document}\n\\author{My Name}\n\\date{\\today}\n\\maketitle\n\n\\section{Introduction}\nThis is the introduction.\n\n\\section{Methods}\n\n\\subsection{Stage 1}\nThe first part of the methods.\n\n\\subsection{Stage 2}\nThe second part of the methods.\n\n\\section{Results}\nHere are my results. Referring to section \\ref{sec1} on page \\pageref{sec1}\n\n\\end{document}");
    }
}

//关于
void MainWindow::on_about_triggered()
{
    QMessageBox::about(this,"这是我的LatexEditor！","这是我的LatexEditor，欢迎学习和使用！");
}


//退出
void MainWindow::on_exit_triggered()
{
    QCoreApplication::exit();
}


void MainWindow::on_clear_history_triggered()
{
    qDebug()<<"on_clear_history_triggered clicked...";
    mSettings->remove("history");
    initMenu();
}


void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    MyTextEdit* myTextEdit = (MyTextEdit*)ui->tabWidget->widget(index);
    qDebug() << myTextEdit->getFileName();
    if(!myTextEdit->checkSaved()){
        QMessageBox::StandardButton btn = QMessageBox::question(this, "警告", "文档未保存！", QMessageBox::Yes|QMessageBox::No);
        if(btn == QMessageBox::Yes){
            if(myTextEdit->saveFile()){
                QString fileName = myTextEdit->getFileName();
                saveHistory(fileName);
                ui->tabWidget->setTabText(index,fileName);
                initMenu();
            }
        }
    }
    ui->tabWidget->removeTab(index);
    delete myTextEdit;
}

void MainWindow::onTimeOut()
{
    myTimer->stop();
    sendData();
}

void MainWindow::readPendingData()
{
    QByteArray array = socket->readAll();
    qDebug() << "       mes come fuckkkkkkkkkk";

        QByteArray first50Bytes;
        if (array.size() > 50) {
            first50Bytes = array.left(50); // 取前100个字节
        } else {
            first50Bytes = array; // 如果array的大小小于100字节，就取整个array
        }

    qDebug() << "------------------------>>>>>>>"+first50Bytes;

    if(isStart == true){
        qDebug() << "1 parts";
        isStart = false;
        //fileName##fileSize 拆包
        fileName = QString(array).section("##",0,0);
        fileSize = QString(array).section("##",1,1).toInt();
        // qDebug() << fileName;
        // qDebug() << fileSize;

        recvSize = 0;
        // qDebug() << "11111";
        file.setFileName(fileName);
        // qDebug() << "222222";
        bool isOk =file.open(QIODevice::WriteOnly);
        // qDebug() << "333333";
        if(isOk == false){
            qDebug() << "文件打开失败";
            // socket->disconnectFromHost();
            // socket->close();
        }
    } else if(isStart == false){
        qDebug() << "2 parts";
        isStart = true;
        qint64 len = file.write(array);
        qDebug() << "file write  514";
        recvSize += len;
        if(recvSize == fileSize){
            ui->progressBar->setValue(100);
            file.close();
            qDebug() << "success";
            if(fileName.section(".",1,1) == "pdf")
            {
                qDebug() <<"                    接收pdf";
                // 加载PDF文档
                QString pdfFilePath = myFilePath+fileName;
                pdfDocument->load(pdfFilePath);
                pdfView->setDocument(pdfDocument);
                // 将QPdfView添加到中心部件的布局中
                ui->widget->layout()->addWidget(pdfView);
                ui->centralwidget->layout()->addWidget(ui->widget);
            } else{
                qDebug() <<"接收不是pdf";
                QFile file(myFilePath+fileName);
                if(!file.open(QIODevice::ReadOnly|QFile::Text)){
                    QMessageBox::warning(this,"警告","无法打开此文件:"+file.errorString());
                    return;
                }
                currentFile = myFilePath+fileName;
                QTextStream in(&file);
                QString text = in.readAll();
                MyTextEdit* myTextEdit = new MyTextEdit(this);
                myTextEdit->setText(text);
                myTextEdit->openFile(myFilePath+fileName);
                ui->tabWidget->addTab(myTextEdit,currentFile);
                ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);
                file.close();
                qDebug() << "openFile";
                saveHistory(currentFile);
                qDebug() << "saveHistory";
                initMenu();
                qDebug() << "initMenu";
            }
        }else{
            qDebug() << "                      未全部接收";
            isStart = false;
        }
    }
}


void MainWindow::on_pushButton_clicked()
{
    QString filename = ui->lineEdit->text();
    QString mess = QString("%1##%2").arg("qqquery").arg(filename);
    socket->write(mess.toUtf8().data());
}

