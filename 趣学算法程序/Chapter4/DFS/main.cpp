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

int main()
{
    testLCSL();
    cout << "Hello world!" << endl;
    return 0;
}
