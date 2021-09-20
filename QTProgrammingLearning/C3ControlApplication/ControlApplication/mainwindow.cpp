#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

 //1.1 QpusButton 按钮

//    button = new QPushButton("按钮A", this);
//    button->setGeometry(QRect(100,100,100,25));
//    connect(button, SIGNAL(released()), this, SLOT(txtButton()));

//1.2 QLabel标签
//    label = new QLabel("我是Qlabel", this);
//    label->setGeometry(QRect(100,100,200,30));
//    label->setStyleSheet("font-size:30px;color:blue;font-weight:bold;font-style:italic");


//1.3 QLineEdit单行文本
//    lineEdit = new QLineEdit(this);
//    lineEdit->setGeometry(QRect(100,100,200,25));
//    lineEdit->setStyleSheet("border:1px;border-style:solid;color:red;border-color: blue red;");
//    lineEdit->setMaxLength(6);
//    lineEdit->setEchoMode(QLineEdit::Password);

//1.4 QTextEdit多行文本
//    QTextEdit e1(this);
//    e1.setGeometry(QRect(50,50,200,150));
//    e1.setText("我是第一行<br/>我是第二行");

//    textEdit = new QTextEdit(this);
//    textEdit->setGeometry(QRect(50,50,200,150));
//    textEdit->setText("我是第一行<br/>我是第二行");


//1.5 QPlainTextEdit多行文本
//    planTextEdit = new QPlainTextEdit(this);
//    planTextEdit->setGeometry(QRect(50,50,200,100));
//    planTextEdit->setPlainText("第一行");


//1.6 QComboBox下拉列表框
//    comboBox = new QComboBox(this);
//    comboBox->setGeometry(QRect(50,50,120,25));
//    QStringList str;
//    str << "数学" << "语文" << "地理";
//    comboBox->addItems(str);


//1.7 QFontComboBox字体下拉列表框
//    fontComboBox = new QFontComboBox(this);
//    button = new QPushButton(this);
//    label = new QLabel(this);
//    label->setGeometry(QRect(50,150,300,25));
//    button->setText("按钮");
//    button->move(180,50);
//    connect(button, SIGNAL(released()),this, SLOT(txtButton()));
//    fontComboBox->setGeometry(QRect(50,50,120,25));


//1.8 QSpinBox控件
//    spinBox = new QSpinBox(this);
//    spinBox->setGeometry(QRect(50,50,100,25));
//    spinBox->setRange(0,200);
//    spinBox->setValue(10);
//    spinBox->setSuffix("元");
//    spinBox->setPrefix("$");


//1.9 QTimeEdit控件
//    timeEdit = new QTimeEdit(this);
//    timeEdit->setGeometry(QRect(50,50,120,50));
//    QDateTime sysTime = QDateTime::currentDateTime();
//    QStringList list = sysTime.toString("hh:mm:ss").split(':');
//    timeEdit->setTime(QTime(list[0].toInt(), list[1].toInt(), list[2].toInt()));


//1.10 QDateEdit日期控件
//    dateEdit = new QDateEdit(this);
//    dateEdit->setGeometry(QRect(50,50,120,25));
//    QDateTime sysTime = QDateTime::currentDateTime();
//    QStringList list = sysTime.toString("yyyy-MM-dd").split('-');
//    dateEdit->setDate(QDate(list[0].toInt(), list[1].toInt(), list[2].toInt()));

//1.11 QScrollBar控件(分数条进度)
//    scrollBar =new QScrollBar(this);
//    spinBox = new QSpinBox(this);
//    scrollBar->setOrientation(Qt::Horizontal);
//    scrollBar->setGeometry(QRect(50,50,180,20));
//    spinBox->setGeometry(QRect(50,90,100,25));
//    scrollBar->setPageStep(10);
//    connect(scrollBar, SIGNAL(valueChanged(int)),spinBox, SLOT(setValue(int)));
//    connect(spinBox, SIGNAL(valueChanged(int)), scrollBar, SLOT(setValue(int)));
//    //scrollBar->setValue(50);
//    spinBox->setValue(10);

//1.12 QRadioButton单选按钮(男女选择按钮)
//    radioM = new QRadioButton(this);
//    radioW = new QRadioButton(this);
//    label = new QLabel(this);
//    radioM->setGeometry(QRect(50,50,50,50));
//    radioW->setGeometry(QRect(100,50,50,50));
//    label->setGeometry(QRect(50,100,100,20));
//    radioM->setText("男");
//    radioW->setText("女");
//    radioM->setChecked(true);
//    label->setText("男");
//    connect(radioM, SIGNAL(clicked()), this, SLOT(radioChange()));
//    connect(radioW, SIGNAL(clicked()), this, SLOT(radioChange()));


//1.13 QCheckBox复选框
//    checkBox01 = new QCheckBox(this);
//    checkBox02 = new QCheckBox(this);
//    checkBox03 = new QCheckBox(this);

//    label = new QLabel(this);

//    checkBox01->setGeometry(QRect(50,50,50,50));
//    checkBox02->setGeometry(QRect(100,50,50,50));
//    checkBox03->setGeometry(QRect(150,50,50,50));
//    label->setGeometry(QRect(50,100,200,30));

//    checkBox01->setText("数学");
//    checkBox02->setText("语文");
//    checkBox03->setText("地理");

//    this->connect(checkBox01, SIGNAL(clicked(bool)), this, SLOT(checkChange()));
//    connect(checkBox02, SIGNAL(clicked(bool)), this, SLOT(checkChange()));
//    connect(checkBox03, SIGNAL(clicked(bool)), this, SLOT(checkChange()));


//1.14 QListView列表控件
//listView = new QListView(this);
//listView->setGeometry(QRect(50,50,100,100));
//QStringList string;
//string << "数学" << "语文" << "外语" << "地理";
//model = new QStringListModel(string);
//listView->setModel(model);


//1.15 QTreeView树控件(类似于目录)
//    treeView = new QTreeView(this);
//    treeView->setGeometry(QRect(50,50,150,200));
//    itemModel = new QStandardItemModel(3,2);
//    itemModel->setHeaderData(0, Qt::Horizontal, "第一列");
//    itemModel->setHeaderData(1, Qt::Horizontal, "第二列");

//    QStandardItem *item1 = new QStandardItem("数学");
//    item1->setIcon(QIcon(":/new/prefix1/qt"));

//    QStandardItem *item2 = new QStandardItem("语文");
//    item2->setIcon(QIcon(":/new/prefix1/qt"));

//    QStandardItem *item3 = new QStandardItem("外语");
//    item3->setIcon(QIcon(":/new/prefix1/qt"));

//    QStandardItem *item4 = new QStandardItem("外语A");
//    item4->setIcon(QIcon(":/new/prefix1/qt"));
//    item3->appendRow(item4);

//    itemModel->setItem(0,0,item1);
//    itemModel->setItem(1,0,item2);
//    itemModel->setItem(2,0,item3);

//    treeView->setModel(itemModel);


//1.16 QTableView表格控件(表格并且分行)
//    tableView = new QTableView(this);
//    tableView->setGeometry(QRect(50,50,310,200));
//    itemModel = new QStandardItemModel();

//    itemModel->setHorizontalHeaderItem(0,new QStandardItem("数学"));
//    itemModel->setHorizontalHeaderItem(1,new QStandardItem("语文"));
//    itemModel->setHorizontalHeaderItem(2,new QStandardItem("外语"));

//    itemModel->setItem(0,0,new QStandardItem("数学 A"));
//    itemModel->setItem(0,1,new QStandardItem("语文 A"));
//    itemModel->setItem(0,2,new QStandardItem("外语 A"));
//    itemModel->setItem(1,0,new QStandardItem("数学 B"));
//    itemModel->setItem(1,1,new QStandardItem("语文 B"));
//    itemModel->setItem(1,2,new QStandardItem("外语 B"));

//    tableView->setModel(itemModel);

//1.17 QHBoxLayout横向布局(横向排列三个按钮)
//    hboxLayout = new QHBoxLayout();
//    button1 = new QPushButton("按钮1");
//    button2 = new QPushButton("按钮2");
//    button3 = new QPushButton("按钮3");

//    hboxLayout->addWidget(button1);
//    hboxLayout->addWidget(button2);
//    hboxLayout->addWidget(button3);

//    hboxLayout->setSpacing(60);

//    widget = new QWidget();

//    widget->setLayout(hboxLayout);

//    this->setCentralWidget(widget);


//1.18 QGridLayout网格布局(按键按表格排列)
//    gridLayout = new QGridLayout();
//    button1 = new QPushButton("按钮1");
//    button2 = new QPushButton("按钮2");
//    button3 = new QPushButton("按钮3");

//    gridLayout->addWidget(button1,0,0,1,1);
//    gridLayout->addWidget(button2,0,1,1,1);
//    gridLayout->addWidget(button3,1,0,1,1);

//    widget = new QWidget();

//    widget->setLayout(gridLayout);
//    this->setCentralWidget(widget);


//1.19 QGroupBox控件(在一个格子中加入一个按钮)
//    box = new QGroupBox(this);
//    box->setGeometry(QRect(30,30,340,100));
//    box->setTitle("语音栏目");

//    button = new QPushButton();
//    button->setText("按钮");

//    vbox = new QVBoxLayout;
//    vbox->addWidget(button);

//    box->setLayout(vbox);


//1.20 QTabWidget控件()
//tabWidget = new QTabWidget(this);
//tabWidget->setGeometry(QRect(30,30,340,140));
//tabWidget->addTab(new tabA, "A栏目");
//tabWidget->addTab(new tabB, "B栏目");


//1.21 QMenu, QToolBar控件(菜单栏的创建)
//    fileMenu = new QMenu(this);
//    editMenu = new QMenu(this);
//    helpMenu = new QMenu(this);

//    newAct = new QAction(QIcon( ":/images/new/prefix1/qt" ), tr( "新建" ), this );
//    newAct->setShortcut(tr("Ctrl+N" ));
//    newAct->setStatusTip(tr("新建文件" ));
//    connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));

//    cutAct = new QAction(QIcon( ":/images/new/prefix1/qt" ), tr( "剪切" ), this );
//    cutAct->setShortcut(tr("Ctrl+X" ));
//    cutAct->setStatusTip(tr("剪切内容" ));

//    copyAct = new QAction(QIcon( ":/images/new/prefix1/qt" ), tr( "复制" ), this );
//    copyAct->setShortcut(tr("Ctrl+C" ));
//    copyAct->setStatusTip(tr("复制内容" ));

//    pasteAct = new QAction(QIcon( ":/images/new/prefix1/qt" ), tr( "粘贴" ), this );
//    pasteAct->setShortcut(tr("Ctrl+V" ));
//    pasteAct->setStatusTip(tr("粘贴内容" ));

//    aboutQtAct = new QAction(tr( "关于 Qt" ), this );
//    aboutQtAct->setStatusTip(tr("关于 Qt 信息" ));
//    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

//    //填充菜单
//    fileMenu = menuBar()->addMenu(tr( "文件" ));
//    fileMenu->addAction(newAct);
//    fileMenu->addSeparator();

//    editMenu = menuBar()->addMenu(tr("编辑" ));
//    editMenu->addAction(cutAct);
//    editMenu->addAction(copyAct);
//    editMenu->addAction(pasteAct);
//    menuBar()->addSeparator();


//    helpMenu = menuBar()->addMenu(tr("帮助" ));
//    helpMenu->addAction(aboutQtAct);


//    //toolBar 工具条
//    fileToolBar = addToolBar(tr("新建"));
//    fileToolBar->addAction(newAct);

//    editToolBar = addToolBar(tr("修改"));
//    editToolBar->addAction(cutAct);
//    editToolBar->addAction(copyAct);



//1.22 任务栏托盘菜单()
    createMenu();
    if(!QSystemTrayIcon::isSystemTrayAvailable())
    {
    return;
    }

    //实例QSystemTrayIcon
    myTrayIcon = new QSystemTrayIcon(this);
    //设置图标
    myTrayIcon->setIcon(QIcon(":/new/prefix1/qt"));
    //鼠标放托盘图标上提示信息
    myTrayIcon->setToolTip("Qt托盘图标功能");
    //设置消息
    myTrayIcon->showMessage("托盘","托盘管理",QSystemTrayIcon::Information,10000);
    //托盘菜单
    myTrayIcon->setContextMenu(myMenu);
    //显示
    myTrayIcon->show();



}

MainWindow::~MainWindow()
{
    delete ui;
    delete button;
    delete label;
    delete lineEdit;
    delete textEdit;
    delete planTextEdit;
    delete comboBox;
    delete fontComboBox;
    delete spinBox;
    delete timeEdit;
    delete dateEdit;
    delete scrollBar;
    delete radioM;
    delete radioW;
    delete checkBox01;
    delete checkBox02;
    delete checkBox03;
    delete listView;
    delete model;
    delete treeView;
    delete itemModel;
    delete tableView;
    delete hboxLayout;
    delete button1;
    delete button2;
    delete button3;
    delete widget;
    delete gridLayout;
    delete box;
    delete vbox;
    delete tabWidget;


}


void MainWindow::txtButton()
{
//    button->setText("按钮B");

//1.7
    label->setText("选择字体: "+fontComboBox->currentText());
}

void MainWindow::radioChange()
{
    if(sender() == radioM)
    {
        label->setText("男");
    }
    else if(sender()==radioW)
    {
        label->setText("女");
    }
}


//QString str;

void MainWindow::checkChange()
{
    if(sender()==checkBox01)
    {
        if(checkBox01->checkState() == Qt::Checked)
        {
            str+="数学";
        } else
        {
            str = str.replace(QString("数学"), QString(""));
        }
    } else if(sender()==checkBox02)
    {
        if(checkBox02->checkState() == Qt::Checked)
        {
            str+="语文";
        } else
        {
            str = str.replace(QString("语文"), QString(""));
        }

    } else if(sender()==checkBox03)
    {
        if(checkBox03->checkState() == Qt::Checked)
        {
            str+="地理";
        } else
        {
            str = str.replace(QString("地理"), QString(""));
        }
    }
    label->setText(str);
}

tabA::tabA(QWidget *parent):QWidget(parent)
{
    QPushButton *buttonA = new QPushButton(this);
    buttonA->setText("页面A");
}

tabB::tabB(QWidget *parent):QWidget(parent)
{
    QPushButton *buttonB = new QPushButton(this);
    buttonB->setText("页面B");
}


void MainWindow::newFile(){
QMessageBox::warning(this,tr("Warning"),
tr("创建新文件？"),
QMessageBox::Yes | QMessageBox::Default,
QMessageBox::No);
}

//绘制菜单
void MainWindow::createMenu()
{
restoreWinAction = new QAction("恢复(&R)",this);
quitAction = new QAction("退出(&Q)",this);
//恢复
connect(restoreWinAction,SIGNAL(triggered()),this,SLOT(showNormal()));
//退出
connect(quitAction,SIGNAL(triggered()),qApp,SLOT(quit()));
myMenu = new QMenu((QWidget*)QApplication::desktop());
//添加菜单
myMenu->addAction(restoreWinAction);
//分隔符
myMenu->addSeparator();
myMenu->addAction(quitAction);
}
//恢复
void MainWindow::showNormal()
{
this->show();
}


void QWidget:: changeEvent (QEvent *e)
{
if((e->type()==QEvent::WindowStateChange)&&this->isMinimized())
{
//QTimer::singleShot(100, this, SLOT(hide()));
this->hide();
}
}

