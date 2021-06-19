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


