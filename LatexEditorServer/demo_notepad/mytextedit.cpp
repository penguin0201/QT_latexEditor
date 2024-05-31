#include "mytextedit.h"
#include "ui_mytextedit.h"

#include <QFileDialog>
#include <QMessageBox>

MyTextEdit::MyTextEdit(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyTextEdit)
{
    ui->setupUi(this);
    ui->textEdit->setPlainText("");
    connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(onTextChanged()));
    connect(ui->textEdit->horizontalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(textEditHScrollBarChanged()));
    connect(ui->horizontalScrollBar, SIGNAL(valueChanged(int)), this, SLOT(scrollBarChanged()));
    connect(ui->textEdit->verticalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(textEditVScrollBarChanged()));
    connect(ui->textBrowser->verticalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(textBrowserVScrollBarChanged()));
    // highlightTimer = new QTimer(this);
    // connect(highlightTimer, &QTimer::timeout, this, &MyTextEdit::highlightTimeOut);
    // highlightTimer->start(1000);
    highlighter = new Highlighter(this->getTextEdit()->document());
    initFront();
}

MyTextEdit::~MyTextEdit()
{
    delete ui;
}

void MyTextEdit::textEditHScrollBarChanged()
{
    ui->horizontalScrollBar->setMaximum(ui->textEdit->horizontalScrollBar()->maximum());
    ui->horizontalScrollBar->setMinimum(ui->textEdit->horizontalScrollBar()->minimum());
    ui->horizontalScrollBar->setPageStep(ui->textEdit->horizontalScrollBar()->pageStep());
    ui->horizontalScrollBar->setValue(ui->textEdit->horizontalScrollBar()->value());
}

void MyTextEdit::textEditVScrollBarChanged()
{
    ui->textBrowser->verticalScrollBar()->setValue(ui->textEdit->verticalScrollBar()->value());
}

void MyTextEdit::textBrowserVScrollBarChanged()
{
    ui->textEdit->verticalScrollBar()->setValue(ui->textBrowser->verticalScrollBar()->value());
}

void MyTextEdit::scrollBarChanged()
{
    ui->textEdit->horizontalScrollBar()->setValue(ui->horizontalScrollBar->value());
}

void MyTextEdit::onTextChanged()
{
    int lineCountOfTextEdit = ui->textEdit->document()->lineCount();
    QString text = ui->textBrowser->toPlainText();
    int lineCountOfTextBrowser = text.trimmed().split("\n").length();

    if(initLine == false){
        for (int i = 0; i < lineCountOfTextEdit; ++i) {
            text+= QString::number(i+1)+"\n";
        }
        initLine =true;
    }else {
        if(lineCountOfTextBrowser>lineCountOfTextEdit)
        {
            for(int i = lineCountOfTextBrowser; i>lineCountOfTextEdit; i--){
                text.chop((QString::number(i+1)+"\n").length());
            }
        }else if(lineCountOfTextBrowser<lineCountOfTextEdit){
            for(int i = lineCountOfTextBrowser; i<lineCountOfTextEdit; i++){
                text += QString::number(i+1)+"\n";
            }
        }else if(lineCountOfTextEdit == 1 && text.length()<1){
            text+= QString::number(1)+"\n";
        }
    }

    ui->textBrowser->setMaximumWidth(25+QString::number(lineCountOfTextEdit).length()*10);
    ui->textBrowser->setText(text);
    isSaved = false;
    // highlighter = new Highlighter(this->getTextEdit()->document());
}

void MyTextEdit::setText(const QString &text)
{
    ui->textEdit->setPlainText(text);
}

QString MyTextEdit::getText(){
    return ui->textEdit->toPlainText();
}

QTextEdit* MyTextEdit::getTextEdit()
{
    return ui->textEdit;
}

void MyTextEdit::openFile(QString fileName)
{
    mFileName = fileName;
}

bool MyTextEdit::saveFile()
{
    QString fileName;
    if(mFileName.isEmpty()){
        fileName =QFileDialog::getSaveFileName(this,"保存文件");
        mFileName =fileName;
    }else{
        fileName =mFileName;
    }
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly|QFile::Text)){
        QMessageBox::warning(this,"警告","无法保存文件:"+file.errorString());
        return false;
    }
    QTextStream out(&file);

    out << ui->textEdit->toPlainText().toUtf8();
    file.close();
    isSaved = true;
    return true;
}

bool MyTextEdit::saveAsFile()
{
    QString fileName=QFileDialog::getSaveFileName(this,"另存文件");
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly|QFile::Text)){
        QMessageBox::warning(this,"警告","无法保存文件:"+file.errorString());
        return false;
    }
    mFileName =fileName;
    QTextStream out(&file);
    QString text =ui->textEdit->toPlainText().toUtf8();
    out<<text;
    file.close();
    isSaved = true;
    return true;
}

void MyTextEdit::setFileName(QString fileName)
{
    mFileName = fileName;
}

QString MyTextEdit::getFileName()
{
    return mFileName;
}

bool MyTextEdit::checkSaved()
{
    return isSaved;
}

// void MyTextEdit::highlightTimeOut()
// {
//     highlighter = new Highlighter(this->getTextEdit()->document());
// }

void MyTextEdit::initFront()
{
    QFont font("Consolas",14);
    ui->textEdit->setFont(font);
    ui->textBrowser->setFont(font);
}

// void MyTextEdit::on_pushButton_clicked()
// {
//     highlighter = new Highlighter(this->getTextEdit()->document());
// }

