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

int main()
{
    testBS();
    cout << "Hello world!" << endl;
    return 0;
}
