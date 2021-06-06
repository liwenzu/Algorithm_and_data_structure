#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

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






















