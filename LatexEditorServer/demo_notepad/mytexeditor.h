#ifndef MYTEXEDITOR_H
#define MYTEXEDITOR_H

#include <QPlainTextEdit>
#include <QWidget>

class MyTexEditor : public QPlainTextEdit
{
    Q_OBJECT
public:
    explicit MyTexEditor(QWidget *parent = nullptr);

signals:
};

#endif // MYTEXEDITOR_H
