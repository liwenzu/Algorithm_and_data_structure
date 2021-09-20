#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QMessageBox>
#include <QFile>

#include <QFileDialog>
#include <QTextStream>
#include <QTextCodec>
#include <QDebug>
#include <QFile>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

////1.1创建文件夹
//edit = new QLineEdit(this);
//edit->setGeometry(QRect(50,50,200,25));

//edit->setText("D://1234Folder");
//button = new QPushButton(this);
//button->setGeometry(QRect(280,50,80,25));
//button->setText("按钮");
//connect(button, SIGNAL(clicked()), this, SLOT(createFolder()));


//1.2写入文件
//    edit = new QLineEdit(this);
//    edit->setGeometry(QRect(50, 50, 200, 25));

//    edit->setText("D://1234.txt");

//    content = new QLineEdit(this);
//    content->setGeometry(QRect(50,100,200,25));
//    content->setText("写入文件的内容");

//    button = new QPushButton(this);
//    button->setGeometry(QRect(270, 50, 80, 25));
//    button->setText("创建");

//    connect(button, SIGNAL(clicked()), this, SLOT(createFile()));


//1.3修改文件内容
//    edit = new QTextEdit(this);
//    edit->setGeometry(QRect(50,50,240,26));

//    browseBt = new QPushButton(this);
//    browseBt->setGeometry(QRect(290,50,80,25));
//    browseBt->setText("浏览文件");
//    connect(browseBt, SIGNAL(clicked()), this, SLOT(browseFile()));

//    content = new QTextEdit(this);
//    content->setGeometry(QRect(50,80,320,150));

//    saveBt = new QPushButton(this);
//    saveBt->setGeometry(QRect(290,240,80,25));
//    saveBt->setText("保存");
//    connect(saveBt, SIGNAL(clicked()), this, SLOT(saveFile()));


//1.4删除文件
//    filePath = new QLineEdit(this);
//    filePath->setGeometry(QRect(50,50,200,25));
//    browseBt = new QPushButton(this);
//    browseBt->setText("浏览文件");
//    browseBt->setGeometry(QRect(270,50,80,25));
//    connect(browseBt, SIGNAL(released()), this, SLOT(browseFile()));

//    deleteBt = new QPushButton(this);
//    deleteBt->setGeometry(QRect(50,100,80,25));
//    deleteBt->setText("删除文件");
//    connect(deleteBt, SIGNAL(released()), this, SLOT(deleteFile()));

//1.5修改文件名
//    filePath = new QLineEdit(this);
//    filePath->setGeometry(QRect(50,50,200,25));

//    browseBt = new QPushButton(this);
//    browseBt->setGeometry(QRect(270, 50, 80, 25));
//    browseBt->setText("浏览");
//    connect(browseBt, SIGNAL(clicked()), this, SLOT(browseFile()));

//    newName = new QLineEdit(this);
//    newName->setGeometry(QRect(50, 90, 200, 25));
//    newName->setText("新名字.txt");

//    saveBt = new QPushButton(this);
//    saveBt->setGeometry(QRect(270, 90, 80, 25));
//    saveBt->setText("保存");
//    connect(saveBt, SIGNAL(clicked()), this, SLOT(saveFile()));


//1.6INI文件写入操作
//    filePathL = new QLabel;
//    filePath->setText("ini文件完整路径");

//    filePath = new QLineEdit;
//    filePath->setText("D:/a001.ini");


//    nodeL = new QLabel;
//    nodeL->setText("节点名");


//    nodeEdit = new QLineEdit;
//    nodeEdit->setText("node");

//    keyL = new QLabel;
//    keyL->setText("键值");

//    keyEdit = new QLineEdit;
//    keyEdit->setText("ip");


//    valL = new QLabel;
//    valL->setText("值");

//    valEdit = new QLineEdit;
//    valEdit->setText("192.168.1.1");
//    //按钮
//    writeBt = new QPushButton;
//    writeBt->setText("写入文件");
//    connect(writeBt,SIGNAL(clicked()),this,SLOT(writeFile()));
//    gLayout = new QGridLayout;

//    gLayout->addWidget(filePathL,0,0,1,1);
//    gLayout->addWidget(filePath,0,1,1,4);
//    gLayout->addWidget(nodeL,1,0,1,1);
//    gLayout->addWidget(nodeEdit,1,1,1,1);
//    gLayout->addWidget(keyL,2,0,1,1);
//    gLayout->addWidget(keyEdit,2,1,1,1);
//    gLayout->addWidget(valL,2,3,1,1);
//    gLayout->addWidget(valEdit,2,4,1,1);
//    gLayout->addWidget(writeBt,3,4,1,1);
//    //实例QWidget
//    widget = new QWidget();
//    //绑定布局
//    widget->setLayout(gLayout);
//    this->setCentralWidget(widget);



//1.7INI文件读取操作
//    filePathL = new QLabel;
//    filePathL->setText("ini 文件完整路径");

//    filePath = new QLineEdit;
//    filePath->setText("C:/Users/cetc/Desktop/a001.ini");

//    nodeL = new QLabel;
//    nodeL->setText("节点名");

//    nodeEdit = new QLineEdit;
//    nodeEdit->setText("node");

//    keyL = new QLabel;
//    keyL->setText("键值");
//    //键输入框
//    keyEdit = new QLineEdit;
//    keyEdit->setText("ip");

//    valL = new QLabel;
//    valL->setText("值");
//    //值输入框
//    valEdit = new QLineEdit;

//    //按钮
//    readBt = new QPushButton;
//    readBt->setText("读取文件");
//    connect(readBt,SIGNAL(clicked()),this,SLOT(readFile()));


//    gLayout = new QGridLayout;
//    gLayout->addWidget(filePathL,0,0,1,1);
//    gLayout->addWidget(filePath,0,1,1,4);
//    gLayout->addWidget(nodeL,1,0,1,1);
//    gLayout->addWidget(nodeEdit,1,1,1,1);
//    gLayout->addWidget(keyL,2,0,1,1);
//    gLayout->addWidget(keyEdit,2,1,1,1);
//    gLayout->addWidget(valL,2,3,1,1);
//    gLayout->addWidget(valEdit,2,4,1,1);
//    gLayout->addWidget(readBt,3,4,1,1);


//    widget = new QWidget();

//    widget->setLayout(gLayout);
//    this->setCentralWidget(widget);


//    1.8创建XML文件
//    explainL = new QLabel(this);
//    explainL->setText("这里就不重复写类似 txt读写的布局了，直接在代码中\r\n填写节点等操作。\r\n文件路径：D:/a001.xml\r\n 根节点：Root");
//    explainL->setGeometry(QRect(50, 50, 300, 100));

//    createBt = new QPushButton(this);
//    createBt->setText("创建XML文件");
//    createBt->setGeometry(QRect(50, 180, 300, 100));
//    connect(createBt, SIGNAL(clicked()), this, SLOT(createFile()));


//    1.9读取XML文件
    resultL = new QLabel(this);
    resultL->setGeometry(QRect(50, 50, 300, 100));

    readBt = new QPushButton(this);
    readBt->setText("读取title节点");
    readBt->setGeometry(QRect(50, 180, 150, 25));
    connect(readBt, SIGNAL(clicked()), this, SLOT(readNode()));








}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::createFolder()
//{
//    QDir *folder = new QDir;
//    bool exist = folder->exists(edit->text());
//    if(exist)
//    {
//        QMessageBox::warning(this,tr("创建文件夹"),tr("文件夹已经存在！"));
//    }
//    else
//    {
//        bool ok = folder->mkdir(edit->text());
//        if(ok)
//        {
//            QMessageBox::warning(this,tr("创建文件夹"),tr("文件夹创建成功！"));
//        }
//        else
//        {
//            QMessageBox::warning(this,tr("创建文件夹"),tr("文件夹创建失败！"));
//        }

//    }
//}



//void MainWindow::createFile()
//{
//    QFile file(edit->text());
//    if(file.exists())
//    {
//        QMessageBox::warning(this,"创建文件","文件已经存在！");
//    }
//    else
//    {
//        file.open(QIODevice::ReadWrite | QIODevice::Text);
//        QByteArray str = content->text().toUtf8();
//        file.write(str);
//        QMessageBox::warning(this,"创建文件","文件创建成功！");
//    }
//    file.close();
//}


//void MainWindow::browseFile()
//{
//    QString str = QFileDialog::getOpenFileName(this,"open file","/","text file(*.txt);;C file(*.cpp);;All file(*.*)");
//    edit->setText(str.toUtf8());

//    if(edit->toPlainText().isEmpty())
//    {
//        return;
//    }
//    QFile file(edit->toPlainText());
//    if(!file. open (QIODevice::ReadOnly|QIODevice::Text))
//    {
//    QMessageBox::warning(this,"打开文件","打开文件失败！");
//    return;
//    }
//    QTextStream ts(&file);
//    while(!ts.atEnd())
//    {
//    //将全部数据绑定至content 控件
//    content->setPlainText(ts.readAll());
//    }
//    //关闭文档
//    file. close ();

//}

//void MainWindow::saveFile()
//{
//    QFile file(edit->toPlainText());
//    file.open(QIODevice::ReadWrite | QIODevice::Text);
//    QByteArray str = content->toPlainText().toUtf8();
//    file.write(str);
//    QMessageBox::warning(this,"修改文件","文件修改成功！");
//    file. close ();
//}


//void MainWindow::browseFile()
//{
//    QString str = QFileDialog::getOpenFileName(this,"open file","/","text file(*.txt);;C file(*.cpp);;All file(*.*)");
//    filePath->setText(str.toUtf8());
//}

//void MainWindow::deleteFile()
//{

//    QFile::remove(filePath->text());
//}

//void MainWindow::browseFile()
//{
//    QString str = QFileDialog::getOpenFileName(this,"open file","/","text file(*.txt);;C file(*.cpp);;All file(*.*)");
//    filePath->setText(str.toUtf8());

//}

//void MainWindow::saveFile()
//{
//    QFileInfo file(filePath->text());
//    QString path = file.absolutePath();
//    bool x = QFile::rename(filePath->text(),path + "/" + newName->text());
//    if(x)
//    {
//        QMessageBox::warning(this,"修改文件名","文件修改成功！");
//    } else
//    {
//        QMessageBox::warning(this,"修改文件名","文件修改失败！");
//    }

//}


//void MainWindow::writeFile()
//{
//    writeIni = new QSettings(filePath->text(), QSettings::IniFormat);
//    //写入键、值
//    writeIni->setValue(nodeEdit->text()+"/"+keyEdit->text(),valEdit->text());
//    //写入完成删除指针
//    delete writeIni;
//}


//void MainWindow::readFile()
//{
//    readIni = new QSettings(filePath->text(), QSettings::IniFormat);
//    QString ipResult = readIni->value(nodeEdit->text()+"/"+keyEdit->text()).toString();
//    valEdit->setText(ipResult);
//    delete readIni;
//}


void MainWindow::createFile()
{
    QString xmlPath = "C:/Users/cetc/Desktop/a001.xml";
    QFile file(xmlPath);
    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QXmlStreamWriter stream(&file);
        stream.setAutoFormatting(true);

        stream.writeStartDocument();
        stream.writeStartElement("Root");

        stream.writeAttribute("href", "http://qt.nokia.com/");
        stream.writeTextElement("title", "Qt Home");
        stream.writeEndElement();
        stream.writeEndDocument();

        file.close();
    }
}


void MainWindow::readNode()
{
    QString xmlPath = "D:/Users/cetc/Desktop/a001.xml";
    QFile file(xmlPath);
    QString str;
    if(file.exists())
    {
    if(file. open (QIODevice::ReadOnly | QIODevice::Text))
    {
    //实例QXmlStreamReader对象读取文件
    QXmlStreamReader xmlRead(&file);
    //循环节点
    while (!xmlRead.atEnd())
    {
    //指针下移
    xmlRead.readNext();
    if(xmlRead.isStartElement())
    {
    //如果节点有等于 title 的
    if(xmlRead.name() == "title")
    {
    //取title 值赋予变量 str
    str = xmlRead.readElementText();
    }else
    {
    str = "没找到节点";
    }
    }
    }
    //将值绑定QLabel控件显示
    resultL->setText(str);
    }else
    {
    resultL->setText("文件打开失败");
    }
    //关闭文件
    file. close ();
    }else
    {
    resultL->setText("文件不存在");
    }


}













