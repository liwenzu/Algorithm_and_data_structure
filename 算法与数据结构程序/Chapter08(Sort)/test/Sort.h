#include <iostream>
#include <vector>


using namespace std;

template <typename T>
void insertionSort(vector<T> &arr)
{
    int n=arr.size();
    for(int i=1;i<n;i++)
    {
        T temp = arr[i];
        int j = i-1;
        for(; arr[j]>temp && j>=0;j--)
            arr[j+1]=arr[j];
        arr[j+1] = temp;
    }
}

//加哨兵
template <typename T>
void insertionSortSB(vector<T> &arr)
{
    int n=arr.size();
    for(int i=2;i<n;i++)
    {
        arr[0] = arr[i];
        int j = i-1;
        for(; arr[j]>arr[0];j--)
            arr[j+1]=arr[j];
        arr[j+1] = arr[0];
    }
}

//折半
template <typename T>
void insertionSortBS(vector<T> &arr)
{
    int n=arr.size();
    for(int i=2;i<n;i++)
    {
        arr[0] = arr[i];
        int left = 1;
        int right = i-1;
        while(left<=right)
        {
            int mid = (left+right)/2;
            if(arr[mid]>arr[0])
                right = mid-1;
            else
                left = mid+1;
        }
        int j = i-1;
        for(; j>=right+1;j--)
            arr[j+1]=arr[j];
        arr[right+1] = arr[0];
    }
}

//shell
template<typename T>
void insertionSortSH(vector<T> &arr)
{
    int n=arr.size();
    for(int d=n>>1;d>0;d=d>>1)
    {
        for(int i=d+1;i<n;i++)
        {
           if(arr[i]<arr[i-d])
           {
                arr[0]=arr[i];
                int j=i-d;
                for(;j>0 && arr[j]>arr[0];j-=d)
                    arr[j+d] = arr[j];
                arr[j+d] = arr[0];
           }
        }
    }
}

//Bubble Sort
template<typename T>
void bubbleSort(vector<T> &arr)
{
    int n=arr.size();
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                T temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

//Optimized bubble sort algorithm
template<typename T>
void bubbleSortOP(vector<T> &arr)
{
    int n=arr.size();
    int flag=1;
    for(int i=1;i<n && flag;i++)
    {
        flag = 0;
        for(int j=0;j<n-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                T temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                flag = 1;
            }
        }
    }
}

//快排(需要设置标志位)
template <typename T>
int Partition(vector<T> &arr, int left, int right)
{
    arr[0] = arr[left];
    int pivotkey = arr[left];
    while(left<right)
    {
        while(left<right && arr[right]>=pivotkey)
            right--;
        arr[left] = arr[right];
        while(left<right && arr[left]<=pivotkey)
            left++;
        arr[right]=arr[left];
    }
    arr[left] = arr[0];
    return left;
}

template <typename T>
void quickSort(vector<T> &arr, int left, int right)
{
    if(left < right)
    {
        int pivotloc = Partition(arr, left, right);
        quickSort(arr, left, pivotloc-1);
        quickSort(arr, pivotloc+1, right);
    }
}

template <typename T>
void quickSort(vector<T> &arr)
{
    int left = 1, right = arr.size()-1;
    quickSort(arr, left, right);
}

//选择排序(不设置标志位)
template <typename T>
void selectSort(vector<T> &arr)
{
    int n = arr.size();
    for(int i=0;i<n-1;i++)
    {
        T temp = arr[i];
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<temp)
            {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }

        }
    }
}

template <typename T>
void selectSortOP(vector<T> &arr)
{
    int n = arr.size();
    for(int i=0;i<n-1;i++)
    {
        int m=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[m])
                m=j;
        }
        if(m!=i)
        {
            T temp = arr[m];
            arr[m] = arr[i];
            arr[i] = temp;
        }
    }
}


//堆排序
template <typename T>
void HeapAdjust(vector<T> &nu, int s, int m)
{
    nu[0] = nu[s];
    for(int j=2*s;j<=m;j*=2)
    {
        if(j<m && nu[j]<nu[j+1])
            j++;
        if(nu[0]>=nu[j])
            break;
        nu[s] = nu[j];
        s=j;
    }
    nu[s] = nu[0];
}

template <typename T>
void CreatHeap(vector<T> &nu)
{
    int n=nu.size();
    for(int i=(n-1)/2;i>0;i--)
    {
        HeapAdjust(nu, i, n-1);
    }
}

template <typename T>
void HeapSort(vector<T> &nu)
{
    CreatHeap(nu);
    int n = nu.size();
    for(int i=n-1;i>1;i--)
    {
        nu[0]=nu[1];
        nu[1]=nu[i];
        nu[i]=nu[0];
        HeapAdjust(nu, 1, i-1);
    }
}

//归并排序











