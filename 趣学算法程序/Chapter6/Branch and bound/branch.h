#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;


class trackSP{

private:
    struct Goods{
        Goods(int v = 0, int w = 0)
        {
            value = v;
            weight = w;
        }
        int value;
        int weight;
    };

    struct Node{
        Node(int _cp, int _rp, int _rw, int _id, int _n=10)
        {
            x.resize(_n+1);
            cp = _cp;
            rp = _rp;
            rw = _rw;
            id = _id;
        }
        Node(int _n=10)
        {
            x.resize(_n+1);
        }
        int cp, rp;
        int rw;
        int id;
        vector<bool> x;
    };



public:
    trackSP(int i=0)
    {
        n = i;
        init();
        cout << "Constructor" << endl;
    }

    ~trackSP()
    {
        cout << "Destructor" << endl;
    }



private:

    void init()
    {
        cout << "Please enter the number of items n:" << endl;
        cin >> n;
        cout << "Please enter the shopping cart capacity W: " << endl;
        cin >> W;
        bestx.resize(n+1);
        goods.resize(n+1);
        cout << "Please enter the weight and value of each item in turn: ";
        for(int i=1;i<=n;i++)
        {
            cin >> goods[i].weight >> goods[i].value;
            sumw += goods[i].weight;
            sumv += goods[i].value;
        }
        if(sumw<=W)
        {
            bestp = sumv;
            cout << "The maximum value of items placed in the shopping cart is: " << bestp << endl;
            cout << "All items have been placed in the shopping cart" << endl;
            return;
        }
        bfs();
        cout << "The maximum value of the item is: " << bestp << endl;
        cout << "Put in the items have: ";
        for(int i=1;i<=n;i++)
            if(bestx[i]==1)
            cout << i << " ";
        cout << endl;
    }

    void bfs()
    {
        int t, tcp, trp, trw;
        queue<Node> q;
        q.push(Node(0, sumv, W, 1, n+1));
        while(!q.empty())
        {
            Node livenode, lchild, rchild;
            livenode = q.front();
            q.pop();
            t = livenode.id;
            if(t>n || livenode.rw==0)
            {
                if(livenode.cp>=bestp)
                {
                    bestp = livenode.cp;
                    bestx = livenode.x;
                }
                continue;
            }
            if(livenode.cp + livenode.rp<bestp)
                continue;
            tcp = livenode.cp;
            trp = livenode.rp - goods[t].value;
            trw = livenode.rw;
            if(trw>=goods[t].weight)
            {
                lchild.rw = trw - goods[t].weight;
                lchild.cp = tcp + goods[t].value;
                lchild = Node(lchild.cp, trp, lchild.rw, t+1, n+1);
                lchild.x = livenode.x;
                lchild.x[t] = true;
                if(lchild.cp>bestp)
                    bestp = lchild.cp;
                q.push(lchild);
            }
            if(tcp+trp>=bestp)
            {
                rchild = Node(tcp, trp, trw, t+1, n+1);
                rchild.x = livenode.x;
                rchild.x[t] = false;
                q.push(rchild);
            }
        }
    }



private:
    int n;
    vector<bool> bestx;
    int W = 0;
    int bestp = 0;
    int sumw = 0;
    int sumv = 0;
    vector<Goods> goods;
};


class trackTR{

private:
    struct Node{
        Node()
        {

        }

        Node(double _cl, int _id, int _n)
        {
            cl = _cl;
            id = _id;
            x.resize(_n+1);
        }

        bool operator<(const Node &b) const
        {
            return cl > b.cl;
        }

        double cl;
        int id;
        vector<int> x;
    };

public:
    trackTR(int i=0)
    {
        n = i;
        cout << "Constructor" << endl;
        init();
    }

    ~trackTR()
    {
        cout << "Destructor" << endl;
    }

private:
    void init()
    {
        cout << "Please enter the number of attractions n: " << endl;
        cin >> n;
        bestx.resize(n+1);
        g.resize(n+1);
        for(int i=0;i<g.size();i++)
            g[i].resize(n+1, INT_MAX);
        cout << "Please enter the number of connections between attractions: " << endl;
        cin >> m;
        cout << "Please enter the distance between the two attractions: " << endl;
        int u,v,w;
        for(int i=1;i<=m;i++)
        {
            cin >> u >> v >> w;
            g[u][v] = g[v][u] = w;
        }
        BFS();
        cout << "The shortest path is: " ;
        for(int i=1;i<=n;i++)
            cout << bestx[i] << "--->";
        cout << "1" << endl;
        cout << "The shortest path length is: " << bestl << endl;
    }

    void BFS()
    {
        int t;
        Node livenode, newnode;
        priority_queue<Node> q;
        newnode = Node(0, 2, n+1);
        for(int i=0;i<=n;i++)
            newnode.x[i] = i;
        q.push(newnode);
        while(!q.empty())
        {
            livenode = q.top();
            q.pop();
            t = livenode.id;
            if(t==n)
            {
                if(g[livenode.x[n-1]][livenode.x[n]]!=INT_MAX && g[livenode.x[n]][1]!=INT_MAX)
                {
                    if(livenode.cl+g[livenode.x[n-1]][livenode.x[n]] + g[livenode.x[n]][1]<bestl)
                    {
                        bestl = livenode.cl+g[livenode.x[n-1]][livenode.x[n]] + g[livenode.x[n]][1];
                        bestx = livenode.x;
                    }
                }
                continue;
            }
            if(livenode.cl>=bestl)
                continue;
            for(int i=t;i<=n;i++)
            {
                double cl = livenode.cl + g[livenode.x[t-1]][livenode.x[i]];
                if(cl<bestl)
                {
                    newnode = Node(cl, t+1, n+1);
                    newnode.x = livenode.x;
                    swap(newnode.x[t], newnode.x[i]);
                    q.push(newnode);
                }
            }
        }
    }

private:
    int n;
    vector<int> bestx;
    double bestl = INT_MAX;
    int m;
    vector<vector<double> > g;
};

class trackPA {

private:

    struct Position{
        int x;
        int y;
    };

public:
    trackPA()
    {
        init();
        cout << "Constructor" << endl;
    }

    ~trackPA()
    {
        cout << "Destructor" << endl;
    }

    void print()
    {
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
                cout << setw(2) << grid[i][j] << "  ";
            cout << endl;
        }
    }

private:
    void init()
    {
        cout << "Please enter the size of the square matrix m, n: " << endl;
        cin >> m >> n;
        grid.resize(m+2);
        for(int i=0;i<grid.size();i++)
        {
            if(i==0 || i==m+1)
                grid[i].resize(n+2, -2);
            else
                grid[i].resize(n+2, -1);
        }
        for(int i=0;i<grid.size();i++)
            grid[i][0] = grid[i][n+1] = -2;
        while(!(m==0&&n==0))
        {
            cout << "Please enter the coordinates of the obstacle x, y (0, 0 end)" << endl;
            cin >> m >> n;
            grid[m][n] = -2;
        }
        cout << "Please enter the starting point coordinates: " << endl;
        cin >> a.x >> a.y;
        cout << "Please enter the end point coordinates: " << endl;
        cin >> b.x >> b.y;
        if(findpath())
        {
            cout << "The shortest path length is: " << Len << endl;
            cout << "The best path coordinates are: " << endl;
            for(int i=0;i<Len;i++)
                cout << setw(2) << way[i].x << setw(2) << way[i].y << endl;
        }
        else
            cout << "Unable to complete the task" << endl;
    }

    bool findpath()
    {
        Position s = a, e = b;
        if(s.x == e.x && s.y == e.y)
        {
            Len = 0;
            return true;
        }
        vector<Position> DIR(4);
        Position here, next;
        DIR[0].x = 0;
        DIR[0].y = 1;
        DIR[1].x = 1;
        DIR[1].y = 0;
        DIR[2].x = 0;
        DIR[2].y = -1;
        DIR[3].x = -1;
        DIR[3].y = 0;
        here = s;
        grid[here.x][here.y] = 0;
        queue<Position> Q;
        while(true)
        {
            for(int i=0;i<4;i++)
            {
                next.x = here.x + DIR[i].x;
                next.y = here.y + DIR[i].y;
                if(grid[next.x][next.y]==-1)
                {
                    grid[next.x][next.y] = grid[here.x][here.y]+1;
                    Q.push(next);
                }
                if(next.x == e.x && next.y == e.y)
                    break;
            }
            if(next.x == e.x && next.y == e.y)
                break;
            if(Q.empty())
                return false;
            else
            {
                here = Q.front();
                Q.pop();
            }
        }
        Len = grid[e.x][e.y];
        way.resize(Len);
        here = e;
        for(int i=Len-1;i>=0;i--)
        {
            way[i] = here;
            for(int j=0;j<4;j++)
            {
                next.x = here.x + DIR[j].x;
                next.y = here.y + DIR[j].y;
                if(grid[next.x][next.y] == i)
                    break;
            }
            here = next;
        }
        return true;
    }

private:
    vector<vector<int> > grid;
    Position a, b;
    int Len, m, n;
    vector<Position> way;
};


























