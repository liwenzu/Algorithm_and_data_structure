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


int main()
{
//    testLCSL();
//    testED();
//    testRent();
//    testMatMul();
    testPZ();

    cout << "Hello world!" << endl;
    return 0;
}
