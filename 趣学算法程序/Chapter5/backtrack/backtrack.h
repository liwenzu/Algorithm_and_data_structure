#pragma once
#include <iostream>
#include <vector>

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
    }

    void print()
    {
        for(int i=1;i<=n;i++)
            cout << "item:" << i << " " << w[i] << "  " << v[i] << endl;
    }

private:
    void Knapsack()
    {

    }

    void track()
    {

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
