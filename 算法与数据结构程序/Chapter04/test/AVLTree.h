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

    void insertAVL(const T &x)
    {
        insertAVL(x, root);
    }

    void printTreeAVL()
    {
        printTreeAVL(root);
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

    void remove(const T&x)
    {
        remove(x, root);
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

    void rotateLL(AVLNode *&k2)
    {
        AVLNode *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = max(height(k2->left), height(k2->right))+1;
        k1->height = max(height(k1->left), k2->height)+1;
        k2 = k1;
    }

    void rotateLR(AVLNode *&k3)
    {
        AVLNode *k1 = k3->left;
        AVLNode *k2 = k1->right;

        k1->right = k2->left;
        k3->left = k2->right;
        k2->left = k1;
        k2->right = k3;
        k1->height = max(height(k1->left), height(k1->right))+1;
        k3->height = max(height(k3->left), height(k3->right))+1;
        k2->height = max(k1->height, k3->height)+1;
        k3 = k2;
    }

    void rotateRR(AVLNode *&k1)
    {
        AVLNode *k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1->height = max(height(k1->left), height(k1->right))+1;
        k2->height = max(k1->height, height(k2->right))+1;
        k1 = k2;
    }

    void rotateRL(AVLNode *&k1)
    {
        AVLNode *k3 = k1->right;
        AVLNode *k2 = k3->left;
        k1->right = k2->left;
        k3->left = k2->right;
        k2->left = k1;
        k2->right = k3;
        k1->height = max(height(k1->left), height(k1->right))+1;
        k3->height = max(height(k3->left), height(k3->right))+1;
        k2->height = max(k1->height, k3->height)+1;
        k1 = k2;
    }

    void insertAVL(const T &x, AVLNode *&t)
    {
        if(t == nullptr)
            t = new AVLNode(x, nullptr, nullptr);
        else if (x < t->ele)
        {
            insert(x, t->left);
            if (height(t->left)-height(t->right)==2)
            {
                if (x<t->left->ele)
                    rotateLL(t);
                else
                    rotateLR(t);
            }
        }
        else if (x > t->ele)
        {
            insert(x, t->right);
            if (height(t->right) - height(t->left) == 2)
            {
                if (x>t->right->ele)
                    rotateRR(t);
                else
                    rotateRL(t);
            }
        }
        else
            ;//TODO
        t->height = max(height(t->left), height(t->right))+1;
    }

    void printDepth(const T&x, int depth=0) const
    {
        while (depth--)
            cout << "\t";
        cout << "[" << x << "]" << endl;
    }

    void printTreeAVL(AVLNode *t, int depth=0)
    {
        if (t==nullptr)
            return;
        printTreeAVL(t->left, depth+1);
        printDepth(t->ele, depth);
        printTreeAVL(t->right, depth+1);
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

    void remove(const T &x, AVLNode *&t)
    {
        if (t==nullptr)
            return;
        if (x<t->ele)
        {
            remove(x, t->left);

            t->height = max(height(t->left), height(t->right))+1;

            if(height(t->right)-height(t->left)==2)
            {
                if(height(t->right->right)>=height(t->right->left))
                    rotateRR(t);
                else
                    rotateRL(t);
            }
        }
        else if (x>t->ele)
        {
            remove(x, t->right);
            t->height = max(height(t->left), height(t->right))+1;
            if (height(t->left)-height(t->right) == 2)
            {
                if (height(t->left->left) >= height(t->left->right))
                    rotateLL(t);
                else
                    rotateLR(t);
            }
        }
        else if (t->left != nullptr && t->right != nullptr)
        {
            t->ele = findMin(t->right)->ele;
            remove(t->ele, t->right);
            t->height = max(height(t->left), height(t->right))+1;
            if (height(t->left)-height(t->right) == 2)
            {
                if (height(t->left->left) >= height(t->left->right))
                    rotateLL(t);
                else
                    rotateLR(t);
            }
        }
        else
        {
            AVLNode *old = t;
            t = (t->left != nullptr)? t->left: t->right;
            delete old;
        }
    }

private:
    AVLNode *root;
};
