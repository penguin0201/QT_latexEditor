/********************************************************************************
** Form generated from reading UI file 'mytextedit.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYTEXTEDIT_H
#define UI_MYTEXTEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyTextEdit
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QTextBrowser *textBrowser;
    QTextEdit *textEdit;
    QScrollBar *horizontalScrollBar;

    void setupUi(QWidget *MyTextEdit)
    {
        if (MyTextEdit->objectName().isEmpty())
            MyTextEdit->setObjectName("MyTextEdit");
        MyTextEdit->resize(746, 503);
        verticalLayout = new QVBoxLayout(MyTextEdit);
        verticalLayout->setSpacing(1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(1);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(1, 1, 1, 1);
        textBrowser = new QTextBrowser(MyTextEdit);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setMaximumSize(QSize(25, 16777215));
        textBrowser->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 255);\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowser->setLineWrapMode(QTextEdit::NoWrap);

        horizontalLayout->addWidget(textBrowser);

        textEdit = new QTextEdit(MyTextEdit);
        textEdit->setObjectName("textEdit");
        textEdit->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 85, 255);\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit->setLineWrapMode(QTextEdit::NoWrap);

        horizontalLayout->addWidget(textEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalScrollBar = new QScrollBar(MyTextEdit);
        horizontalScrollBar->setObjectName("horizontalScrollBar");
        horizontalScrollBar->setMinimum(50);
        horizontalScrollBar->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalScrollBar);


        retranslateUi(MyTextEdit);

        QMetaObject::connectSlotsByName(MyTextEdit);
    } // setupUi

    void retranslateUi(QWidget *MyTextEdit)
    {
        MyTextEdit->setWindowTitle(QCoreApplication::translate("MyTextEdit", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyTextEdit: public Ui_MyTextEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYTEXTEDIT_H
