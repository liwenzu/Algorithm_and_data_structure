#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "windows.h" //1 顺序不可颠倒
#include "tlhelp32.h" //2
//#include <QPushButton>
#include <QMessageBox>
#include <QProcess>
#include <QThreadPool>
#include "runnable.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    1.1进程管理器
//    tableView = new QTableView(this);
//    tableView->setGeometry(QRect(10, 10, 340, 430));
//    QPushButton *button = new QPushButton(this);
//    button->setGeometry(QRect(260, 450, 80, 25));
//    button->setText("结束进程");
//    connect(button,SIGNAL(clicked()),this,SLOT(deletePro()));

//    model = new QStandardItemModel();
//    model->setHorizontalHeaderItem(0,new QStandardItem("进程名"));
//    model->setHorizontalHeaderItem(1,new QStandardItem("PID"));

//    HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
//    if (hProcessSnap == FALSE )
//    {
//        qDebug() << "调用失败";
//        return;
//    }
//    PROCESSENTRY32 pe32;
//    pe32.dwSize = sizeof(PROCESSENTRY32);
//    BOOL bRet = Process32First(hProcessSnap, &pe32);
//    int i = 0;
//    while ((bRet)) {
//        i++;
//        //前面2 行不要
//        if(i > 1)
//        {
//            //获取进程名
//            QString pName = QString::fromWCharArray(pe32.szExeFile);
//            //追加数据模型第一列
//            model->setItem(i-2,0,new QStandardItem(pName));
//            //获取PID 号
//            QString pid = QString::number(pe32.th32ProcessID);
//            //追加数据模型第二列
//            model->setItem(i-2,1,new QStandardItem(pid));
//        }
//        bRet = Process32Next(hProcessSnap, &pe32);
//    }
//    ::CloseHandle(hProcessSnap);

//    //绑定数据
//    tableView-> setModel (model);
//    //列宽
//    tableView->setColumnWidth(0,190);
//    tableView->setColumnWidth(1,130);
//    //选取整行
//    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
//    //不可修改
//    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
//    //行单击事件
//    connect(tableView,SIGNAL(clicked(QModelIndex)),SLOT(sendContent(QModelIndex)));
//    //纵向头隐藏
////    tableView->verticalHeader()->setVisible (false);
//    //关闭滚动条
//    //tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    //隔行变色
//    tableView->setAlternatingRowColors(true);


//1.2线程QThread应用
//    starThread = new QPushButton(this);
//    starThread->setGeometry(QRect(30, 50, 80, 25));
//    starThread->setText("执行线程1");
//    connect(starThread, SIGNAL(clicked()), this, SLOT(startFun()));


//1.3线程QRunnable应用
    progressBar = new QProgressBar(this);
    progressBar->setGeometry(QRect(50, 50, 200, 16));
    progressBar->setValue(0);
    progressBar->setRange(0, 100000-1);

    progressBar2 = new QProgressBar(this);
    progressBar2->setGeometry(QRect(50, 100, 200, 16));
    progressBar2->setRange(0, 100000-1);
    progressBar2->setValue(0);

    startButton = new QPushButton(this);
    startButton->setGeometry(QRect(260, 45, 80, 25));
    startButton->setText("执行");
    connect(startButton, SIGNAL(clicked()), this, SLOT(startFun()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::sendContent(QModelIndex)
{
    //获取点击行索引
    int index = tableView->currentIndex().row();
    //将PID 值赋予QString 类型保存
    cPid = model->data(model->index(index,1)).toString();
}

void MainWindow::deletePro()
{
    if(cPid == "")
    {
    QMessageBox::warning(this,"警告",tr("请选择要结束的进程!!!"));
    }else
    {
    //Taskkill/pid 3184
    //结束进程命令
    QProcess process(0);
    QString dos = "Taskkill";
    QStringList list;
    list.append("/pid");
    list.append(cPid);
    //拼接参数，因为QProcess 不支持中文与空格
    process.start(dos,list);
    QMessageBox::warning(this,"警告",tr("成功结束!!!"));
    }

}

//void MainWindow::startFun()
//{
//    thread = new QThread();
//    thread->start();
//    int i = 0;
//    while (true) {
//        thread->sleep(2);
//        i++;
//        qDebug() << i;
//        if(i>6)
//            break;
//    }
//    qDebug() << "结束";
//}


void MainWindow::startFun()
{
    runnable *hInst = new runnable(progressBar);
    hInst = new runnable(progressBar2);
    QThreadPool::globalInstance()->start(hInst);
}
