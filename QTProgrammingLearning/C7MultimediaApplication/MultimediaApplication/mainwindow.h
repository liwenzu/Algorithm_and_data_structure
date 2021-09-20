#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAxWidget>
#include <QWidget>
#include <QVBoxLayout>
#include <QDir>
#include <QLabel>
#include <QPixmap>
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    QPixmap *pm;
    QLabel *label;
    QTimer *timer;


private slots:
    void changeImg();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
