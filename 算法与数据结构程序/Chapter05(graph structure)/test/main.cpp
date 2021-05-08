#include <iostream>
#include "graph.h"

using namespace std;

void GMtest()
{
    GraphMatrix grp;
    grp.GraphCreate();
//    grp.printVe();
    grp.DFS();
    grp.BFS();
}

int main()
{
    GMtest();
    cout << "Hello world!" << endl;
    return 0;
}
