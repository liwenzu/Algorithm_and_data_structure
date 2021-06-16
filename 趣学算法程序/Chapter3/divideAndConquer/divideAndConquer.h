#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int recSearch(vector<int> &s, int low, int high, int f)
{
    if(low>high)
        return -1;
    int m = (low+high)/2;
    if(s[m]==f)
        return m;
    else if (s[m]>f)
        return recSearch(s, low, m-1, f);
    else
        return recSearch(s, m+1, high, f);
}

int binarySearch()
{
    int n;
    cout << "Please enter the number of elements in the sequence" << endl;
    cin >> n;
    vector<int> s(n);
    cout << "Please enter the elements in the array one by one" << endl;
    for(int i=0;i<s.size();i++)
        cin >> s[i];
    sort(s.begin(), s.end());
    cout << "Sorted array" << endl;
    for(int i=0;i<s.size();i++)
        cout << s[i] << " ";
    cout << endl;
    int f;
    cout << "Please enter the element you want to find" << endl;
    cin >>f;
    int low=0, high=s.size()-1,middele=0;

    return middele = recSearch(s, low, high, f);

//    while(low<=high)
//    {
//        middele = (low+high)/2;
//        if(s[middele]==f)
//            return middele;
//        else if(s[middele]>f)
//            high=middele-1;
//        else
//            low=middele+1;
//    }
//    return -1;
}
