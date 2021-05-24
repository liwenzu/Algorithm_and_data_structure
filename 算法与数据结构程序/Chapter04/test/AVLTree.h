#pragma once
#include <iostream>
//#define nullptr NULL

using namespace std;

template<class T>
class AVLTree{
private:
    struct AVLNode{
        AVLNode(const T &element, AVLNode *lt, AVLNode *rt, int h=0)
        {
            ele = element;
            left = lt;
            right = rt;
            height = h;
        }
        T ele;
        AVLNode *left;
        AVLNode *right;
        int height;
    };

public:
    AVLTree()
    {
        cout << "平衡二叉树的构造函数" << endl;
        root = nullptr;
    }

    ~AVLTree()
    {
        cout << "平衡二叉树的析构函数" << endl;
    }


    void insert(const T &x)
    {
        insert(x, root);
    }

    void printTree()
    {
        printTree(root);
        cout <<endl;
    }

private:
    int height(AVLNode *t) const
    {
        return t==nullptr? -1: t->height;
    }

    void insert(const T &x, AVLNode *&t)
    {
        if(t == nullptr)
            t = new AVLNode(x, nullptr, nullptr);
        else if (x < t->ele)
        {
            insert(x, t->left);
        }
        else if (x > t->ele)
        {
            insert(x, t->right);
        }
        else
            ;//TODO
        t->height = max(height(t->left), height(t->right))+1;
    }

    void printTree(AVLNode *t)
    {
        if (t==nullptr)
            return;
        printTree(t->left);
        cout << t->ele << ":" << t->height <<endl;
        printTree(t->right);
    }


private:
    AVLNode *root;
};
