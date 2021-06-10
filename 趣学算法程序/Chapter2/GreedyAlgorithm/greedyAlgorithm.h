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




















