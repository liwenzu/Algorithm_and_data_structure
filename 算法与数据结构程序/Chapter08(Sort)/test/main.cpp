#include <iostream>
#include "Sort.h"
#include <cstdlib>
#include <time.h>

using namespace std;



    void test()
    {
        srand((unsigned)time(NULL));
//        int nums[]={-1,40,20,35,16,8,60,55,45};

//��һλ��������־λ
        vector<int> arr;

//��һλ��������־λ
//        vector<int> arr(1,-1);
        for(int i=0;i<9;i++)
            arr.push_back((rand()%(101)));

        for(int i=0;i<arr.size();i++)
            cout << arr[i] << ";";
        cout << endl;
        cout << "Before sorting" << endl;

//InsertionSort

//��һ����ȫ��Ҫ��־λ
//        insertionSort(arr);

//��Ҫ��־λ
//        insertionSortSB(arr);

//��Ҫ��־λ
//        insertionSortBS(arr);

//��Ҫ��־λ
//        insertionSortSH(arr);

//����Ҫ��־λ
//        bubbleSort(arr);

//�Ľ���ð������(����Ҫ��־λ)
//        bubbleSortOP(arr);

//��������(��Ҫ��־λ)
//        quickSort(arr);

//��ѡ������()
//        selectSort(arr);
//�Ż�
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
