/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *new_file;
    QAction *open_file;
    QAction *save_file;
    QAction *save_as;
    QAction *paste;
    QAction *cut;
    QAction *copy;
    QAction *bolder;
    QAction *italics;
    QAction *underline;
    QAction *font;
    QAction *about;
    QAction *undo;
    QAction *redo;
    QAction *exit;
    QAction *print;
    QAction *clear_history;
    QAction *highlighter;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QProgressBar *progressBar;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *recent;
    QMenu *menu_2;
    QMenu *menu_3;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;
    QToolBar *toolBar_3;
    QToolBar *toolBar_4;
    QToolBar *toolBar_5;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1010, 661);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/pencil.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        new_file = new QAction(MainWindow);
        new_file->setObjectName("new_file");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        new_file->setIcon(icon1);
        open_file = new QAction(MainWindow);
        open_file->setObjectName("open_file");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        open_file->setIcon(icon2);
        save_file = new QAction(MainWindow);
        save_file->setObjectName("save_file");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        save_file->setIcon(icon3);
        save_as = new QAction(MainWindow);
        save_as->setObjectName("save_as");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/images/save_as.png"), QSize(), QIcon::Normal, QIcon::Off);
        save_as->setIcon(icon4);
        paste = new QAction(MainWindow);
        paste->setObjectName("paste");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/images/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        paste->setIcon(icon5);
        cut = new QAction(MainWindow);
        cut->setObjectName("cut");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/images/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        cut->setIcon(icon6);
        copy = new QAction(MainWindow);
        copy->setObjectName("copy");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/images/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        copy->setIcon(icon7);
        bolder = new QAction(MainWindow);
        bolder->setObjectName("bolder");
        bolder->setCheckable(true);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/images/bold.png"), QSize(), QIcon::Normal, QIcon::Off);
        bolder->setIcon(icon8);
        italics = new QAction(MainWindow);
        italics->setObjectName("italics");
        italics->setCheckable(true);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/images/italic.png"), QSize(), QIcon::Normal, QIcon::Off);
        italics->setIcon(icon9);
        underline = new QAction(MainWindow);
        underline->setObjectName("underline");
        underline->setCheckable(true);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/images/underline.png"), QSize(), QIcon::Normal, QIcon::Off);
        underline->setIcon(icon10);
        font = new QAction(MainWindow);
        font->setObjectName("font");
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/images/font.png"), QSize(), QIcon::Normal, QIcon::Off);
        font->setIcon(icon11);
        about = new QAction(MainWindow);
        about->setObjectName("about");
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/images/info.png"), QSize(), QIcon::Normal, QIcon::Off);
        about->setIcon(icon12);
        undo = new QAction(MainWindow);
        undo->setObjectName("undo");
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/images/images/edit_undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        undo->setIcon(icon13);
        redo = new QAction(MainWindow);
        redo->setObjectName("redo");
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/images/images/edit_redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        redo->setIcon(icon14);
        exit = new QAction(MainWindow);
        exit->setObjectName("exit");
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/images/images/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        exit->setIcon(icon15);
        print = new QAction(MainWindow);
        print->setObjectName("print");
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/images/images/print.png"), QSize(), QIcon::Normal, QIcon::Off);
        print->setIcon(icon16);
        clear_history = new QAction(MainWindow);
        clear_history->setObjectName("clear_history");
        highlighter = new QAction(MainWindow);
        highlighter->setObjectName("highlighter");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideMiddle);
        tabWidget->setTabsClosable(true);
        tabWidget->setMovable(true);

        horizontalLayout->addWidget(tabWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setLayoutDirection(Qt::LeftToRight);
        label->setStyleSheet(QString::fromUtf8("color: rgb(170, 85, 255);\n"
"font: 700 16pt \"Magneto\";"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        progressBar = new QProgressBar(widget);
        progressBar->setObjectName("progressBar");
        progressBar->setValue(24);

        verticalLayout_2->addWidget(progressBar);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName("lineEdit");

        verticalLayout_2->addWidget(lineEdit);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");

        verticalLayout_2->addWidget(pushButton);


        verticalLayout->addWidget(widget);


        horizontalLayout->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1010, 24));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        recent = new QMenu(menu);
        recent->setObjectName("recent");
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName("menu_3");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        statusbar->setStyleSheet(QString::fromUtf8("background-color: rgb(153, 153, 153);"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        toolBar->setStyleSheet(QString::fromUtf8("background-color: rgb(153, 153, 153);"));
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(MainWindow);
        toolBar_2->setObjectName("toolBar_2");
        toolBar_2->setStyleSheet(QString::fromUtf8("background-color: rgb(153, 153, 153);"));
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar_2);
        toolBar_3 = new QToolBar(MainWindow);
        toolBar_3->setObjectName("toolBar_3");
        toolBar_3->setStyleSheet(QString::fromUtf8("background-color: rgb(153, 153, 153);"));
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar_3);
        toolBar_4 = new QToolBar(MainWindow);
        toolBar_4->setObjectName("toolBar_4");
        toolBar_4->setStyleSheet(QString::fromUtf8("background-color: rgb(153, 153, 153);"));
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar_4);
        toolBar_5 = new QToolBar(MainWindow);
        toolBar_5->setObjectName("toolBar_5");
        toolBar_5->setStyleSheet(QString::fromUtf8("background-color: rgb(153, 153, 153);"));
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar_5);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menu->addAction(new_file);
        menu->addAction(open_file);
        menu->addAction(recent->menuAction());
        menu->addSeparator();
        menu->addAction(save_file);
        menu->addAction(save_as);
        menu->addSeparator();
        menu->addAction(print);
        menu->addSeparator();
        menu->addAction(exit);
        menu_2->addAction(copy);
        menu_2->addAction(paste);
        menu_2->addAction(cut);
        menu_2->addSeparator();
        menu_2->addAction(bolder);
        menu_2->addAction(italics);
        menu_2->addAction(underline);
        menu_2->addSeparator();
        menu_2->addAction(font);
        menu_3->addAction(about);
        toolBar->addAction(new_file);
        toolBar->addAction(open_file);
        toolBar->addAction(print);
        toolBar->addAction(save_file);
        toolBar->addAction(save_as);
        toolBar_2->addAction(copy);
        toolBar_2->addAction(paste);
        toolBar_2->addAction(cut);
        toolBar_3->addAction(bolder);
        toolBar_3->addAction(italics);
        toolBar_3->addAction(underline);
        toolBar_3->addAction(font);
        toolBar_4->addAction(undo);
        toolBar_4->addAction(redo);
        toolBar_5->addAction(about);
        toolBar_5->addAction(exit);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Demo-Notepad", nullptr));
        new_file->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\346\226\207\344\273\266", nullptr));
#if QT_CONFIG(shortcut)
        new_file->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        open_file->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
#if QT_CONFIG(shortcut)
        open_file->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        save_file->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\346\226\207\344\273\266", nullptr));
#if QT_CONFIG(shortcut)
        save_file->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        save_as->setText(QCoreApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272", nullptr));
#if QT_CONFIG(shortcut)
        save_as->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        paste->setText(QCoreApplication::translate("MainWindow", "\347\262\230\350\264\264", nullptr));
#if QT_CONFIG(shortcut)
        paste->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        cut->setText(QCoreApplication::translate("MainWindow", "\345\211\252\345\210\207", nullptr));
#if QT_CONFIG(shortcut)
        cut->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        copy->setText(QCoreApplication::translate("MainWindow", "\345\244\215\345\210\266", nullptr));
#if QT_CONFIG(shortcut)
        copy->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        bolder->setText(QCoreApplication::translate("MainWindow", "\345\212\240\347\262\227", nullptr));
#if QT_CONFIG(shortcut)
        bolder->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+B", nullptr));
#endif // QT_CONFIG(shortcut)
        italics->setText(QCoreApplication::translate("MainWindow", "\346\226\234\344\275\223", nullptr));
#if QT_CONFIG(shortcut)
        italics->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+I", nullptr));
#endif // QT_CONFIG(shortcut)
        underline->setText(QCoreApplication::translate("MainWindow", "\344\270\213\345\210\222\347\272\277", nullptr));
#if QT_CONFIG(shortcut)
        underline->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+U", nullptr));
#endif // QT_CONFIG(shortcut)
        font->setText(QCoreApplication::translate("MainWindow", "\346\250\241\347\211\210", nullptr));
#if QT_CONFIG(tooltip)
        font->setToolTip(QCoreApplication::translate("MainWindow", "\346\250\241\347\211\210", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        font->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+F", nullptr));
#endif // QT_CONFIG(shortcut)
        about->setText(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
#if QT_CONFIG(shortcut)
        about->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+I", nullptr));
#endif // QT_CONFIG(shortcut)
        undo->setText(QCoreApplication::translate("MainWindow", "\346\222\244\345\233\236", nullptr));
#if QT_CONFIG(shortcut)
        undo->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        redo->setText(QCoreApplication::translate("MainWindow", "\345\217\226\346\266\210\346\222\244\345\233\236", nullptr));
#if QT_CONFIG(shortcut)
        redo->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        exit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#if QT_CONFIG(shortcut)
        exit->setShortcut(QCoreApplication::translate("MainWindow", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        print->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\215\260", nullptr));
#if QT_CONFIG(shortcut)
        print->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+P", nullptr));
#endif // QT_CONFIG(shortcut)
        clear_history->setText(QCoreApplication::translate("MainWindow", "\346\270\205\351\231\244\346\211\223\345\274\200\345\216\206\345\217\262\350\256\260\345\275\225", nullptr));
#if QT_CONFIG(shortcut)
        clear_history->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Alt+Shift+C", nullptr));
#endif // QT_CONFIG(shortcut)
        highlighter->setText(QCoreApplication::translate("MainWindow", "\346\226\207\346\234\254\351\253\230\344\272\256", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "PDF View", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\346\237\245\346\211\276\346\226\207\344\273\266", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        recent->setTitle(QCoreApplication::translate("MainWindow", "\346\234\200\350\277\221\346\211\223\345\274\200", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
        toolBar_2->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar_2", nullptr));
        toolBar_3->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar_3", nullptr));
        toolBar_4->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar_4", nullptr));
        toolBar_5->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar_5", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
