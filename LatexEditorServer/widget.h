#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QTcpServer>
#include <QDebug>
#include <QFile>
#include <QTimer>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>

#define PORT 6969

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void sendData();
private slots:
    void newClientHandler();
    void readPendingData();
    void sendFile(const QString &fileName);
    void onTimeOut();

private:
    Ui::Widget *ui;
    QTcpServer* server;
    QTcpSocket* socket;
    bool isStart;
    bool isFind;
    QString fileName;
    qint64 fileSize;
    qint64 sendSize;
    qint64 recvSize;
    QFile file;
    QString myFilePath = "D:\\QTsoftware\\LatexEditorServer\\build\\Desktop_Qt_6_8_0_MinGW_64_bit-Debug\\";
    QTimer* myTimer;
    // QString fileListText;
    QSqlDatabase db;
    QSqlTableModel* m;
    QSqlQuery* query;
    int id = 1;
};
#endif // WIDGET_H
