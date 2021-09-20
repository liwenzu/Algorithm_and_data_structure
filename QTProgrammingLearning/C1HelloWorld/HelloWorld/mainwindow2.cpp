#include "mainwindow2.h"
#include "ui_mainwindow2.h"

MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);

    lable2 = new QLabel(this);
    lable2->setText("ETCT2");
    lable2->setGeometry(100,200,200,50);
}

MainWindow2::~MainWindow2()
{
    delete ui;
    delete lable2;
}
