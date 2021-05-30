#include <iostream>
#include "Sort.h"
#include <cstdlib>
#include <time.h>

using namespace std;



    void test()
    {
        srand((unsigned)time(NULL));
//        int nums[]={-1,40,20,35,16,8,60,55,45};

//第一位不用留标志位
        vector<int> arr;

//第一位用于留标志位
//        vector<int> arr(1,-1);
        for(int i=0;i<9;i++)
            arr.push_back((rand()%(101)));

        for(int i=0;i<arr.size();i++)
            cout << arr[i] << ";";
        cout << endl;
        cout << "Before sorting" << endl;

//InsertionSort

//不一定完全需要标志位
//        insertionSort(arr);

//需要标志位
//        insertionSortSB(arr);

//需要标志位
//        insertionSortBS(arr);

//需要标志位
//        insertionSortSH(arr);

//不需要标志位
//        bubbleSort(arr);

//改进的冒泡排序(不需要标志位)
//        bubbleSortOP(arr);

//快速排序(需要标志位)
//        quickSort(arr);

//简单选择排序()
//        selectSort(arr);
//优化
        selectSortOP(arr);


        for(int i=0;i<arr.size();i++)
            cout << arr[i] << ";";
        cout << endl;
        cout << "After sorting" << endl;
    }

int main()
{
    test();
    cout << "Hello world!" << endl;
    return 0;
}
