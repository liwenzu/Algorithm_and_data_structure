#include <iostream>
#include <vector>

using namespace std;


int SearchInOrder(const vector<int> &v, int f)
{
    cout << "顺序查找不带哨兵" << endl;
    for (int i=v.size()-1;i>=0;i--)
    {
        if (f==v[i])
            return i;
    }
    return -1;
}


int SearchInOrder1(vector<int> &v, int f)
{
    cout << "带哨兵查找" << endl;
    v[0] = f;
    int i=v.size()-1;
    for (;v[i]!=f;i--);
    return i;
}

int binarySearch(vector<int> &v, int f)
{
    cout << "二分查找非递归" << endl;
    int l=0,r=v.size()-1;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if (v[mid]==f)
            return mid;
        else if(v[mid]<f)
            l=mid+1;
        else
            r=mid-1;
    }
    return 0;
}


int binarySearchD(vector<int> &v, int l, int r, int f)
{
//    cout << "二分查找递归" << endl;
    if (l>r)
        return 0;
    int mid = (l+r)/2;
    if (v[mid]==f)
        return mid;
    else if (v[mid]<f)
        return binarySearchD(v, mid+1, r, f);
    else
        return binarySearchD(v, l, mid-1, f);
}


int main()
{
    vector<int> v1(10000);
    for (int i=1; i<10000; i++)
        v1[i]= i*i;


//    int r = SearchInOrder(v1, 100);
//    int r = SearchInOrder1(v1, 100);
//    int r = binarySearch(v1, 100);

    int r = binarySearchD(v1, 0, v1.size()-1, 10000);

    cout << "查找到的位置:" << r << endl;

//    for(int i=0;i<v1.size();i++)
//        cout << v1[i] << ";";
//    cout << endl;

    cout << "Hello world!" << endl;
    return 0;
}
