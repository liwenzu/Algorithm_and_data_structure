#include <iostream>
#include "BinarySearchTree.h"
#include "AVLTree.h"

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

void AVLTest()
{
    AVLTree<int>  avlt;
    int height;
    cout << "Please enter the total number of nodes" << endl;
    cin >> height;
    cout << "***************************" << endl;

    for(int i=0;i<height;i++)
    {
        int element;
        cin >> element;
        avlt.insert(element);
    }
    cout << "***************************" << endl;
    avlt.printTree();
    cout << "***************************" << endl;
    avlt.printTreeAVL();

    cout << "the smallest number:" << avlt.findMin() << endl;
    cout << "the biggest number:" << avlt.findMax() << endl;


    cout << "Binary tree starts to adjust" << endl;

    int curr;
    cout << "Please enter the insert node" << endl;
    cin >> curr;
    avlt.insertAVL(curr);
    cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
    avlt.printTree();
    cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
    avlt.printTreeAVL();



    cout << "remove" << endl;
    cout << "Please enter the insert node" << endl;
    cin >> curr;
    avlt.remove(curr);
    cout << "SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS" << endl;
    avlt.printTree();
    cout << "SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS" << endl;
    avlt.printTreeAVL();

//    if (avlt.contains(38))
//        cout << "yes" << endl;







//    AVLTree<int>  avltcp(avlt);
//    AVLTree<int>  avltcp;
//    avltcp = avlt;
//
//    avltcp.printTree();
}

int main()
{
//    testBinTree();

    AVLTest();
    cout << "Hello world!" << endl;
    return 0;
}
