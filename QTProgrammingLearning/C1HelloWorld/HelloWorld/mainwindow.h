#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPushButton>
#include <QLabel>
#include "mainwindow2.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void mousePressEvent(QMouseEvent *e);

    void mouseMoveEvent(QMouseEvent *e);

    void mouseReleaseEvent(QMouseEvent *e);

private:
    QPushButton *btClose;
    QPoint last;
    QLabel *lable;
    QPushButton *button;
    MainWindow2 w2;

private slots:
    void showMainwindow2();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
