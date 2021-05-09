#pragma once
#include <iostream>
#include <cstring>
#include <queue>

#define nullptr NULL

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


class GraphLink{
    enum {SPARE_CAPACITY = 100};
private:

    struct ArcNode{
        ArcNode(int ad=int(), int w=0, ArcNode *p=nullptr)
        {
            adjvex=ad;
            nextarc=p;
            info=w;
        }
        int adjvex;
        ArcNode *nextarc;
        int info;
    };

    struct VNode{
        VNode(string str=string(), ArcNode *p = nullptr)
        {
            data = str;
            firstarc = p;
        }
        string data;
        ArcNode *firstarc;
    };

public:
    GraphLink()
    {
        cout << "�����ʾ��ͼ�ṹ�Ĺ��캯��" << endl;
    }

    ~GraphLink()
    {
        cout << "������������" << endl;
        for (int i=0;i<vexnum;i++)
        {
            ArcNode *p = vertices[i].firstarc;
            while(p)
            {
                ArcNode *old = p->nextarc;
                delete p;
                p = old;
            }
        }
    }

    void GraphCreate()
    {
        cout << "������ͼ���ܶ�����:" << endl;
        cin >> vexnum;
        cout << "������ͼ���ܱ���:" << endl;
        cin >> arcnum;
        cout << "������ͼ�е�ÿ������" << endl;
        for (int i=0;i<vexnum;i++)
            cin >> vertices[i].data;
        cout << "������ͼ������1.����ͼ;2.����ͼ" << endl;
        cin >> type;
        for (int i=0;i<arcnum;i++)
        {
            string str1,str2;
            int w;
            cout << "��������ʼ����յ��Լ�Ȩ��" << endl;
            cin >>str1;
            cin >>str2;
            cin >>w;
            int it = LocateVex(str1);
            int jt = LocateVex(str2);

            if (type == 2)
            {
                ArcNode *p1 = new ArcNode(jt, w, vertices[it].firstarc);
                vertices[it].firstarc = p1;
            } else if(type==1)
            {
                ArcNode *p1 = new ArcNode(jt, w, vertices[it].firstarc);
                vertices[it].firstarc = p1;
                ArcNode *p2 = new ArcNode(it, w, vertices[jt].firstarc);
                vertices[jt].firstarc = p2;
            }
        }
    }

    int LocateVex(string str)
    {
        for (int i=0;i<vexnum;i++)
        {
            if (str == vertices[i].data)
                return i;
        }
        return -1;
    }


    void printVe()
    {
        cout << "��ӡ���㼯��" << endl;
        for(int i=0;i<vexnum;i++)
            cout << vertices[i].data <<";";
        cout << endl;
        cout << "��ӡ�߼���" << endl;
        for (int i=0;i<vexnum;i++)
        {
            cout << vertices[i].data <<"=>";
            ArcNode *p = vertices[i].firstarc;
            while(p!=nullptr)
            {
                cout << vertices[p->adjvex].data <<"=>";
                p = p->nextarc;
            }
            cout << endl;
        }
    }

    void DFS()
    {
        int v;
        for (int i=0;i<vexnum;i++)
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

private:
    void DFS(int v)
    {
        cout << vertices[v].data << "=>";
        visited[v]=1;
        ArcNode *p = vertices[v].firstarc;
        while(p)
        {
            if (!visited[p->adjvex])
                DFS(p->adjvex);
            p = p->nextarc;
        }
    }

    void BFS(int v)
    {
        cout << vertices[v].data << "=>";
        visited[v]=1;
        queue<int> bq;
        bq.push(v);
        while(!bq.empty())
        {
            int de = bq.front();
            bq.pop();
            ArcNode *p = vertices[de].firstarc;
            while(p)
            {
                if(!visited[p->adjvex])
                {
                    cout << vertices[p->adjvex].data << "=>";
                    bq.push(p->adjvex);
                    visited[p->adjvex] = 1;
                }
                p = p->nextarc;
            }
        }
    }

private:
    VNode vertices[SPARE_CAPACITY];
    int vexnum,arcnum;
    int type;
    int visited[SPARE_CAPACITY];
};
