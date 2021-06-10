#include <iostream>
#include "greedyAlgorithm.h"

using namespace std;


void test()
{
    int arrcp[8] = {4, 10, 7, 11, 3, 5, 14, 2};
    vector<int> arr;
    for(int i=0;i<8;i++)
    {
//        int m;
//        cin >> m;
        arr.push_back(arrcp[i]);
    }
    int ans = GreedyAlgorithm(arr, 30);

    cout << "Maximum number of artifacts:" << ans << endl;
}

void testAlibaba()
{
    double arrcp[7][2] = {{2, 8}, {6, 1}, {7, 9}, {4, 3}, {10, 2}, {3, 4}};
    vector<three> arr;
    for(int i=0;i<6;i++)
    {
        three t1;
        t1.w = arrcp[i][0];
        t1.v = arrcp[i][1];
        t1.p = arrcp[i][1]/arrcp[i][0];
        arr.push_back(t1);
    }
    double price = Alibaba(arr, 19);
    cout << "The maximum value of the goods is:" << price << endl;
}

//»áÒé²âÊÔ
void testMeet()
{
    setMeet s1;
 //   s1.print();
    s1.solve();
    cout << "Sorted meeting" << endl;
    s1.print();
}

//最短路径
void testDi()
{
    Dijkstra d1;
    d1.init();
// Ordinary method
//    d1.minimumPath
//  priority queue
    d1.minimumPathPQ();
    d1.print();
    d1.printMP();
//    d1.printCity();
}


int main()
{
//    test();
//    testAlibaba();
//    testMeet();
    testDi();

    cout << "Hello world!" << endl;
    return 0;
}
