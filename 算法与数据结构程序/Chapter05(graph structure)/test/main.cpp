#include <iostream>
#include "graph.h"

using namespace std;

void GMtest()
{
    GraphMatrix grp;
    grp.UDGraphCreate();
    grp.printVe();
}

int main()
{
    GMtest();
    cout << "Hello world!" << endl;
    return 0;
}
