#pragma once
#include <iostream>
#include <string>

using namespace std;


class GraphMatrix {
    enum {SPARE_CAPACITY = 100};
public:
    GraphMatrix()
    {
        cout << "ͼ���ڽӾ��󴴽�" << endl;
        cout << "���Դ洢��ͼ����󶥵���Ϊ:" << SPARE_CAPACITY << endl;
    }

    ~GraphMatrix()
    {
        cout << "ͼ���ڽӾ���ɾ��" << endl;
    }

    void UDGraphCreate()
    {
        cout << "����ͼ����" << endl;
        cout << "������ͼ���ܶ�����:" << endl;
        cin >> vexnum;
        cout << "������ͼ���ܱ���:" << endl;
        cin >> arcnum;
        cout << "������ͼ�еõ�ÿ������" << endl;
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
