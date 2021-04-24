#pragma once
#include <iostream>

#define nullptr NULL

using namespace std;

template<class T>
class BinarySearchTree{
private:
    struct BinaryNode{
    BinaryNode(const T &element, BinaryNode *lt, BinaryNode *rt)
    {
        ele = element;
        left = lt;
        right = rt;
    }
    T ele;
    BinaryNode *left;
    BinaryNode *right;
    };
public:
    BinarySearchTree()
    {
        root = nullptr;
        cout << "二叉树构造函数,根节点赋值为空指针" << endl;
    }

    ~BinarySearchTree()
    {
        cout << "二叉树析构函数,删除树创建时开辟的空间" << endl;
    }

    void insert (const T &x) {insert (x, root);}

    bool empty( ) const {return root == nullptr;}

    void printXianTree()
    {
        printXianTree(root);
        cout << endl;
        cout << "先序打印二叉树" << endl;
    }

    void printHouTree()
    {
        printHouTree(root);
        cout << endl;
        cout << "后序打印二叉树" << endl;
    }

    void printZhongTree()
    {
        printZhongTree(root);
        cout << endl;
        cout << "中序打印二叉树" << endl;
    }


private:
    void insert(const T&x, BinaryNode *&t)
    {
        if (t == nullptr)
            t = new BinaryNode(x, nullptr, nullptr);
        else if (x < t->ele)
            insert(x, t->left);
        else if (x > t->ele)
            insert(x, t->right);
        else
            ;//todo
    }

//先序打印
    void printXianTree(BinaryNode *t)
    {
        if (t == nullptr)
            return;
        cout << t->ele << ";";
        printXianTree(t->left);
        printXianTree(t->right);
    }

//后序打印
    void printHouTree(BinaryNode *t)
    {
        if(t==nullptr)
            return;
        printHouTree(t->left);
        printHouTree(t->right);
        cout << t->ele << ";";
    }

//中序打印
    void printZhongTree(BinaryNode *t)
    {
        if (t==nullptr)
            return;
        printZhongTree(t->left);
        cout << t->ele << ";";
        printZhongTree(t->right);
    }

private:
    BinaryNode *root;
};
