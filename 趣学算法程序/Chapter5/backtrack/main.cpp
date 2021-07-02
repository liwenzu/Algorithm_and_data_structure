#include <iostream>
#include "backtrack.h"

using namespace std;


void testSp()
{
    backTrackSp sp;
    sp.init();
 //   sp.print();
}

void testKS()
{
    backTrackKs ks;
    ks.init();
//    ks.print();

}

void testMP()
{
    backTrackMP mp;
//    mp.print();
}



int main()
{
//    testSp();
//    testKS();
    testMP();
    cout << "Hello world!" << endl;
    return 0;
}
