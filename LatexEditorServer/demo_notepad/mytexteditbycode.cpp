#include "mytexteditbycode.h"

#include <QVBoxLayout>
#include <QHBoxLayout>


MyTextEditByCode::MyTextEditByCode(QWidget *parent) : QWidget(parent)
{
    //UI组件
    initWidget();

    //字体
    initFont();

    //绑定
    initConnection();

}

void MyTextEditByCode::initWidget()
{
    QWidget * horizontalLayoutWidget = new QWidget();
    //竖向布局
    QVBoxLayout *verticalLayout = new QVBoxLayout(this);

    verticalLayout->setSpacing(0);
    verticalLayout->setContentsMargins(0, 0, 0, 0);

    //横向布局
    QHBoxLayout *horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
    horizontalLayout->setSpacing(0);
    horizontalLayout->setContentsMargins(0, 0, 0, 0);

    textEdit = new QTextEdit();
    textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    textEdit->setLineWrapMode(QTextEdit::NoWrap);

    textBrowser = new QTextBrowser();
    textBrowser->setMaximumWidth(25);
    textBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scrollBar = new QScrollBar();
    scrollBar->setOrientation(Qt::Horizontal);

    horizontalLayout->addWidget(textBrowser);
    horizontalLayout->addWidget(textEdit);

    verticalLayout->addWidget(horizontalLayoutWidget);
    verticalLayout->addWidget(scrollBar);
}

void MyTextEditByCode::initFont()
{
    mFont = QFont("Consolas",14);
    textEdit->setFont(mFont);
    QTextBlockFormat format ;
    format.setLineHeight(QFontMetrics(mFont).height()*1.1,QTextBlockFormat::FixedHeight);

    QTextCursor cursor =  textEdit->textCursor();
    cursor.select(QTextCursor::Document);
    cursor.mergeBlockFormat(format);

    textBrowser->setFont(mFont);

}

void MyTextEditByCode::initConnection()
{
    //textChange
    connect(textEdit,SIGNAL(textChanged()),this,SLOT(onTextChanged()));

    //滚动条
    connect(textEdit->horizontalScrollBar(),SIGNAL(valueChanged(int)),this,SLOT(onTextEditHorizontalScrollBarChanged()));
    connect(textEdit->verticalScrollBar(),SIGNAL(valueChanged(int)),this,SLOT(onTextEditVerticalScrollBarChanged()));
    connect(scrollBar,SIGNAL(valueChanged(int)),this,SLOT(onScrollBarChanged()));
    connect(textBrowser->verticalScrollBar(),SIGNAL(valueChanged(int)),this,SLOT(onTextBrowserHorizontalScrollBarChanged()));

    //cursor
    connect(textEdit,SIGNAL(cursorPositionChanged()),this,SLOT(highlightCurrentLine()));
}


void MyTextEditByCode::onTextEditHorizontalScrollBarChanged(){
    scrollBar->setMaximum(textEdit->horizontalScrollBar()->maximum());
    scrollBar->setMinimum(textEdit->horizontalScrollBar()->minimum());
    scrollBar->setPageStep(textEdit->horizontalScrollBar()->pageStep());
    scrollBar->setValue(textEdit->horizontalScrollBar()->value());
}

void MyTextEditByCode::onTextEditVerticalScrollBarChanged(){
    textBrowser->verticalScrollBar()->setMaximum(textEdit->verticalScrollBar()->maximum());
    textBrowser->verticalScrollBar()->setMinimum(textEdit->verticalScrollBar()->minimum());
    textBrowser->verticalScrollBar()->setPageStep(textEdit->verticalScrollBar()->pageStep());
    textBrowser->verticalScrollBar()->setValue(textEdit->verticalScrollBar()->value());
}

void MyTextEditByCode::onScrollBarChanged(){
    textEdit->horizontalScrollBar()->setValue(scrollBar->value());
}

void MyTextEditByCode::onTextBrowserHorizontalScrollBarChanged(){
    textEdit->verticalScrollBar()->setValue(textBrowser->verticalScrollBar()->value());
}

void MyTextEditByCode::onTextChanged()
{
    int lineContOfTextEdit = textEdit->document()->lineCount();

    QString text = textBrowser->toPlainText();
    int lineContOfTextBrowser = text.trimmed().split("\n").length();

    if(lineContOfTextBrowser>lineContOfTextEdit){
        for(int i = lineContOfTextBrowser;i>lineContOfTextEdit;i--)
            text.chop((QString::number(i)+"\n").length());
    }else if(lineContOfTextBrowser==1&text.length()<1){
        text ="1\n";
    }else if(lineContOfTextBrowser<lineContOfTextEdit){
        for(int i = lineContOfTextBrowser;i<lineContOfTextEdit;i++)
            text +=QString::number(i+1)+"\n";
    }
    textBrowser->setMaximumWidth(25+QString::number(lineContOfTextEdit).length()*7);
    textBrowser->setText(text);

    QTextBlockFormat format ;
    format.setLineHeight(QFontMetrics(mFont).height()*1.1,QTextBlockFormat::FixedHeight);
    format.setAlignment(Qt::AlignRight);
    QTextCursor cursor =  textBrowser->textCursor();
    cursor.select(QTextCursor::Document);
    cursor.mergeBlockFormat(format);
}


