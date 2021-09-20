#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//获取屏幕分辨率
//    QLabel *label = new QLabel(this);
//    label->setGeometry(QRect(50, 50, 200, 25));
//    QDesktopWidget *desk = QApplication::desktop();
//    QRect screenRect = desk->screenGeometry();
//    QString str = "屏幕分辨率位: ";
//    int sWidth = screenRect.width();
//    int sHeight = screenRect.height();
//    label->setText(str+QString::number(sWidth, 10)+"*"+QString::number(sHeight, 10));

//获取本机名。iP地址
//    QString localHostName = QHostInfo::localHostName();
//    qDebug() << "计算机名：" << localHostName;
//    //获取IP地址
//    QHostInfo info = QHostInfo::fromName(localHostName);
//    //遍历地址，只获取IPV4 地址
//    foreach(QHostAddress address,info.addresses())
//    {
//        if(address.protocol() == QAbstractSocket::IPv4Protocol)
//        {
//        qDebug() << "ipV4 地址：" << address.toString();
//        }
//    }

    //实例 QLabel
//    label = new QLabel(this);
//    label->setGeometry(QRect(50,50,200,25));
//    label->setText("按 Q键更改文字");

//获取系统环境变量
//    this->setWindowTitle("获取Path环境变量");
//    QListView *listView = new QListView(this);
//    listView->setGeometry(QRect(10, 10,  380, 280));

//    QStringList strList = QProcess::systemEnvironment();
//    QStringListModel *model = new QStringListModel(strList);
//    listView->setModel(model);

//执行系统命令

    comm = new QLineEdit(this);
    comm->setGeometry(QRect(20, 20, 260, 25));
    comm->setText("ipconfig");


    btClick = new QPushButton(this);
    btClick->setText("执行");
    btClick->setGeometry(QRect(290, 20, 80, 25));
    connect(btClick, SIGNAL(clicked()), this, SLOT(clickExecution()));

    outEdit = new QPlainTextEdit(this);
    outEdit->setGeometry(QRect(20, 60, 350, 200));

    process = new QProcess;
    connect(process, SIGNAL(readyRead()), this, SLOT(readOutput()));

    label = new QLabel(this);
    label->setGeometry(QRect(30, 265, 200, 25));
    label->setText(tr("<a  href=\"http://www.baidu.com/s?wd=dos 命令大全\">命令DOS查阅</a>"));
    label->setOpenExternalLinks(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow:: keyPressEvent (QKeyEvent *event)
//{
////键值如果等于Q
//if(event->key()==Qt::Key_Q)
//{
//label->setText("你按了 Q 键");
//}
//}


void MainWindow::clickExecution()
{
    QString info = comm->text();
    process->start(info);
//    outEdit->setPlainText(output);
}


void MainWindow::readOutput()
{
    output += process->readAll();
    outEdit->setPlainText(output);

}

























