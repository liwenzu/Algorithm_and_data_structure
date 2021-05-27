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
        makeEmpty();
    }

    AVLTree(const AVLTree &rhs)
    {
        root = nullptr;
        operator=(rhs);
        cout << "拷贝构造函数" << endl;
    }

    AVLTree &operator=(const AVLTree &rhs)
    {
//        cout << "等号运算符重载" << endl;
        makeEmpty();
        root = clone(rhs.root);
        return *this;
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

    bool empty() const
    {
        return root == nullptr;
    }

    const T &findMin()
    {
        return findMin(root)->ele;
    }

    const T &findMax()
    {
        return findMax(root)->ele;
    }

    void makeEmpty()
    {
        makeEmpty(root);
    }

    bool contains(const T&x)
    {
        return contains(x, root);
    }

private:
    AVLNode *clone(AVLNode *t) const
    {
        if (t == nullptr)
            return nullptr;
        return new AVLNode(t->ele, clone(t->left), clone(t->right), t->height);
    }

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

    AVLNode *findMin(AVLNode *t)
    {
        if (t==nullptr)
            return nullptr;
        if (t->left == nullptr)
            return t;
        return findMin(t->left);
    }

    AVLNode *findMax(AVLNode *t)
    {
        if (t==nullptr)
            return nullptr;
        if (t->right==nullptr)
            return t;
        return findMax(t->right);
    }

    void makeEmpty(AVLNode *&t)
    {
        if (t!=nullptr)
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        t = nullptr;
    }

    bool contains(const T&x, AVLNode *t)
    {
        if (t==nullptr)
            return false;
        else if (t->ele == x)
            return true;
        else if (t->ele > x )
            return contains(x, t->left);
        else
            return contains(x, t->right);
    }

private:
    AVLNode *root;
};
