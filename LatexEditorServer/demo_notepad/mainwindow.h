#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPdfView>
#include <QPdfDocument>
#include <QTcpSocket>
#include <QHostAddress>
#include <QFile>
#include <QTimer>
#include <highlighter.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void sendData();


private slots:
    void on_new_file_triggered();

    void on_open_file_triggered();

    void on_save_file_triggered();

    void on_save_as_triggered();

    void on_paste_triggered();

    void on_cut_triggered();

    void on_copy_triggered();

    void on_italics_triggered();

    void on_underline_triggered();

    void on_bolder_triggered();

    void on_font_triggered();

    void on_about_triggered();

    void on_undo_triggered();

    void on_redo_triggered();

    void on_exit_triggered();

    void on_print_triggered();

    void sendFile(const QString &fileName);

    void on_clear_history_triggered();

    void on_tabWidget_tabCloseRequested(int index);

    void onTimeOut();

    void readPendingData();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QString currentFile;
    QPdfDocument *pdfDocument;
    QPdfView *pdfView;
    void initMenu();
    void createSocket();
    void on_open_rencent_file();
    QTcpSocket* socket;
    QString fileName;
    qint64 fileSize;
    qint64 sendSize;
    qint64 recvSize;
    QFile file;
    QTimer* myTimer;
    QString myFilePath = "D:\\QTsoftware\\demo_notepad\\build\\Desktop_Qt_6_8_0_MinGW_64_bit-Debug\\";
    bool isStart;
    Highlighter* highlighter;
};
#endif // MAINWINDOW_H
