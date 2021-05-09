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
        cout << "图的邻接矩阵创建" << endl;
        cout << "可以存储的图的最大顶点数为:" << SPARE_CAPACITY << endl;
    }

    ~GraphMatrix()
    {
        cout << "图的邻接矩阵删除" << endl;
    }

    void GraphCreate()
    {
        cout << "无向图创建" << endl;
        cout << "请输入图的总顶点数:" << endl;
        cin >> vexnum;
        cout << "请输入图的总边数:" << endl;
        cin >> arcnum;
        cout << "请输入图中得到每个顶点" << endl;
        for(int i=0;i<vexnum;i++)
              cin >> vexs[i];
        cout << "请输入创建的是无向图1，还是有向图2;" << endl;
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
            cout << "请输入起始点和终点已经权重" << endl;
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
        cout << "请输入深度优先遍历的开始顶点" << endl;
        cin >> v;
        DFS(v);
        cout << endl;
    }

    void BFS()
    {
        int v;
        for(int i=0;i<vexnum;i++)
            visited[i]=0;
        cout << "请输入广度优先遍历的开始顶点" << endl;
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
        cout << "打印顶点集合" << endl;
        for(int i=0;i<vexnum;i++)
            cout << vexs[i] <<";";
        cout << endl;
        cout << "打印边集合" << endl;
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
        cout << "链表表示的图结构的构造函数" << endl;
    }

    ~GraphLink()
    {
        cout << "析构函数调用" << endl;
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
        cout << "请输入图的总顶点数:" << endl;
        cin >> vexnum;
        cout << "请输入图的总边数:" << endl;
        cin >> arcnum;
        cout << "请输入图中的每个顶点" << endl;
        for (int i=0;i<vexnum;i++)
            cin >> vertices[i].data;
        cout << "请输入图的类型1.无向图;2.有向图" << endl;
        cin >> type;
        for (int i=0;i<arcnum;i++)
        {
            string str1,str2;
            int w;
            cout << "请输入起始点和终点以及权重" << endl;
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
        cout << "打印顶点集合" << endl;
        for(int i=0;i<vexnum;i++)
            cout << vertices[i].data <<";";
        cout << endl;
        cout << "打印边集合" << endl;
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
        cout << "请输入深度优先遍历的开始顶点" << endl;
        cin >> v;
        DFS(v);
        cout << endl;
    }

    void BFS()
    {
        int v;
        for(int i=0;i<vexnum;i++)
            visited[i]=0;
        cout << "请输入广度优先遍历的开始顶点" << endl;
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
