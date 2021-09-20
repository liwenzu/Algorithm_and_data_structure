#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QPlainTextEdit>
#include "TAesClass.h"
#include <QCryptographicHash>
#include <QTime>
#include <QLabel>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QLabel *label;
    QPushButton *btJ;
    QPushButton *btU;
    QLineEdit *edit;
    QPlainTextEdit *pEdit;
    QByteArray str;
    TAesClass *aes;

private slots:
    void encFun();
    void jieFun();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
