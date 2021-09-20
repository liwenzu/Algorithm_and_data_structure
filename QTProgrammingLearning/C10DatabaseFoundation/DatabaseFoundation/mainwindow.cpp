#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QDir>
#include <QTableView>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

// 查询数据库驱动
//    QStringList drivers = QSqlDatabase::drivers();
//    foreach (QString driver, drivers) {
//        qDebug() << "\r" << driver;
//    }


//1.2 Qodbc连接Access数据库
//    QLabel *label = new QLabel(this);
//    label->setGeometry(QRect(50, 50, 200, 25));
//    this->setWindowTitle(QDir::currentPath()+"/db.mdb");
//    if(openConnection())
//    {
//        label->setText("连接成功");
//    }else
//    {
//        label->setText("连接失败");
//    }
//    QTableView *tableView = new QTableView(this);
//    tableView->setGeometry(QRect(50, 80, 310, 200));



}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::openConnection()
{
   db = QSqlDatabase::addDatabase("QODBC");
//   db.setDatabaseName("DRIVER={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ="+QDir::currentPath()+"/db.mdb;UID='';PWD=''");
   db.setDatabaseName("DRIVER={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ=D:/MY_COMPUTER/F/QTProgrammingLearning/C10DatabaseFoundation/build-DatabaseFoundation-Desktop_Qt_5_14_2_MSVC2017_64bit-Debug/db.mdb;UID='';PWD=''");
   bool isOk = db.open();
   if(isOk)
   {
       return true;
   }
   else
   {
       return false;
   }
}

