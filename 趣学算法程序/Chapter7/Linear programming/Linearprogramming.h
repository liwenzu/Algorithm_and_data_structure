#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>

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
