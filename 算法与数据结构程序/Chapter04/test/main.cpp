#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

void testBinTree()
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
        cout << "树为空" << endl;

    tree.printXianTree();

 //   tree.printHouTree();

 //   tree.printZhongTree();

//    tree.printTree();


//    tree.makeEmpty();
//
//    tree.printTree();
//
//    if (tree.empty())
//        cout << "二叉树为空" << endl;

    cout << "zui xiao zhi:" << tree.findMin() << endl;

    cout << "zui da zhi:" << tree.findMax() << endl;

    if (tree.contains(0))
        cout << "this tree contains the element" << endl;

//    tree.remove(2);

    BinarySearchTree<int> tree1(tree);

//    tree1 = tree;

    tree1.printXianTree();

    cout << "the depth of tree:" << tree.treeDepth() << endl;

    cout << "the total nodes of tree:" << tree.nodeCount() << endl;



    cout << "---------------------------" << endl;


    BinarySearchTree<int> example;

    example.xianInsert();

    example.printXianTree();


}

int main()
{
    testBinTree();


    cout << "Hello world!" << endl;
    return 0;
}
