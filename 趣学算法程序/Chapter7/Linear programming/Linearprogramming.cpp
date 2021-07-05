#include "Linearprogramming.h"

linProPR::linProPR()
{
    init();
    cout << "Constructor" << endl;
}

linProPR::~linProPR()
{
    cout << "Destructor" << endl;
}

void linProPR::init()
{
    cout << "Please enter the number of non-basic variables and subscripts of non-basic variables: " << endl;
    cin >> m;
    FJL.resize(m+1);
    for(int i=1;i<FJL.size();i++)
        cin >> FJL[i];
    cout << "Please enter the number of basic variables and the index of basic variables: " << endl;
    cin >> n;
    JL.resize(n+1);
    for(int i=1;i<JL.size();i++)
        cin >> JL[i];
    kernel.resize(n+1);
    for(int i=0;i<kernel.size();i++)
        kernel[i].resize(m+1);
    cout << "Please enter the simplex table parameters: " << endl;
    for(int i=0;i<kernel.size();i++)
        for(int j=0;j<kernel[i].size();j++)
            cin >> kernel[i][j];
    print();
    DCXA();
}

void linProPR::print()
{
    cout << endl;
    cout << "----------tables----------" << endl;
    cout << "  ";
    cout << setw(7) << "b ";
    for(int i=1;i<=m;i++)
        cout << setw(7) << "x" << FJL[i];
    cout << endl;
    cout << "c ";
    for(int i=0;i<=n;i++)
    {
        if(i>=1)
            cout <<"x"<<JL[i];
        for(int j=0;j<=m;j++)
            cout << setw(7) << kernel[i][j] << " ";
        cout << endl;
    }
}

void linProPR::DCXA()
{
    float max1;
    float max2;
    int e = -1;
    int k = -1;
    float min1;
    while(true)
    {
        max1 = 0;
        max2 = 0;
        min1 = INT_MAX;
        for(int j=1;j<=m;j++)
        {
            if(max1<kernel[0][j])
            {
                max1 = kernel[0][j];
                e = j;
            }
        }
        if(max1<=0)
        {
            cout << endl;
            cout << "Obtained the optimal solution: " << kernel[0][0] << endl;
//            print();
            break;
        }
        for(int i=1;i<=n;i++)
        {
            if(max2<kernel[i][e])
                max2 = kernel[i][e];
            float temp = kernel[i][0]/kernel[i][e];
            if(temp>0 && temp<min1)
            {
                min1 = temp;
                k = i;
            }
        }
        cout << "Base variable: " << "x" << FJL[e] << " ";
        cout << "Off-base variable: " << "x" << JL[k] << endl;
        if(max2 == 0)
        {
            cout << "Unbounded" << endl;
            break;
        }
        char temp = FJL[e];
        FJL[e] =  JL[k];
        JL[k] = temp;
        for(int i=0;i<=n;i++)
        {
            if(i!=k)
            {
                for(int j=0;j<=m;j++)
                {
                    if(j!=e)
                    {
                        if(i==0 && j==0)
                            kernel[i][j] = kernel[i][j] + (kernel[i][e]*kernel[k][j])/kernel[k][e];
                        else
                            kernel[i][j] = kernel[i][j] - (kernel[i][e]*kernel[k][j])/kernel[k][e];

                    }
                }
            }
        }
        for(int i=0;i<=n;i++)
        {
            if(i!=k)
                kernel[i][e]=-kernel[i][e]/kernel[k][e];
        }
        for(int j=0;j<=m;j++)
        {
            if(j!=e)
                kernel[k][j]=kernel[k][j]/kernel[k][e];
        }
        kernel[k][e] = 1/kernel[k][e];
        print();
    }
}



//network
trackNT::trackNT()
{
    init();
    cout << "Constructor" << endl;
}

trackNT::~trackNT()
{
    cout << "Destructor" << endl;
}

void trackNT::init()
{
    cout << "Please enter the number of nodes and the number of edges: " << endl;
    cin >> n >> m;
    g.resize(n+1);
    f.resize(n+1);
    vis.resize(n+1, false);
    pre.resize(n+1, -1);
    for(int i=0;i<g.size();i++)
    {
        g[i].resize(n+1);
        f[i].resize(n+1);
    }
    int u, v, w;
    cout << "Please enter the capacity of two nodes and edges: " << endl;
    for(int i=1;i<=m;i++)
    {
        cin >> u >> v >> w;
        g[u][v] += w;
    }
    cout << "The maximum flow value of the network is: " << EK(1,n) << endl;
    print();

}

int trackNT::EK(int s, int t)
{
    int v,w,d,maxflow;
    maxflow = 0;
    while(bfs(s,t))
    {

        cout << "&&&&&&&&&&&&&&&&&&&" << endl;

        v = t;
        d = INT_MAX;
        while(v!=s)
        {
            w=pre[v];
            if(g[w][v]<d)
                d = g[w][v];
            v = w;
        }
        maxflow+=d;
        v = t;
        while(v!=s)
        {
            w = pre[v];
            g[w][v]-=d;
            g[v][w]+=d;
            if(f[v][w]>0)
                f[v][w]-=d;
            else
                f[w][v]+=d;
            v = w;
        }
    }
    return maxflow;
}

bool trackNT::bfs(int s, int t)
{
    pre.resize(n+1, -1);
    vis.resize(n+1, false);
    queue<int> q;
    vis[s] = true;
    q.push(s);
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        for(int i=1;i<=n;i++)
        {
            if(!vis[i]&&g[now][i]>0)
            {
                vis[i] = true;
                pre[i] = now;
                if(i==t)
                    return true;
                q.push(i);
            }
        }
    }
    return false;
}

void trackNT::print()
{
    cout << endl;
    cout << "-----------------network-----------------" << endl;
    cout << "  ";
    for(int i=1;i<=n;i++)
        cout << setw(7) << "v" <<i;
    cout << endl;
    for(int i=1;i<=n;i++)
    {
        cout << "v" <<i;
        for(int j=1;j<=n;j++)
            cout << setw(7) << f[i][j] << " ";
        cout << endl;
    }
}






