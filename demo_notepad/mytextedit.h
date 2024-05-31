#ifndef MYTEXTEDIT_H
#define MYTEXTEDIT_H

#include <QWidget>
#include <QTextEdit>
#include <highlighter.h>
#include <QTimer>

namespace Ui {
class MyTextEdit;
}

class MyTextEdit : public QWidget
{
    Q_OBJECT

public:
    explicit MyTextEdit(QWidget *parent = nullptr);
    ~MyTextEdit();
    void setText(const QString &text);
    QString getText();
    QTextEdit* getTextEdit();
    void openFile(QString fileName);
    bool saveFile();
    bool saveAsFile();
    void setFileName(QString fileName);
    QString getFileName();
    bool checkSaved();
    // void highlightTimeOut();

private slots:
    void textEditHScrollBarChanged();
    void textEditVScrollBarChanged();
    void textBrowserVScrollBarChanged();
    void scrollBarChanged();
    void onTextChanged();

    // void on_pushButton_clicked();

private:
    Ui::MyTextEdit *ui;
    void initFront();
    Highlighter* highlighter;
    QString mFileName;
    bool isSaved = false;
    bool initLine = false;
    // QTimer* highlightTimer;
};

#endif // MYTEXTEDIT_H
