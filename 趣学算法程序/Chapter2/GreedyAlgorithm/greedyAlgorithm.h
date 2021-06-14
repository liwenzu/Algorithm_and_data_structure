#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

//加勒比海盗装载问题
int GreedyAlgorithm(vector<int> &arr, int w)
{
    int ans = 0, sum_w = 0;
    sort(arr.begin(), arr.end());
    int n = arr.size();
    for(int i=0;i<n;i++)
    {
        sum_w+=arr[i];
        if(sum_w <= w)
            ans++;
        else
            break;
    }
//    for(int i=0;i<arr.size(); i++)
//        cout << arr[i] << ";";
//    cout << endl;
    return ans;
}

//Alibaba
    struct three{
        double w;
        double v;
        double p;
    };

bool cmp(const three &a, const three &b)
{
    return a.p > b.p;
}

double Alibaba(vector<three> &arr, int sum_w)
{
    sort(arr.begin(), arr.end(), cmp);
    double price=0;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i].w < sum_w)
        {
            price+=arr[i].v;
            sum_w-=arr[i].w;
        }
        else
        {
            price+=sum_w*arr[i].p;
            break;
        }
    }
//    for(int i=0;i<arr.size(); i++)
//    {
//        cout << arr[i].w << ":" << arr[i].v << ":" << arr[i].p << endl;
//    }
    return price;
}

//会议测试
class setMeet{

private:
    struct Meet{
        int beg;
        int end;
        int num;
    };
    int arrcp[10][2] = {{3, 6}, {1, 4}, {5, 7}, {2, 5}, {5, 9}, {3, 8}, {8, 11}, {6, 10}, {8, 12}, {12, 14}};

public:
    setMeet(int nu = 10)
    {
        cout << "Constructor" << endl;
        n = nu;
        init();
    }

    ~setMeet()
    {
        cout << "Destructor" << endl;
    }

    void solve()
    {
        sort(arr.begin(), arr.end(), cmpClass);
        int last = arr[0].end;
        ans = 1;
        cout << "Conference number:" << arr[0].num << endl;
        for(int i=1;i<n;i++)
        {
            if(arr[i].beg>=last)
            {
                last = arr[i].end;
                ans++;
                cout << "Conference number:" << arr[i].num << endl;
            }
        }
        cout << "Maximum number of meetings:" << ans << endl;
    }

    void print() const
    {
        for(int i=0;i<arr.size();i++)
            cout << arr[i].num << "|" << arr[i].beg << "|" << arr[i].end << endl;
    }

private:

    void init()
    {
        for(int i=0;i<n;i++)
        {
            Meet m1;
            m1.beg = arrcp[i][0];
            m1.end = arrcp[i][1];
            m1.num = i+1;
            arr.push_back(m1);
        }
    }

    static bool cmpClass(const Meet &m1, const Meet &m2)
    {
        if (m1.end == m2.end)
            return m1.beg > m2.beg;
        return m1.end < m2.end;
    }

private:
    int ans = 0;
    int n;
    vector<Meet> arr;
};

//最短路径求法
class Dijkstra{
public:
    enum {SPARE_CAPACITY = 100};
    const int INF = 1e7;

private:
    struct Node{
        Node() {};
        Node(int a, int sp)
        {
            st = a;
            step = sp;
        }
        int st;
        int step;
        bool operator < (const Node &a) const
        {
            return step > a.step;
        }
    };

public:
    Dijkstra()
    {
        cout << "构造函数" << endl;
    }

    ~Dijkstra()
    {
        cout << "析构函数" << endl;
    }

    void init()
    {
        int s,e,w;
        map.resize(SPARE_CAPACITY);
        for(int i=0;i<map.size();i++)
            map[i].resize(SPARE_CAPACITY);
        dist.resize(SPARE_CAPACITY);
        p.resize(SPARE_CAPACITY);
        flag.resize(SPARE_CAPACITY);

        system("color 0d");
        cout << "Please enter the number of cities" << endl;
        cin >> n;
        cout << "Please enter the number of lines between cities" << endl;
        cin >> m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                map[i][j]=INF;
        while(m--)
        {
            cin >> s >> e >> w;
            map[s][e]=min(map[s][e],w);
        }
        cout << "Please enter your location" << endl;
        cin >> u;
    }

    void minimumPath()
    {
        for(int i=1;i<=n;i++)
        {
            dist[i] = map[u][i];
            flag[i] = false;
            if(dist[i]==INF)
                p[i] = -1;
            else
                p[i] = u;
        }
        dist[u] = 0;
        flag[u] = true;
        for(int i=1;i<=n;i++)
        {
            int tmp = INF, t = u;
            for(int j=1;j<=n;j++)
            {
                if(!flag[j] && dist[j]<tmp)
                {
                    tmp = dist[j];
                    t = j;
                }
            }
            if(t==u)
                return;
            flag[t] = true;
            for(int j=1;j<=n;j++)
            {
                if(!flag[j] && map[t][j]<INF)
                {
                    if(map[t][j]+dist[t]<dist[j])
                    {
                        dist[j] = map[t][j]+dist[t];
                        p[j] = t;
                    }
                }
            }
        }
    }

    void minimumPathPQ()
    {
        priority_queue<Node> Q;
        Q.push(Node(u, 0));
        for(int i=1;i<=n;i++)
        {
            flag[i] = false;
            dist[i] = INF;
        }
        dist[u] = 0;
        while(!Q.empty())
        {
            Node it = Q.top();
            Q.pop();
            int t = it.st;
            if(flag[t])
                continue;
            flag[t] = true;
            for(int i=1;i<=n;i++)
            {
                if(!flag[i] && map[t][i]<INF)
                {
                    if(dist[i]>map[t][i]+dist[t])
                    {
                        dist[i] = map[t][i]+dist[t];
                        Q.push(Node(i, dist[i]));
                    }
                }
            }
        }
    }

    void print()
    {
//        for(int i=1;i<=n;i++)
//        {
//            for(int j=1;j<=n;j++)
//                cout << map[i][j] << ";";
//            cout << endl;
//        }
        for(int i=1;i<=n;i++)
            cout << dist[i] << ";";
        cout << endl;

        for(int i=1;i<=n;i++)
            cout << p[i] << ";";
        cout << endl;
    }

    void printMP()
    {
        cout << "Bob's location is:" << u << endl;
        for(int i=1;i<=n;i++)
        {
            cout << "Bob:" << u << "-" << "Arrived location:" << i << " ";
            if(dist[i] == INF)
                cout << "Sorry there is no way" << endl;
            else
                cout << "The shortest path is:" << dist[i] << endl;
        }
    }

    void printCity()
    {
        int x;
        stack<int> s;
        cout << "The source point is" << u << endl;
        for(int i=1;i<=n;i++)
        {
            x = p[i];
            while(x!=-1)
            {
                s.push(x);
                x = p[x];
            }

            cout << "The path from the source point to the other points is: ";
            while(!s.empty())
            {
                cout << s.top() << "---";
                s.pop();
            }
            cout << i << ";The shortest path is:" << dist[i] << endl;
        }
    }

private:
    vector<vector<int> > map;
    vector<int> dist;
    vector<int> p;
    vector<bool> flag;
    int n;
    int m;
    int u;
};

//Huffman coding
class HuffmanCoding {
    enum{MAXBIT = 100, MAXVALUE = 10000, MAXLEAF = 30, MAXNODE = MAXLEAF*2 - 1};

private:
    struct HNodeType {
        HNodeType()
        {
            weight = 0;
            parent = -1;
            lchild = -1;
            rchild = -1;
        }
        double weight;
        int parent;
        int lchild;
        int rchild;
        string value;
    };

    struct HCodeType {
        HCodeType()
        {
            bit.resize(MAXBIT);
            start = 0;
        }
        vector<int> bit;
        int start;
    };

public:
    HuffmanCoding()
    {
        cout << "Constructor" << endl;
        HuffNode.resize(MAXNODE);
        HuffCode.resize(MAXLEAF);
    }

    ~HuffmanCoding()
    {
        cout << "Destructor" << endl;
    }

    void HuffmanTree()
    {
        cout << "Please input n: " << endl;
        cin >> n;

        int x1,x2;
        double m1,m2;
        for(int i=0;i<2*n-1;i++)
        {
            HuffNode[i].weight = 0;
            HuffNode[i].lchild = -1;
            HuffNode[i].rchild = -1;
            HuffNode[i].parent = -1;
        }
        for(int i=0;i<n;i++)
        {
            cout << "Please input value and weight of leaf node" << i+1 << endl;
            cin >> HuffNode[i].value >> HuffNode[i].weight;
        }
        for(int i=0;i<n-1;i++)
        {
            m1 = m2 = MAXVALUE;
            x1 = x2 = 0;
            for(int j=0;j<n+i;j++)
            {
                if(HuffNode[j].parent == -1 && HuffNode[j].weight < m1)
                {
                    m2 = m1;
                    x2 = x1;
                    m1 = HuffNode[j].weight;
                    x1 = j;
                }
                else if(HuffNode[j].weight < m2 && HuffNode[j].parent == -1)
                {
                    m2 = HuffNode[j].weight;
                    x2 = j;
                }
            }
            HuffNode[n+i].weight = m1+m2;
            HuffNode[n+i].lchild = x1;
            HuffNode[n+i].rchild = x2;
            HuffNode[x1].parent = n+i;
            HuffNode[x2].parent = n+i;
        }
    }

    void HuffmanCode()
    {
        HCodeType cd;
        int c,p;
        for(int i=0;i<n;i++)
        {
            cd.start = n-1;
            p = HuffNode[i].parent;
            c = i;
            while(p!=-1)
            {
                if(HuffNode[p].lchild == c)
                    cd.bit[cd.start] = 0;
                else
                    cd.bit[cd.start] = 1;
                cd.start--;
                c = p;
                p = HuffNode[p].parent;
            }
            for(int j =cd.start+1;j<n;j++)
                HuffCode[i].bit[j] = cd.bit[j];
            HuffCode[i].start = cd.start;
        }
    }

    void print()
    {
        for(int i=0;i<2*n-1;i++)
        {
            cout << HuffNode[i].weight << " : " << HuffNode[i].parent << " : " << HuffNode[i].lchild << " : " << HuffNode[i].rchild << " : " << HuffNode[i].value << endl;
        }
        for(int i=0;i<n;i++)
        {
            cout << HuffNode[i].value << ": Huffman code is: ";
            for(int j=HuffCode[i].start+1;j<n;j++)
                cout << HuffCode[i].bit[j];
            cout << endl;
        }
    }

private:
    int n;
    vector<HNodeType> HuffNode;
    vector<HCodeType> HuffCode;
};

//最小生成树
class minSpaTree{
    enum{MAXNODE = 100, INF = 0x3fffffff};

public:
    minSpaTree()
    {
        cout << "Constructor" << endl;
        closest.resize(MAXNODE);
        lowcost.resize(MAXNODE);
        s.resize(MAXNODE);
        c.resize(MAXNODE);
        for (int i=0;i<c.size();i++)
            c[i].resize(MAXNODE);
    }

    ~minSpaTree()
    {
        cout << "Destructor" << endl;
    }

    void init()
    {
        cout << "Please enter the number of nodes (N) and edges (M)" << endl;
        cin >> n >> m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                c[i][j] = INF;
        cout << "Please enter the nodes u and v, and their weight w" << endl;
        int u,v,w;
        for(int i=1;i<=m;i++)
        {
            cin >> u >> v >> w;
            c[u][v] = c[v][u] = w;
        }
        cout << "Please enter the start node" << endl;
        cin >> u0;
    }

    void prim()
    {
        s[u0] = true;
        for(int i=1;i<=n;i++)
        {
            if(i!=u0)
            {
                closest[i] = u0;
                lowcost[i] = c[u0][i];
                s[i] = false;
            }
            else
                lowcost[u0] = 0;
        }
        for(int i=1;i<=n;i++)
        {
            int t=u0,temp=INF;
            for(int j=1;j<=n;j++)
            {
                if(!s[j] && lowcost[j]<temp)
                {
                    t=j;
                    temp=lowcost[j];
                }
            }
            if(t==u0)
                break;
            s[t] = true;
            for(int j=1;j<=n;j++)
            {
                if(!s[j] && c[t][j]<lowcost[j])
                {
                    lowcost[j] = c[t][j];
                    closest[j] = t;
                }
            }
        }
        int sumcost;
        for(int i=1;i<=n;i++)
        {
            cout << lowcost[i] << ";";
            sumcost+=lowcost[i];
        }
        cout << endl;
        cout << "Minimum cost is: " << sumcost << endl;
    }

    void print()
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                cout << c[i][j] << ";";
            cout << endl;
        }
        for(int i=1;i<=n;i++)
            cout << closest[i] << ";";
        cout << endl;
        for(int i=1;i<=n;i++)
            cout << lowcost[i] << ";";
        cout << endl;
    }

private:
    vector<int> closest;
    vector<int> lowcost;
    vector<bool> s;
    vector<vector<int> > c;
    int n;
    int m;
    int u0;
};





















