#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include <QStandardItemModel>
#include <QPushButton>
#include <QThread>
#include <QProgressBar>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


private:
    QTableView *tableView;
    QStandardItemModel *model;
    QString cPid;
    QPushButton *starThread;
    QThread *thread;
    QPushButton *startButton;
    QProgressBar *progressBar;
    QProgressBar *progressBar2;

private slots:
    void sendContent(QModelIndex);
    void deletePro();
    void startFun();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
