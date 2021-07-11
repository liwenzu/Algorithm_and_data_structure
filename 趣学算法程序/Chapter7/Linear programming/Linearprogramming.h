#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class linProPR{

public:
    linProPR();

    ~linProPR();

private:
    void init();

    void print();

    void DCXA();


private:
    int n;
    int m;
    vector<vector<float> > kernel;
    vector<char> FJL;
    vector<char> JL;
};


class trackNT
{
public:

    trackNT();

    ~trackNT();

private:
    void init();

    int EK(int s, int t);

    void print();

    bool bfs(int s, int t);



private:
    vector<vector<int> > g, f;
    vector<int> pre;
    vector<bool> vis;
    int n;
    int m;
};


class trackCS
{

private:

    struct Vertex
    {
        int first;
    };

    struct Edge
    {
        int v, next;
        int cap, flow, cost;
    };

public:

    trackCS()
    {
        init();
        cout << "Constructor" << endl;
    }

    ~trackCS()
    {
        cout << "Destructor" << endl;
    }

private:

    void init()
    {
        cout << "Please enter the number of nodes and edges: " << endl;
        cin >> n >> m;
        V.resize(100);
        for(int i=0;i<V.size();i++)
            V[i].first = -1;
        E.resize(10000);
        dist.resize(100);
        pre.resize(100);
        c.resize(100);
        vis.resize(100);
        cout << "Please enter the capacity and cost of the two nodes: " << endl;
        int u, v, w, c;
        for(int i=1;i<=m;i++)
        {
            cin >> u >> v >> w >> c;
            add(u,v,w,c);
        }
        cout << endl;
        printg( );
        cout << "The minimum cost of the network is: " << MCMF(1,n) << endl;
        cout << "The maximum flow value of the network: " << maxflow << endl;
        cout << endl;
        printg();
        printflow();
    }

    void add(int u, int v, int c, int cost)
    {
        add_edge(u,v,c,cost);
        add_edge(v,u,0,-cost);
    }

    void add_edge(int u, int v, int c, int cost)
    {
        E[top].v = v;
        E[top].cap = c;
        E[top].flow = 0;
        E[top].cost = cost;
        E[top].next = V[u].first;
        V[u].first = top++;
    }

    void printg()
    {
        cout << "--------------network table--------------" << endl;
        for(int i=1;i<=n;i++)
        {
            cout << "v" << i << " [" << V[i].first;
            for(int j=V[i].first;~j;j=E[j].next)
                cout << "]--[" << E[j].v << "  " << E[j].cap << "  " << E[j].flow << "  " << E[j].cost << "  " << E[j].next;
            cout << "]" << endl;
        }
    }

    int MCMF(int s, int t)
    {
        int d;
        int i, mincost;
        mincost = 0;
        while(SPFA(s,t))
        {
            d = INT_MAX;
            cout << endl;
            cout << "Augmentation path: " << t;
            for(i=pre[t];i!=-1;i=pre[E[i^1].v])
            {
                d = min(d, E[i].cap - E[i].flow);
                cout << "--" << E[i^1].v;
            }
            cout << "Increase flow: " << d << endl;
            cout << endl;
            maxflow+=d;
            for(int i=pre[t];i!=-1;i=pre[E[i^1].v])
            {
                E[i].flow+=d;
                E[i^1].flow-=d;
            }
            mincost+=dist[t]*d;
        }
        return mincost;
    }

    bool SPFA(int s, int t)
    {
        int i, u ,v;
        queue<int> qu;
        for(i=0;i<vis.size();i++)
            vis[i] = false;
        for(i =0;i<c.size();i++)
            c[i] = 0;
        for(i=0;i<pre.size();i++)
            pre[i] = -1;
        for(i=0;i<dist.size();i++)
            dist[i] = INT_MAX;
        vis[s] = true;
        c[s]++;
        dist[s]=0;
        qu.push(s);
        while(!qu.empty())
        {
            u = qu.front();
            qu.pop();
            vis[u] = false;
            for(i=V[u].first;i!=-1;i=E[i].next)
            {
                v=E[i].v;
                if(E[i].cap>E[i].flow && dist[v]>dist[u]+E[i].cost)
                {
                    dist[v] = dist[u]+E[i].cost;
                    pre[v] = i;
                    if(!vis[v])
                    {
                        c[v]++;
                        qu.push(v);
                        vis[v]=true;
                        if(c[v]>n)
                            return false;
                    }
                }
            }
        }
        cout << "Shortest path array" << endl;
        cout << "dist[ ]=";
        for(int i=1;i<=n;i++)
            cout << "  " << dist[i];
        cout << endl;
        if(dist[t] == INT_MAX)
            return false;
        return true;
    }

    void printflow()
    {
        cout << "----------table-----------" << endl;
        for(int i=1;i<=n;i++)
        {
            for(int j=V[i].first;~j;j=E[j].next)
            {
                if(E[j].flow>0)
                {
                    cout << "v" << i << "--" <<"v" << E[j].v << " " << E[j].flow << " " << E[j].cost;
                    cout << endl;
                }
            }
        }
    }

private:
    int top = 0;
    vector<int> dist, pre, c;
    vector<bool> vis;
    int maxflow = 0;
    vector<Vertex> V;
    vector<Edge> E;
    int n, m;
};


class trackBL{
    enum {N = 100, M = 10000};

private:
    struct Vertex
    {
        int first;
    };

    struct Edge
    {
        int v, next;
        int cap, flow;
    };

public:
    trackBL()
    {
        init();
        cout << "Constructor" << endl;
    }

    ~trackBL()
    {
        cout << "Destructor" << endl;
    }


private:
    void init()
    {
        cout << "please input m and n: " << endl;
        cin >> m >> n;
        flag.resize(N*N);
        dfsflag.resize(N*N);
        V.resize(N);
        for(int i=0;i<V.size();i++)
            V[i].first = -1;
        h.resize(N);
        pre.resize(N);
        g.resize(N);
        E.resize(M);
        map.resize(N);
        for(int i=0;i<map.size();i++)
            map[i].resize(N);
        total = m*n;
        cout << "Please enter the value of each item in turn: " << endl;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin >> map[i][j];
                sum+=map[i][j];
            }
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if((i+j)%2==0)
                {
                    add(0, (i-1)*n+j, map[i][j]);
                    flag[(i-1)*n+j]=1;
                    for(int k=0;k<4;k++)
                    {
                        int x = i+dir[k][0];
                        int y = j+dir[k][1];
                        if(x<=m&&x>0&&y<=n&&y>0)
                            add((i-1)*n+j,(x-1)*n+y,INT_MAX);
                    }
                }
                else
                    add((i-1)*n+j, total+1, map[i][j]);
            }
        }
        cout << endl;
//        printg(total+2);
        cout << "The maximum value of the selected item is: " << sum-Isap(0, total+1, total+2) <<endl;
        cout << endl;
        print();
    }

    void add(int u, int v, int c)
    {
        add_edge(u,v,c);
        add_edge(v,u,0);
    }

    void add_edge(int u, int v, int c)
    {
        E[top].v = v;
        E[top].cap = c;
        E[top].flow = 0;
        E[top].next = V[u].first;
        V[u].first = top++;
    }

    void printg(int _n)
    {
        cout << "-------------table--------------" << endl;
        for(int i=0;i<=_n;i++)
        {
            cout <<"v"<<i<<"  [" << V[i].first;
            for(int j=V[i].first;~j;j=E[j].next)
                cout <<"]---["<<E[j].v<<"  "<<E[j].cap<<"  "<<E[j].flow<<"  "<< E[j].next;
            cout << "]" << endl;
        }
    }

    int Isap(int s, int t, int _n)
    {
        set_h(t,_n);
        int ans=0,u=s;
        int d;
        while(h[s]<_n)
        {
            int i=V[u].first;
            if(u==s)
                d=INT_MAX;
            for(;~i;i=E[i].next)
            {
                int v=E[i].v;
                if(E[i].cap>E[i].flow && h[u]==h[v]+1)
                {
                    u=v;
                    pre[v]=i;
                    d=min(d,E[i].cap-E[i].flow);
                    if(u==t)
                    {
                        cout << endl;
                        cout << "path: " << t;
                        while(u!=s)
                        {
                            int j=pre[u];
                            E[j].flow+=d;
                            E[j^1].flow-=d;
                            u=E[j^1].v;
                            cout <<"--"<<u;
                        }
                        cout <<"increase flow" <<d<<endl;
                        ans+=d;
                        d=INT_MAX;
                    }
                    break;
                }
            }
            if(i==-1)
            {
                if(--g[h[u]]==0)
                    break;
                int hmin=n-1;
                for(int j=V[u].first;~j;j=E[j].next)
                    if(E[j].cap>E[j].flow)
                        hmin=min(hmin,h[E[j].v]);
                h[u]=hmin+1;
                cout << "after" << endl;
                cout <<"h[ ]=";
                for(int i=1;i<=n;i++)
                    cout << "  "<<h[i];
                cout << endl;
                ++g[h[u]];
                if(u!=s)
                    u=E[pre[u]^1].v;
            }
        }
        return ans;
    }

    void set_h(int t, int _n)
    {
        queue<int> Q;
        for(int i=0;i<h.size();i++)
            h[i] = -1;
        for(int i=0;i<g.size();i++)
            g[i] = 0;
        h[t] = 0;
        Q.push(t);
        while(!Q.empty())
        {
            int v = Q.front();
            Q.pop();
            ++g[h[v]];
            for(int i=V[v].first;~i;i=E[i].next)
            {
                int u = E[i].v;
                if(h[u]==-1)
                {
                    h[u]=h[v]+1;
                    Q.push(u);
                }
            }
        }
        cout << "初始化高度" << endl;
        cout <<"h[ ]=";
        for(int i=1;i<=_n;i++)
            cout << " " << h[i];
        cout << endl;
    }

    void print()
    {
        cout << "--------fanan---------" << endl;
        cout << "number: " << endl;
        DFS(0);
        for(int i=1;i<=m*n;i++)
        {
            if((flag[i]&&dfsflag[i])||(!flag[i]&&!dfsflag[i]))
                cout <<i<<"  ";
        }
    }
    void DFS(int s)
    {
        for(int i=V[s].first;~i;i=E[i].next)
        {
            if(E[i].cap>E[i].flow)
            {
                int u = E[i].v;
                if(!dfsflag[u])
                {
                    dfsflag[u]=true;
                    DFS(u);
                }
            }
        }
    }

private:
    int top = 0;
    vector<int> h, pre, g;
    vector<bool> flag, dfsflag;
    vector<vector<int> > map;
    int n, m, total, sum=0;
    vector<Vertex> V;
    vector<Edge> E;
    int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
};


class trackTO{

    enum{M=150, N=10000};

private:

    struct Vertex{
        int first;
    };

    struct Edge{
        int v, next;
        int cap, flow,cost;
    };

public:

    trackTO()
    {
        init();
        cout << "Constructor" << endl;
    }

    ~trackTO()
    {
        cout << "Destructor" << endl;
    }

private:

    void init()
    {
        cout << "please input n and m: " << endl;
        cin >> n >> m;
        V.resize(N);
        for(int i=0;i<V.size();i++)
            V[i].first = -1;
        dist.resize(N);
        pre.resize(N);
        vis.resize(N);
        c.resize(N);
        E.resize(M);
        maze.clear();
        string str1, str2;
        cout << "please input the name str: " << endl;
        for(int i=1;i<=n;i++)
        {
            cin >> str[i];
            maze[str[i]] = i;
            if(i==1||i==n)
                add(i,i+n,2,0);
            else
                add(i,i+n,1,0);
        }
        cout << "input str1, str2: " << endl;
        for(int i=1;i<=m;i++)
        {
            cin >> str1 >> str2;
            int a=maze[str1], b=maze[str2];
            if(a<b)
            {
                if(a==1&&b==n)
                    add(a+n,b,2,-1);
                else
                    add(a+n,b,1,-1);
            }
            else
            {
                if(b==1&&a==n)
                    add(b+n,a,2,-1);
                else
                    add(b+n,a,1,-1);
            }
        }
        if(MCMF(1,2*n,2*n)==2)
        {
            cout << "Number of scenic spots passed: " << -mincost << endl;
            cout << "Scenic spots passing by: " << endl;
            cout << str[1] << endl;
            for(int i=0;i<vis.size();i++)
                vis[i]=0;
            print(1);
            cout << str[1] << endl;
        }
        else
            cout << "No Solution!" << endl;
    }

    void add(int u, int v, int c, int cost)
    {
        add_edge(u,v,c,cost);
        add_edge(v,u,0,-cost);
    }

    void add_edge(int u, int v, int c, int cost)
    {
        E[top].v = v;
        E[top].cap = c;
        E[top].flow = 0;
        E[top].next = V[u].first;
        V[u].first = top++;
    }

    int MCMF(int s, int t, int m_n)
    {
        int d;
        maxflow = mincost = 0;
        while(SPFA(s,t,m_n))
        {
            d=INT_MAX;
            cout << endl;
            cout << "increase path: " << t;
            for(int i=pre[t];i!=-1;i=pre[E[i^1].v])
            {
                d=min(d, E[i].cap-E[i].flow);
                cout <<"--"<<E[i^1].v;
            }
            cout <<"increase flow: " << d<< endl;
            cout << endl;
            for(int i=pre[t];i!=-1;i=pre[E[i^1].v])
            {
                E[i].flow+=d;
                E[i^1].flow-=d;
            }
            maxflow+=d;
            mincost+=dist[t]*d;
        }
        return maxflow;
    }

    bool SPFA(int s, int t, int m_n)
    {
        int i,u,v;
        queue <int> qu;
        for(i=0;i<vis.size();i++)
        {
            vis[i]=0;
            c[i] = 0;
            pre[i] = -1;
        }
        for(i=1;i<=m_n;i++)
            dist[i] = INT_MAX;
        vis[s] = true;
        c[s]++;
        dist[s]=0;
        qu.push(s);
        while(!qu.empty())
        {
            u=qu.front();
            qu.pop();
            vis[u]=false;
            for(i=V[u].first;i!=-1;i=E[i].next)
            {
                v=E[i].v;
                if(E[i].cap>E[i].flow && dist[v]>dist[u]+E[i].cost)
                {
                    dist[v]=dist[u]+E[i].cost;
                    pre[v]=i;
                    if(!vis[v])
                    {
                        c[v]++;
                        qu.push(v);
                        vis[v]=true;
                        if(c[v]>m_n)
                            return false;
                    }
                }
            }
        }
        cout << "Shortest path array: " << endl;
        cout << "dist[ ]=";
        for(int i=1;i<=n;i++)
            cout << "  "<< dist[i];
        cout << endl;
        if(dist[t]==INT_MAX)
            return false;
        return true;
    }

    void print(int s)
    {
        int v;
        vis[s]=1;
        for(int i=V[s].first;~i;i=E[i].next)
        {
            if(!vis[v=E[i].v]&&((E[i].flow>0&&E[i].cost<=0)||(E[i].flow<0&&E[i].cost>=0)))
            {
                print(v);
                if(v<=n)
                    cout << str[v]<<endl;
            }
        }
    }

private:
    int top = 0;
    vector<int> dist, pre, c;
    vector<bool> vis;
    string str[M];
    map<string, int> maze;
    vector<Vertex> V;
    vector<Edge> E;
    int maxflow,mincost;
    int n, m;
};
