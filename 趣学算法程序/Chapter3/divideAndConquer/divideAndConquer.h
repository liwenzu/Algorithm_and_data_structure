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

void Merge(vector<int> &A, int low, int high, int mid)
{
    vector<int> temp(high-low+1);
    int i=low, j=mid+1, k=0;
    while(i<=mid && j<=high)
    {
        if(A[i]<=A[j])
            temp[k++] = A[i++];
        else
            temp[k++] = A[j++];
    }
    while (i<=mid)
        temp[k++] = A[i++];
    while (j<=high)
        temp[k++] = A[j++];
    for(i=low,k=0;i<=high;i++)
        A[i] = temp[k++];
}



void MergeSort(vector<int> &A, int low, int high)
{
    if(low < high)
    {
        int mid = (low+high)/2;
        MergeSort(A, low, mid);
        MergeSort(A, mid+1, high);
        Merge(A, low, high, mid);
    }

}


//©ЛкыеепР
int Partition(vector<int> &A, int low, int high)
{
    int i=low, j=high, pivot = A[low];
    while(i<j)
    {
        while(i<j && A[j]>pivot)
            j--;
        if(i<j)
            A[i++] = A[j];
        while(i<j && A[i]<pivot)
            i++;
        if(i<j)
            A[j--] = A[i];
    }
    A[j] = pivot;
    return j;
}

void QuickSort(vector<int> &A, int low, int high)
{
    if(low<high)
    {
        int mid = Partition(A, low,high);
        QuickSort(A, low, mid-1);
        QuickSort(A, mid+1, high);
    }
}


//大数相乘
class multiply{
    enum {MAXVALUE = 100};

private:
    struct Node{
    Node()
    {
        s.resize(MAXVALUE);
    }
    vector<int> s;
    int l;
    int c;
    };

public:
    multiply()
    {
        cout << "Constructor" << endl;
    }

    ~multiply()
    {
        cout << "Destructor" << endl;
    }

    void init()
    {
        cout << "Please enter a large integer a" << endl;
        cin >> sa;
        cout << "Please enter a large integer b" << endl;
        cin >> sb;
        a.l = sa.size();
        b.l = sb.size();
        for(int i=a.l-1,z=0;i>=0;i--)
            a.s[z++] = sa[i]-'0';
        a.c = 0;
        for(int i=b.l-1,z = 0;i>=0;i--)
            b.s[z++] = sb[i]-'0';
        b.c = 0;
        mul(&a, &b, &ans);
    }

    void print()
    {
//        cout << sa << endl;
//        cout << sb << endl;
//        for(int i=0;i<a.l;i++)
//            cout << a.s[i] << " ";
//        for(int i=0;i<b.l;i++)
//            cout << b.s[i] << " ";

        cout << "The final result is" << endl;
        for(int i=ans.l-1;i>=0;i--)
            cout << ans.s[i];
        cout << endl;
    }

private:
    void mul(Node *pa, Node *pb, Node *ans1)
    {
        int i, cc, w;
        int ma = pa->l>>1, mb = pb->l>>1;
        Node ah, al, bh, bl;
        Node t1, t2, t3, t4, z;
        Node *temp;
        if(!ma || !mb)
        {
            if(!ma)
            {
                temp = pa;
                pa = pb;
                pb = temp;
            }
            ans1->c = pa->c + pb->c;
            w = pb->s[0];
            cc = 0;
            for(i=0;i<pa->l;i++)
            {
                ans1->s[i] = (w*pa->s[i]+cc)%10;
                cc = (w*pa->s[i]+cc)/10;
            }
            if(cc)
                ans1->s[i++] = cc;
            ans1->l = i;
            return;
        }
        cp(pa, &ah, ma, pa->l-ma);
        cp(pa, &al, 0, ma);
        cp(pb, &bh, mb, pb->l-mb);
        cp(pb, &bl, 0, mb);

        mul(&ah, &bh, &t1);
        mul(&ah, &bl, &t2);
        mul(&al, &bh, &t3);
        mul(&al, &bl, &t4);

        add(&t3, &t4, ans1);
        add(&t2, ans1, &z);
        add(&t1, &z, ans1);
    }

    void cp(Node *src, Node *des, int st, int l)
    {
        int i, j;
        for(i=st, j=0;i<st+l;i++,j++)
            des->s[j] = src->s[i];
        des->l = l;
        des->c = src->c + st;
    }

    void add(Node *pa, Node *pb, Node *ans1)
    {
        int i, cc, k, palen, pblen, len;
        int ta, tb;
        Node *temp;
        if(pa->c < pb->c)
        {
            temp = pa;
            pa = pb;
            pb = temp;
        }
        ans1->c = pb->c;
        cc = 0;
        palen = pa->l + pa->c;
        pblen = pb->l + pb->c;
        if (palen>pblen)
            len = palen;
        else
            len = pblen;
        k = pa->c - pb->c;
        for(i=0;i<len - ans1->c;i++)
        {
            if(i<k)
                ta = 0;
            else
                ta = pa->s[i-k];
            if(i<pb->l)
                tb = pb->s[i];
            else
                tb = 0;
            ans1->s[i] = (ta+tb+cc)%10;
            cc = (ta+tb+cc)/10;
        }
        if(cc)
            ans1->s[i++] = cc;
        ans1->l = i;
    }


private:
    string sa;
    string sb;
    Node ans;
    Node a;
    Node b;
};





























