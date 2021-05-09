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

void GLtest()
{
    GraphLink grp;
    grp.GraphCreate();
//    grp.printVe();
    grp.DFS();
    grp.BFS();
}

int main()
{
//    GMtest();
    GLtest();
    cout << "Hello world!" << endl;
    return 0;
}
