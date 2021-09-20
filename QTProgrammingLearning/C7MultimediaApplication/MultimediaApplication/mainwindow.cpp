#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//1.2 播放flash
//    QAxWidget *flash = new QAxWidget(0, 0);
//    flash->resize(460, 370);
//    flash->setControl(QString::fromUtf8("{d27cdb6e-ae6d-11cf-96b8-444553540000}"));

//    flash->dynamicCall("LoadMovie(long,string)",0,QDir::currentPath() +"/Qt02/map.swf");

//    QVBoxLayout *layout = new QVBoxLayout;
//    layout->addWidget(flash);

//    QWidget *widget = new QWidget();
//    widget->setLayout(layout);
//    this->setCentralWidget(widget);
//    this->setWindowTitle(QDir::currentPath());


//1.3 播放图片动画
    pm = new QPixmap;
    pm->load("./image/a0");



    label = new QLabel(this);
    label->setGeometry(QRect(50, 50, 350, 350));
    label->setPixmap(*pm);
    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(changeImg()));
    timer->start(1000);



}

MainWindow::~MainWindow()
{
    delete ui;
}


int i =-1;
void MainWindow::changeImg()
{
    if(i<3)
    {
        i++;
        QString str = "./image/a";
        pm->load(str.toUtf8().append(QString::number(i,10)));
        label->setPixmap(*pm);
    }
    else
        i=-1;
}




























