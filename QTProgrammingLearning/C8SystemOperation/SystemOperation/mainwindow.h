#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QDesktopWidget>
#include <QDebug>
#include <QtNetwork/QHostInfo>
#include <QListView>
#include <QStringListModel>
#include <QProcess>
#include <QLineEdit>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QProcess>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void clickExecution(); //点击按钮事件
    void readOutput(); //QProcess事件

private:
    QLineEdit *comm; //dos 命令输入框
    QPlainTextEdit *outEdit; //命令执行反馈框
    QPushButton *btClick; //执行按钮
    QProcess *process; //QProcess
    QString output; //接收反馈信息

private:
    Ui::MainWindow *ui;
    QLabel *label;
//    void  keyPressEvent (QKeyEvent *event);
};
#endif // MAINWINDOW_H
