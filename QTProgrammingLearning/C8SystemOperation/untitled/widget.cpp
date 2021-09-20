#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //获取计算机名称
//    QString localHostName = QHostInfo::localHostName();
//    qDebug() << "计算机名：" << localHostName;
//    //获取IP地址
//    QHostInfo info = QHostInfo::fromName(localHostName);
//    //遍历地址，只获取IPV4 地址
//    foreach(QHostAddress address,info.addresses())
//    {
//    if(address.protocol() == QAbstractSocket::IPv4Protocol)
//    {
//    qDebug() << "ipV4 地址：" << address.toString();
//    }
//    }

//根据网址获取IP地址
//    label = new QLabel(this);
//    label->setGeometry(QRect(50, 50, 40, 25));
//    label->setText("网址： ");

//    edit = new QLineEdit(this);
//    edit->setGeometry(QRect(100, 50, 150, 25));
//    edit->setText("www.google.com");

//    button = new QPushButton(this);
//    button->setGeometry(QRect(260, 50, 80, 25));
//    button->setText("查询");

//    connect(button, SIGNAL(clicked()), this, SLOT(sendUrl()));

//    result = new QLabel(this);
//    result->setGeometry(QRect(50, 90, 150, 25));


//判断键盘按下键值
    label = new QLabel(this);
    label->setGeometry(QRect(50, 50, 200, 25));
    label->setText("按Q键更改文字");


}

Widget::~Widget()
{
    delete ui;
}

void Widget::sendUrl()
{
    QHostInfo::lookupHost(edit->text(), this, SLOT(lookedUp(QHostInfo)));
}

void Widget::lookedUp(const QHostInfo &host)
{
    result->setText("IP地址： "+host.addresses().first().toString());
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Q)
        label->setText("你按了Q键");
}

