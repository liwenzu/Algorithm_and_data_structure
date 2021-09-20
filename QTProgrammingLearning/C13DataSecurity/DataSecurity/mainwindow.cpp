#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //1.1 QByteArray加密数据
//    this->setWindowTitle("QByteArray加密");

//    label = new QLabel(this);
//    label->setGeometry(QRect(30, 50, 100, 25));
//    label->setText("加密内容");

//    edit = new QLineEdit(this);
//    edit->setGeometry(QRect(90, 50, 290, 25));
//    edit->setText("你好");

//    pEdit = new QPlainTextEdit(this);
//    pEdit->setGeometry(QRect(30, 80, 350, 150));

//    btJ = new QPushButton(this);
//    btJ->setGeometry(QRect(80, 240, 80, 25));
//    btJ->setText("加密");
//    connect(btJ, SIGNAL(clicked(bool)), this, SLOT(encFun()));

//    btU = new QPushButton(this);
//    btU->setGeometry(QRect(220, 240, 80, 25));
//    btU->setText("解密");
//    connect(btU, SIGNAL(clicked(bool)), this, SLOT(jieFun()));


    //1.2 AES加密数据
//    this->setWindowTitle("AES加密");

//    label = new QLabel(this);
//    label->setGeometry(QRect(40, 40, 200, 25));
//    label->setText("调试中查看结果");

//    btJ = new QPushButton(this);
//    btJ->setGeometry(QRect(80, 80, 80, 25));
//    btJ->setText("加密");
//    connect(btJ, SIGNAL(clicked(bool)), this, SLOT(encFun()));

    //1.3 MD5加密数据
//    label = new QLabel(this);
//    label->setGeometry(QRect(50, 50, 200, 25));
//    QString pwd = "李文祖";
//    QString MD5;
//    QByteArray ba, bb;
//    QCryptographicHash md(QCryptographicHash::Md5);
//    ba.append(pwd);
//    md.addData(ba);
//    bb = md.result();
//    MD5.append(bb.toHex());
//    label->setText(MD5);


    //1.4 生成随机数
    QTime time = QTime::currentTime();
    qsrand(time.msec()+time.second()*1000);
    int xNum = qrand()%1000;

    QLabel *label = new QLabel(this);
    label->setGeometry(QRect(50,50,200,25));
    label->setText("随机数："+QString::number(xNum));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::encFun()
{
    aes = new TAesClass;
    char mingwen[1024] = "李文祖";
    DWORD size = strlen(mingwen);
    char miwen[1024];
    char jiemi[1024];
    UCHAR key[1024] = "pwd";
    UCHAR *p = key;
    aes->InitializePrivateKey(16, p);
    aes->OnAesEncrypt((LPVOID)mingwen, size, (LPVOID)miwen);
    aes->OnAesUncrypt((LPVOID)miwen, (DWORD)sizeof(miwen),(LPVOID)jiemi);

    //调试输出信息
    qDebug() << "明文:" << mingwen;
    qDebug() << "密文:" << miwen;
    qDebug() << "解密:" <<jiemi;
    //释放TAesClass
    free(aes);
    //清0
    aes = 0;
}

void MainWindow::jieFun()
{
    pEdit->setPlainText("解密");
}
