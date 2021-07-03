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

void testNK()
{
    backTrackNK nk;
}

void testPR()
{
    backTrackPR pr;
}

void testTR()
{
    backTrackTR tr;
}



int main()
{
//    testSp();
//    testKS();
//    testMP();
//    testNK();
//    testPR();
    testTR();
    cout << "Hello world!" << endl;
    return 0;
}
