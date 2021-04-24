#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

testBinTree()
{

    BinarySearchTree<int> tree;
    for (int i = 1; i<5;i++) {
        tree.insert(i);
    }
    tree.insert(0);
    tree.insert(6);
    tree.insert(5);
    tree.insert(7);

    if (tree.empty())
        cout << "Ê÷Îª¿Õ" << endl;

    tree.printXianTree();

    tree.printHouTree();

    tree.printZhongTree();




}

int main()
{
    testBinTree();


    cout << "Hello world!" << endl;
    return 0;
}
