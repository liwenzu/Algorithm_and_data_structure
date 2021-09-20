#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    this->setWindowTitle("QT测试程序");
//    this->setMaximumSize(500,300);
//    this->setMinimumSize(300,300);


//    this->move(600,600);
//    this->setStyleSheet("background:red");
//    this->setWindowIcon(QIcon(":/new/prefix1/qt"));


//    this->setWindowTitle("移动无边框窗体");
//    this->setWindowFlags(Qt::FramelessWindowHint);

//关闭按钮失效或者最小化或最大化按钮失效
//    this->setWindowFlags(Qt::WindowMinMaxButtonsHint);
//    this->setWindowFlags(Qt::WindowCloseButtonHint);

    btClose = new QPushButton(this);
    btClose->setText("关闭窗口");

    connect(btClose, SIGNAL(clicked()), this, SLOT(close()));


    lable = new QLabel(this);
    lable->setText("CETC");
    lable->setGeometry(200,200,200,25);



//    button = new QPushButton(this);
//    button->setText("调用第二个窗口按钮");
//    button->setGeometry(50,50,200,50);

//    connect(button, SIGNAL(clicked()), this, SLOT(showMainwindow2()));



//字体形状窗体
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground, true);
    setStyleSheet("background-image:url(:/new/prefix1/qt2);background-repeat:no-repeat;");


}

MainWindow::~MainWindow()
{
    delete ui;
    delete btClose;
    delete lable;
    delete  button;
}




void MainWindow::mousePressEvent(QMouseEvent *e)
{
    last = e->globalPos();
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();

    last = e->globalPos();
    move(x()+dx, y()+dy);
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    move(x()+dx, y()+dy);
}



void MainWindow::showMainwindow2()
{
    w2.show();
}






















