#pragma once
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class backTrackSp{

public:

    backTrackSp(int i=0)
    {
        n = i;
        cout << "Constructor" << endl;
    }

    ~backTrackSp()
    {
        cout << "Destructor" << endl;
    }

    void init()
    {
        cout << "Please enter the number of items n: " << endl;
        cin >> n;
        w.resize(n+1);
        v.resize(n+1);
        x.resize(n+1);
        bestx.resize(n+1);
        cout << "Please enter the shopping cart capacity W: " << endl;
        cin >> W;
        cout << "Please enter the weight w and value v of each item in turn: " << endl;
        for(int i=1;i<=n;i++)
            cin >> w[i] >> v[i];
        Knapsack();
    }

    void print()
    {
        for(int i=1;i<=n;i++)
            cout << "item:" << i << " " << w[i] << "  " << v[i] << endl;
    }

private:
    void Knapsack()
    {
       double sumw = 0;
       double sumv = 0;
       for(int i=1;i<=n;i++)
       {
           sumw+=w[i];
           sumv+=v[i];
       }
       if(sumw<=W)
       {
           bestp = sumv;
           cout << "The maximum value of items placed in the shopping cart is" << bestp << endl;
           cout << "All items are put into the shopping cart";
           return;
       }
       track(1);
       cout << "The maximum value of items placed in the shopping cart is" << bestp << endl;
       cout << "The serial number of the item put into the shopping cart is: ";
       for(int i=1;i<=n;i++)
       {
           if(bestx[i] == 1)
              cout << i << " ";
       }
       cout << endl;
    }

    void track(int t)
    {
        if(t>n)
        {
            bestx = x;
            bestp = cp;
            return;
        }
        if(cw + w[t] <= W)
        {
            x[t] = 1;
            cw+=w[t];
            cp+=v[t];
            track(t+1);
            cw-=w[t];
            cp-=v[t];
        }
        if(bound(t+1)>bestp)
        {
            x[t] = 0;
            track(t+1);
        }
    }

    double bound(int i)
    {
        double rp =0;
        while (i<=n)
            rp+=v[i++];
        return cp+rp;
    }

private:
    int n;
    vector<double> w, v;
    vector<bool> x, bestx;
    double cw = 0;
    double cp = 0;
    double bestp = 0;
    int W = 0;
};


class backTrackKs{

public:
    backTrackKs(int i=0)
    {
        n = i;
        cout << "Constructor" << endl;
    }

    ~backTrackKs()
    {
        cout << "Destructor" << endl;
    }

    void init()
    {
        cout << "Please enter the number of people in the tribe n: " << endl;
        cin >> n;
        cout << "Please enter the number of friends m: " << endl;
        cin >> m;
        x.resize(n+1);
        bestx.resize(n+1);
        a.resize(n+1);
        for(int i=0;i<a.size();i++)
            a[i].resize(n+1);
        cout << "Please enter two people who have a friendly relationship in turn: " << endl;
        int u, v;
        for(int i=1;i<=m;i++)
        {
            cin >> u >> v;
            a[u][v] = a[v][u] = 1;
        }
        track(1);
        cout << "The maximum number of the King¡¯s Guard is: " << bestn << endl;
        cout << "The members of the King¡¯s Guard are: ";
        for(int i=1;i<=n;i++)
            if(bestx[i] == 1)
                cout << i << " ";
        cout << endl;
    }

    void print()
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                cout << a[i][j] << " ";
            cout << endl;
        }
    }


private:
    void track(int t)
    {
        if(t>n)
        {
            bestn = cn;
            bestx = x;
            return;
        }
        if(place(t))
        {
            x[t] = 1;
            cn++;
            track(t+1);
            cn--;
        }
        if(cn+n-t>bestn)
        {
            x[t] = 0;
            track(t+1);
        }
    }

    bool place(int t)
    {
        for(int j=1;j<t;j++)
            if(x[j] && a[t][j] == 0)
                return false;
        return true;
    }

private:
    int n;
    int m;
    int bestn = 0;
    int cn = 0;
    vector<vector<int> > a;
    vector<bool> x, bestx;
};

class backTrackMP{

public:
    backTrackMP(int i=0)
    {
        n = i;
        cout << "Constructor" << endl;
        init();
    }

    ~backTrackMP()
    {
        cout << "Destructor" << endl;
    }

    void print()
    {
        for(int i=1;i<map.size();i++)
        {
            for(int j=1;j<map[i].size();j++)
                cout << map[i][j] << " ";
            cout << endl;
        }
    }

private:

    void init()
    {
        cout << "Please enter the number of nodes: " << endl;
        cin >> n;
        cout << "Please enter the number of colors: " << endl;
        cin >> m;
        x.resize(n+1);
        map.resize(n+1);
        for(int i=0;i<map.size();i++)
            map[i].resize(n+1);
        cout << "Please enter the number of edges" << endl;
        cin >> edge;
        int u, v;
        cout << "Please enter two connected nodes u and v in turn: " << endl;
        for(int i=1;i<=edge;i++)
        {
            cin >> u >> v;
            map[u][v] = map[v][u] = 1;
        }
        track(1);
    }

    bool OK(int t)
    {
        for(int i=1;i<t;i++)
        {
            if(map[t][i] && x[t] == x[i])
                return false;
        }
        return true;
    }

    void track(int t)
    {
        if(t>n)
        {
            sum++;
            cout << "The " << sum << " option: ";
            for(int i=1;i<=n;i++)
                cout << x[i] << " ";
            cout << endl;
        }
        else
        {
            for(int i=1;i<=m;i++)
            {
                x[t] = i;
                if(OK(t))
                    track(t+1);
            }
        }
    }

private:
    int n;
    int m;
    int edge;
    int sum = 0;
    vector<int> x;
    vector<vector<int> > map;
};


class backTrackNK{

public:
    backTrackNK(int i=0)
    {
        n = i;
        cout << "Constructor" << endl;
        init();
    }

    ~backTrackNK()
    {
        cout << "Destructor" << endl;
    }

private:
    void init()
    {
        cout << "Please enter the number of queens n: " << endl;
        cin >> n;
        x.resize(n+1);
        track(1);
        cout << "The number of answers is: " << countn << endl;
    }

    void track(int t)
    {
        if(t>n)
        {
            countn++;
            for(int i=1;i<=n;i++)
                cout << x[i] << " ";
            cout << endl;
            cout << "---------------" << endl;
        }
        else
        {
            for(int i=1;i<=n;i++)
            {
                x[t] = i;
                if(place(t))
                    track(t+1);
            }
        }
    }

    bool place(int t)
    {
        for(int i=1;i<t;i++)
            if(x[t] == x[i] || t-i == fabs(x[t]-x[i]))
                return false;
        return true;
    }

private:
    int n;
    int countn = 0;
    vector<int> x;
};

class backTrackPR{

private:
    struct node{
        node(int a = 0, int b = 0)
        {
            x = a;
            y = b;
        }
        int x;
        int y;
    };

public:
    backTrackPR(int i=0)
    {
        n = i;
        cout << "Constructor" << endl;
        init();
    }

    ~backTrackPR()
    {
        cout << "Destructor" << endl;
    }

private:

    void init()
    {
        cout << "Please enter the number of parts of the machine n: " << endl;
        cin >> n;
        x.resize(n+1);
        bestx.resize(n+1);
        T.resize(n+1);
        cout << "Please enter the processing time of each part: " << endl;
        for(int i=1;i<=n;i++)
        {
            cin >> T[i].x >> T[i].y;
            x[i] = i;
        }
        track(1);
        cout << "Optimal machining parts sequence: ";
        for(int i=1;i<=n;i++)
            cout << bestx[i] << " ";
        cout << endl;
        cout << "The optimal part processing time is: " << bestf << endl;
    }

    void track(int t)
    {
        if(t>n)
        {
            bestx = x;
            bestf = f2;
            return;
        }
        for(int i=t;i<=n;i++)
        {
            f1+=T[x[i]].x;
            int temp = f2;
            f2 = max(f1,f2)+T[x[i]].y;
            if(bestf>f2)
            {
                swap(x[t],x[i]);
                track(t+1);
                swap(x[t],x[i]);
            }
            f1-=T[x[i]].x;
            f2 = temp;
        }
    }


private:
    int n;
    int bestf = INT_MAX;
    int f1 = 0;
    int f2 = 0;
    vector<int> x, bestx;
    vector<node> T;
};



class backTrackTR{

public:
    backTrackTR(int i=0)
    {
        n = i;
        cout << "Constructor" << endl;
        init();
    }

    ~backTrackTR()
    {
        cout << "Destructor" << endl;
    }

private:

    void init()
    {
        cout << "Please enter the number of attractions n: " << endl;
        cin >> n;
        x.resize(n+1);
        bestx.resize(n+1);
        g.resize(n+1);
        for(int i=0;i<g.size();i++)
            g[i].resize(n+1,INT_MAX);
        for(int i=0;i<=n;i++)
            x[i] = i;
        cout << "Please enter the number of connections between attractions m: " << endl;
        cin >> m;
        int u, v, w;
        for(int i=1;i<=m;i++)
        {
            cin >> u >> v >> w;
            g[u][v]=g[v][u] = w;
        }
        track(2);
        cout << "The shortest path is: ";
        for(int i=1;i<=n;i++)
            cout << bestx[i] << "--->";
        cout << "1" << endl;
        cout << "The shortest path length is: " << best1 << endl;
    }

    void track(int t)
    {
        if(t>n)
        {
            if(g[x[n]][1]!=INT_MAX && cl+g[x[n]][1]<best1)
            {
                bestx = x;
                best1 = cl+g[x[n]][1];
            }
        }
        else
        {
            for(int i=t;i<=n;i++)
            {
                if(g[x[t-1]][x[i]] !=INT_MAX && cl+g[x[t-1]][x[i]]<best1)
                {
                    swap(x[t], x[i]);
                    cl+=g[x[t-1]][x[t]];
                    track(t+1);
                    cl-=g[x[t-1]][x[t]];
                    swap(x[t], x[i]);
                }
            }
        }
    }

private:
    int n, m;
    int best1 = INT_MAX;
    int cl = 0;
    vector<int> x, bestx;
    vector<vector<int> > g;
};

