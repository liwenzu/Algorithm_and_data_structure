#pragma once
#include <iostream>
#include <string>

using namespace std;


class GraphMatrix {
    enum {SPARE_CAPACITY = 100};
public:
    GraphMatrix()
    {
        cout << "图的邻接矩阵创建" << endl;
        cout << "可以存储的图的最大顶点数为:" << SPARE_CAPACITY << endl;
    }

    ~GraphMatrix()
    {
        cout << "图的邻接矩阵删除" << endl;
    }

    void UDGraphCreate()
    {
        cout << "无向图创建" << endl;
        cout << "请输入图的总顶点数:" << endl;
        cin >> vexnum;
        cout << "请输入图的总边数:" << endl;
        cin >> arcnum;
        cout << "请输入图中得到每个顶点" << endl;
        for(int i=0;i<vexnum;i++)
              cin >> vexs[i];
    }

    void printVe()
    {
        for(int i=0;i<vexnum;i++)
            cout << vexs[i] <<";";
        cout << endl;
    }


private:
    char vexs[SPARE_CAPACITY][6];
    int arcs[SPARE_CAPACITY][SPARE_CAPACITY];
    int vexnum,arcnum;
};
