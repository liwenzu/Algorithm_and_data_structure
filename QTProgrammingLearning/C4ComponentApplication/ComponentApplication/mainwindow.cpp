#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


//日历组件
//    label = new QLabel(this);
//    label->setText("选择日期: ");
//    label->setGeometry(QRect(50, 50, 100, 25));
//    lineEdit = new QLineEdit(this);
//    lineEdit->setGeometry(QRect(110, 50, 150, 22));

//    connect(lineEdit, SIGNAL(cursorPositionChanged(int,int)), this, SLOT(showTime()));
//    calendarWidget = new QCalendarWidget(this);

//    calendarWidget->setGeometry(20,75,350,180);
//    calendarWidget->setHidden(true);
//    connect(calendarWidget, SIGNAL(clicked(QDate)), this, SLOT(setData()));


//登录窗口
//    setMinimumSize(280, 150);
//    setMaximumSize(280, 150);
//    usrLabel = new QLabel(tr("用户名: "));
//    pwdLabel = new QLabel(tr("密 码: "));

//    usrLineEdit = new QLineEdit;

//    pwdLineEdit = new QLineEdit;

//    pwdLineEdit->setEchoMode(QLineEdit::Password);

//    usrLineEdit->setMaxLength(6);
//    pwdLineEdit->setMaxLength(6);

//    gridlayout = new QGridLayout;

//    gridlayout->addWidget(usrLabel, 0, 0, 1, 1);
//    gridlayout->addWidget(usrLineEdit, 0, 1, 1, 1);


//    gridlayout->setSpacing(20);

//    gridlayout->addWidget(pwdLabel, 1, 0, 1, 1);
//    gridlayout->addWidget(pwdLineEdit, 1, 1, 1, 1);


//    okBtn = new QPushButton(tr("确定"));
//    cancelBtn = new QPushButton(tr("取消"));

//    connect(okBtn, SIGNAL(clicked(bool)), this, SLOT(accept()));

//    connect(cancelBtn, SIGNAL(clicked(bool)), this, SLOT(reject()));


//    QHBoxLayout *hboxLayout = new QHBoxLayout;

//    hboxLayout->setSpacing(60);

//    hboxLayout->addWidget(okBtn);
//    hboxLayout->addWidget(cancelBtn);


//    vboxLayout = new QVBoxLayout;
//    vboxLayout->addLayout(gridlayout);
//    vboxLayout->addLayout(hboxLayout);


//    this->setLayout(vboxLayout);


//1.3文件浏览对话框
//    filename = new QLineEdit(this);
//    filename->setGeometry(QRect(50,50,230,25));

//    button = new QPushButton(this);

//    button->setGeometry(QRect(280,50,80,25));

//    button->setText("浏览");
//    connect(button, SIGNAL(clicked()), this, SLOT(showFiles()));

//1.4颜色选择对话框
//      button = new QPushButton(this);

//      button->setGeometry(QRect(200, 50, 80, 25));

//      button->setText("选择颜色");

//      connect(button, SIGNAL(clicked()), this, SLOT(editText()));

//      label = new QLabel(this);

//      label->setGeometry(QRect(50, 50, 100, 25));

//      label->setText("我的颜色可以改变");

//1.5 进度条实例
//    bar =new QProgressBar(this);
//    bar->setGeometry(QRect(50, 50, 200, 20));

//    bar->setRange(0, 100000-1);
//    bar->setValue(1);

//    button = new QPushButton(this);
//    button->setGeometry(QRect(270, 50, 80, 25));
//    button->setText("开始");
//    connect(button, SIGNAL(clicked()), this, SLOT(startBar()));


//1.6 Timer 实时更新时间
label = new QLabel(this);
label->setGeometry(50,50,200,25);
timer = new QTimer;

connect(timer, SIGNAL(timeout()), this, SLOT(timerTime()));
timer->start(1000);



}

MainWindow::~MainWindow()
{
    delete ui;
    delete label;
    delete lineEdit;
    delete calendarWidget;
}



void MainWindow::showTime()
{
    calendarWidget->setHidden(false);

}

void MainWindow::setData()
{
    QDate date = calendarWidget->selectedDate();

    QString str = date.toString("yyyy-MM-dd");

    lineEdit->setText(str);
    calendarWidget->setHidden(true);
}

void MainWindow::accept()
{

}

void MainWindow::showFiles()
{
    QString str = QFileDialog::getOpenFileName(this,"open file","/","text file(*.txt);;C file(*.cpp);;All file(*.*)");
    filename->setText(str.toUtf8());
}

void MainWindow::editText()
{
    QColorDialog::setCustomColor(0, QRgb(0x0000FF));
    QColor color = QColorDialog::getColor(QColor(0, 255, 0));
    QPalette p = palette();
    p.setColor(QPalette::WindowText, QColor(color));
    label->setPalette(p);
}


void MainWindow::startBar()
{
    for(int i=0;i<100000;i+=2)
    {
        if(i==99999)
        {
            button->setText("结束");
        }
        bar->setValue(i);
    }
}

void MainWindow::timerTime()
{
    QDateTime sysTime = QDateTime::currentDateTime();
    label->setText(sysTime.toString());
}




















