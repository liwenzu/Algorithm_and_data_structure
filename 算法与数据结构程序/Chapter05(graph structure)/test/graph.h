#pragma once
#include <iostream>
#include <cstring>
#include <queue>

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

    void GraphCreate()
    {
        cout << "����ͼ����" << endl;
        cout << "������ͼ���ܶ�����:" << endl;
        cin >> vexnum;
        cout << "������ͼ���ܱ���:" << endl;
        cin >> arcnum;
        cout << "������ͼ�еõ�ÿ������" << endl;
        for(int i=0;i<vexnum;i++)
              cin >> vexs[i];
        cout << "�����봴����������ͼ1����������ͼ2;" << endl;
        cin >> type;
        for (int i=0;i<vexnum;i++)
        {
            for(int j=0;j<vexnum;j++)
                arcs[i][j]=0;
        }
        for(int i=0;i<arcnum;i++)
        {
            char v1[6],v2[6];
            int w;
            cout << "��������ʼ����յ��Ѿ�Ȩ��" << endl;
            cin >>v1;
            cin >>v2;
            cin >>w;
            int it = LocateVex(v1);
            int jt = LocateVex(v2);
            if (type == 1)
                arcs[it][jt]=arcs[jt][it]=w;
            else if (type == 2)
                arcs[it][jt]=w;
        }
    }

    void DFS()
    {
        int v;
        for(int i=0;i<vexnum;i++)
           visited[i]=0;
        cout << "������������ȱ����Ŀ�ʼ����" << endl;
        cin >> v;
        DFS(v);
        cout << endl;
    }

    void BFS()
    {
        int v;
        for(int i=0;i<vexnum;i++)
            visited[i]=0;
        cout << "�����������ȱ����Ŀ�ʼ����" << endl;
        cin >> v;
        BFS(v);
        cout << endl;
    }

    int LocateVex(char *node)
    {
        for(int i=0;i<vexnum;i++)
        {
            if (strcmp(vexs[i], node) == 0)
                return i;
        }
        return -1;
    }

    void printVe()
    {
        cout << "��ӡ���㼯��" << endl;
        for(int i=0;i<vexnum;i++)
            cout << vexs[i] <<";";
        cout << endl;
        cout << "��ӡ�߼���" << endl;
        for (int i=0;i<vexnum;i++)
        {
            for (int j=0;j<vexnum;j++)
                cout << arcs[i][j] << ";";
            cout << endl;
        }
    }

private:
    void DFS(int v)
    {
        cout << vexs[v] << "=>";
        visited[v]=1;
        for (int i=0;i<vexnum;i++)
        {
            if((arcs[v][i]!=0)&&(!visited[i]))
                DFS(i);
        }
    }

    void BFS(int v)
    {
        cout << vexs[v] << "=>";
        visited[v]=1;
        queue<int> bq;
        bq.push(v);
        while(!bq.empty())
        {
            int de = bq.front();
            bq.pop();
            for(int i=0;i<vexnum;i++)
            {
                if (!visited[i] && arcs[de][i])
                {
                    cout << vexs[i] << "=>";
                    visited[i]=1;
                    bq.push(i);
                }
            }
        }

    }

private:
    char vexs[SPARE_CAPACITY][6];
    int arcs[SPARE_CAPACITY][SPARE_CAPACITY];
    int vexnum,arcnum;
    int type;
    int visited[SPARE_CAPACITY];
};
