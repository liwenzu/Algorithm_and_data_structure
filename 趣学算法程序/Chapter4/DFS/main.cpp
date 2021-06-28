#include <iostream>
#include "DFS.h"

using namespace std;


void testLCSL()
{
    string s1;
    string s2;
    cout << "Please enter the string s1" << endl;
    cin >> s1;
    cout << "Please enter the string s2" << endl;
    cin >> s2;
    vector<vector<int> > dp(s1.size()+1, vector<int>(s2.size()+1));
    vector<vector<int> > b(s1.size()+1, vector<int>(s2.size()+1));
    LCLS(dp, b, s1, s2);
    cout << "The longest common subsequence length is:" << dp[s1.size()][s2.size()] <<endl;
    cout << "The longest common subsequence is" << endl;
    print(b, s1, s1.size(), s2.size());
    cout <<endl;
//    for(int i=0;i<dp.size();i++)
//    {
//        for(int j=0;j<dp[i].size();j++)
//            cout << dp[i][j] <<" ";
//        cout << endl;
//    }
}
void testED()
{
    string s1;
    string s2;
    cout << "Please enter the string s1" << endl;
    cin >> s1;
    cout << "Please enter the string s2" << endl;
    cin >> s2;
    vector<vector<int> > dp(s1.size()+1, vector<int>(s2.size()+1));
    DE(dp, s1, s2);
    cout << "The minimum edit distance is:" << dp[s1.size()][s2.size()] <<endl;
    for(int i=0;i<dp.size();i++)
    {
        for(int j=0;j<dp[i].size();j++)
            cout << dp[i][j] <<" ";
        cout << endl;
    }
}

void testRent()
{
    int n;
    cout << "Please enter the number of sites n" << endl;
    cin >> n;
    vector<vector<int> > r(n+1, vector<int>(n+1));
    vector<vector<int> > dp(n+1, vector<int>(n+1));
    vector<vector<int> > s(n+1, vector<int>(n+1));
    cout << "Please enter the rent between sites in turn" << endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            cin >> r[i][j];
            dp[i][j] = r[i][j];
        }
    }
    rent(dp, s);
    cout << "The minimum rent spent is: " << dp[1][n] << endl;
    cout << "The site passed by is: " <<1;
    print(s, 1, n);
    cout << endl;
//    for(int i=0;i<dp.size();i++)
//    {
//        for(int j=0;j<dp[i].size();j++)
//            cout << dp[i][j] << " ";
//        cout << endl;
//    }
}

void testMatMul()
{
    int n;
    cout << "Please enter the number of matrices n" << endl;
    cin >> n;
    vector<vector<int> > m(n+1, vector<int>(n+1));
    vector<vector<int> > s(n+1, vector<int>(n+1));
    vector<int> p(n+1);
    cout << "Please enter the number of rows of each matrix and the number of columns of the last matrix in turn: " << endl;
    for(int i=0;i<=n;i++)
        cin >> p[i];
    matrixChain(m, s, p);
    mprint(s, 1, n);
    cout << endl;
    cout << "The minimum calculation amount is: " << m[1][n] << endl;
//    for(int i=0;i<=n;i++)
//        cout << p[i] << " ";
//    cout << endl;
//    for(int i=0;i<=n;i++)
//    {
//        for(int j=0;j<=n;j++)
//            cout << m[i][j] << " ";
//        cout << endl;
//    }
}

void testPZ()
{
    int n;
    cout << "Please enter the number of vertices n" << endl;
    cin >> n;
    vector<vector<double> > m(n, vector<double>(n));
    vector<vector<int> > s(n, vector<int>(n));
    vector<vector<double> > g(n, vector<double>(n));
    cout << "Please enter the weight of each vertex in turn: " << endl;
    for(int i=0;i<g.size();i++)
    {
        for(int j=0;j<g[i].size();j++)
            cin >> g[i][j];
    }
    PZ(m, g, s);
    cout << m[1][n-1]<< endl;
    printPZ(s, 1, n-1);
/*
    for(int i=0;i<g.size();i++)
    {
        for(int j=0;j<g[i].size();j++)
            cout << g[i][j] << " ";
        cout << endl;
    }
*/
}

void testST()
{
    int n;
    cout << "Please enter the number of piles of stones n" << endl;
    cin >> n;
    vector<vector<int> > smax(205, vector<int>(205));
    vector<vector<int> > smin(205, vector<int>(205));
    vector<int> ssum(205);
    vector<int> a(205);
    cout << "Please enter the number of stones in each pile one by one" << endl;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    straight(n, a, ssum, smax, smin);
    cout << "The minimum cost is (Straight): " << smin[1][n] << endl;
    cout << "The maximum cost is (Straight): " << smax[1][n] << endl;
    int minc = 0, maxc = 0;
    circular(n, a, ssum, smax, smin, maxc, minc);
    cout << "The minimum cost is (circular): " << minc << endl;
    cout << "The maximum cost is (circular): " << maxc << endl;
}

void testSP()
{
    int n,W;
    cout << "Please enter the number of products n: " << endl;
    cin >> n;
    cout << "Please enter the capacity w of the shopping cart: " << endl;
    cin >> W;
    vector<vector<int> > c(n+1, vector<int>(W+1));
    vector<int> w(n+1);
    vector<int> v(n+1);
    vector<int> x(n+1);
    cout << "Please enter the weight w and value v of each item in turn" << endl;
    for(int i=1;i<=n;i++)
        cin >> w[i] >> v[i];
    SP(c, w, v);
    cout << "The maximum value loaded into the shopping cart is: " << c[n][W] << endl;
    printSP(c, x, w);
    cout << "The items loaded into the shopping cart are: ";
    for(int i=1;i<x.size();i++)
        if(x[i]!=0)
            cout << i << " ";
    cout << endl;
}

void testBS()
{
    int n;
    cout << "Please enter the number of keywords n: " << endl;
    cin >> n;
    vector<vector<double> > c(n+2, vector<double>(n+1));
    vector<vector<double> > w(n+2, vector<double>(n+1));
    vector<vector<int> > s(n+2, vector<int>(n+1));
    vector<double> p(n+1);
    vector<double> q(n+1);
    cout << "Please enter the search probability of each keyword: " << endl;
    for(int i=1;i<p.size();i++)
        cin >> p[i];
    cout << "Please enter the search probability of each virtual node: " << endl;
    for(int i=0;i<q.size();i++)
        cin >> q[i];
    BST(c, w, s, p, q);
    cout << "The search cost of the minimum spanning tree is: " << c[1][n] << endl;
    cout << "The optimal binary search tree is: " << endl;
    printBST(s, 1, n, 0);
}

int main()
{
//    testLCSL();
//    testED();
//    testRent();
//    testMatMul();
//    testPZ();
//    testST();
//    testSP();
    testBS();

    cout << "Hello world!" << endl;
    return 0;
}
