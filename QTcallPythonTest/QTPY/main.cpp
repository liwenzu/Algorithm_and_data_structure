#include "mainwindow.h"

#include <QApplication>

#include <QDebug>
#include <iostream>

#pragma push_macro("slots")
#undef slots
#include <Python.h>
#pragma pop_macro("slots")


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QString s = "--------------------";
    qDebug() << s;



    qDebug() << "==========start============";


    //初始化python模块
    Py_Initialize();
    if ( !Py_IsInitialized() )
    {
    return -1;
    }


    //导入print.py模块
    PyObject* pModule = PyImport_ImportModule("print");
    if (!pModule) {
        printf("Cant open python file!\n");
        return -1;
    }
        //获取test模块中的hello函数
    PyObject* pFunhello= PyObject_GetAttrString(pModule,"hello");
        //注释掉的这部分是另一种获得test模块中的hello函数的方法
    //    PyObject* pDict = PyModule_GetDict(pModule);
    //       if (!pDict) {
    //           printf("Cant find dictionary.\n");
    //           return -1;
    //       }
    //    PyObject* pFunhello = PyDict_GetItemString(pDict, "hello");

    if(!pFunhello){
        qDebug() <<"Get function hello failed";
        return -1;
    }
    //调用hello函数
    PyObject_CallFunction(pFunhello,NULL);
    //结束，释放python
    Py_Finalize();


    qDebug() << "*******************";







//    MainWindow w;
//    w.show();

    return a.exec();
}
