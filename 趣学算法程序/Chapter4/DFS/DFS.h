#pragma once
#include <iostream>
#include <vector>

using namespace std;

//最长公共子序列
void LCLS(vector<vector<int> > &dp, vector<vector<int> > &b, string s1, string s2)
{
    for(int i=1;i<dp.size();i++)
    {
        for(int j=1;j<dp[i].size();j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j] = dp[i-1][j-1]+1;
                b[i][j] = 1;
            }

            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if(dp[i][j-1]>=dp[i-1][j])
                    b[i][j] = 2;
                else
                    b[i][j] = 3;
            }
        }
    }
}

void print(vector<vector<int> > &b, string s1, int i, int j)
{
    if(i==0 || j==0)
        return;
    if(b[i][j] == 1)
    {
        print(b, s1, i-1, j-1);
        cout << s1[i-1];
    }
    else if (b[i][j]==2)
        print(b,s1,i,j-1);
    else
        print(b,s1,i-1,j);
}


void DE(vector<vector<int> > &dp, string s1, string s2)
{
   int temp;
   for(int i=0;i<dp.size();i++)
   {
       for(int j=0;j<dp.size();j++)
       {
           if(i==0 || j==0)
             dp[i][j] = i==0? j:i;
           else
           {
             if (s1[i-1] == s2[j-1])
               temp = 0;
             else
               temp = 1;
             dp[i][j] = min(dp[i-1][j]+1, min(dp[i][j-1]+1, dp[i-1][j-1]+temp));
           }
       }
   }
}

void rent(vector<vector<int> > &dp, vector<vector<int> > &s)
{
    for(int d=3;d<dp.size();d++)
    {
        for(int i=1;i<dp.size()-d+1;i++)
        {
            int j=i+d-1;
            for(int k=1;k<j;k++)
            {
                if(dp[i][k]+dp[k][j]<dp[i][j])
                {
                    dp[i][j] = dp[i][k]+dp[k][j];
                    s[i][j] = k;
                }
            }
        }
    }
}

void print(vector<vector<int> > &s, int i, int j)
{
    if(s[i][j] == 0)
    {
        cout << "---" <<j;
        return;
    }
    print(s, i,s[i][j]);
    print(s, s[i][j], j);
}


void matrixChain(vector<vector<int> > &m, vector<vector<int> > &s, vector<int> &p)
{
    for(int r=2;r<m.size();r++)
    {
        for(int i=1;i<m.size()-r+1;i++)
        {
            int j=i+r-1;
            m[i][j] = m[i+1][j]+p[i-1]*p[i]*p[j];
            s[i][j] = i;
            for(int k=i+1;k<j;k++)
            {
                int t = m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(t<m[i][j])
                {
                    m[i][j]=t;
                    s[i][j]=k;
                }
            }
        }
    }
}

void mprint(vector<vector<int> > &s, int i, int j)
{
    if(i==j)
    {
        cout << "A[" << i << "]";
        return;
    }
    cout << "(";
    mprint(s, i, s[i][j]);
    mprint(s, s[i][j]+1, j);
    cout << ")";
}


void PZ(vector<vector<double> > &m, vector<vector<double> > &g, vector<vector<int> > &s)
{
    for(int d=2;d<g.size();d++)
    {
        for(int i=1;i<g.size()-d+1;i++)
        {
            int j = i+d-1;
            m[i][j] = m[i+1][j] + g[i-1][i] + g[i][j] + g[i-1][j];
            s[i][j] = i;
            for(int k=i+1;k<j;k++)
            {
                double temp = m[i][k] + m[k+1][j] + g[i-1][k] +g[k][j] + g[i-1][j];
                if(temp < m[i][j])
                {
                    m[i][j] = temp;
                    s[i][j] = k;
                }
            }
        }
    }
}

void printPZ(vector<vector<int> > &s, int i, int j)
{
    if(i==j)
        return;
    if(s[i][j]>i)
        cout << "{v" << i-1 << "v" << s[i][j] << "}" << endl;
    if(j>s[i][j]+1)
        cout << "{v" << s[i][j] << "v" << j << "}" << endl;
    printPZ(s, i, s[i][j]);
    printPZ(s, s[i][j]+1, j);
}

void straight(int n, vector<int> &a, vector<int> &ssum, vector<vector<int> > &smax, vector<vector<int> > &smin)
{
    for(int i=1;i<=n;i++)
    {
        smax[i][i] = 0;
        smin[i][i] = 0;
    }
    ssum[0] = 0;
    for(int i=1;i<=n;i++)
        ssum[i]=ssum[i-1]+a[i];
    for(int d=2;d<=n;d++)
    {
        for(int i=1;i<=n-d+1;i++)
        {
            int j = i+d-1;
            smax[i][j] = INT_MIN;
            smin[i][j] = INT_MAX;
            int temp = ssum[j]-ssum[i-1];
            for(int k=i;k<j;k++)
            {
                smax[i][j] = max(smax[i][j], smax[i][k] + smax[k+1][j] + temp);
                smin[i][j] = min(smin[i][j], smin[i][k] + smin[k+1][j] +temp);
            }
        }
    }

}

void circular(int n, vector<int> &a, vector<int> &ssum, vector<vector<int> > &smax, vector<vector<int> > &smin, int &maxc, int &minc)
{
    for(int i=1;i<=n-1;i++)
        a[n+i] = a[i];
    n = 2*n-1;
    straight(n, a, ssum, smax, smin);
    n=(n+1)/2;
    maxc = smax[1][n];
    minc = smin[1][n];
    for(int i=2;i<=n;i++)
    {
        if(smin[i][i+n-1] < minc)
            minc = smin[i][i+n-1];
        if(smax[i][i+n-1]>maxc)
            maxc = smax[i][i+n-1];
    }
}

void SP(vector<vector<int> > &c, vector<int> &w, vector<int> &v)
{
    for(int i=1;i<c.size();i++)
    {
        for(int j=1;j<c[0].size();j++)
        {
            if(j<w[i])
                c[i][j] = c[i-1][j];
            else
                c[i][j] = max(c[i-1][j], c[i-1][j-w[i]] + v[i]);
        }
    }
}

void printSP(vector<vector<int> > &c, vector<int> &x, vector<int> &w)
{
    int j = c[0].size()-1;
    for(int i=c.size()-1;i>0;i--)
    {
        if(c[i][j]>c[i-1][j])
        {
            x[i] = 1;
            j-=w[i];
        }
    }
}
