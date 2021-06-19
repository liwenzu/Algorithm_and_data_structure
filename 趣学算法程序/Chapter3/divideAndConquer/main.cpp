#include <iostream>
#include "divideAndConquer.h"

using namespace std;

void testBS()
{
    int i = binarySearch();
    if(i==-1)
        cout << "Did not find the required element" << endl;
    else
        cout << "The location of the element:" << i <<endl;
}

void tesMS()
{
    int n=0;
    cout << "Please enter the number of elements in the sequence n" << endl;
    cin >> n;
    vector<int> A(n);
    cout << "Please enter the element" << endl;
    for(int i=0;i<n;i++)
        cin >> A[i];
    cout << "Results before merging" << endl;
    for(int i=0;i<n;i++)
        cout << A[i] << " ";
    cout << endl;
    MergeSort(A, 0, n-1);
    cout << "Merged result" << endl;
    for(int i=0;i<n;i++)
        cout << A[i] << " ";
    cout << endl;
}

void tesQS()
{
    int n;
    cout << "Please enter the number of elements in the sequence n" << endl;
    cin >> n;
    vector<int> A(n);
    cout << "Please enter the element" << endl;
    for(int i=0;i<n;i++)
        cin >> A[i];
    cout << "Results before merging" << endl;
    for(int i=0;i<n;i++)
        cout << A[i] << " ";
    cout << endl;
    QuickSort(A, 0, n-1);
    cout << "Merged result" << endl;
    for(int i=0;i<n;i++)
        cout << A[i] << " ";
    cout << endl;

}

void testMU()
{
    multiply mu;
    mu.init();
    mu.print();
}


int main()
{
//    testBS();
//    tesMS();
//    tesQS();
    testMU();
    cout << "Hello world!" << endl;
    return 0;
}
