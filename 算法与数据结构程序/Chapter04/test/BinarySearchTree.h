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
        cout << "���������캯��,���ڵ㸳ֵΪ��ָ��" << endl;
    }

    ~BinarySearchTree()
    {
        cout << "��������������,ɾ��������ʱ���ٵĿռ�" << endl;
    }

    void insert (const T &x) {insert (x, root);}

    bool empty( ) const {return root == nullptr;}

    void printXianTree()
    {
        printXianTree(root);
        cout << endl;
        cout << "�����ӡ������" << endl;
    }

    void printHouTree()
    {
        printHouTree(root);
        cout << endl;
        cout << "�����ӡ������" << endl;
    }

    void printZhongTree()
    {
        printZhongTree(root);
        cout << endl;
        cout << "�����ӡ������" << endl;
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

//�����ӡ
    void printXianTree(BinaryNode *t)
    {
        if (t == nullptr)
            return;
        cout << t->ele << ";";
        printXianTree(t->left);
        printXianTree(t->right);
    }

//�����ӡ
    void printHouTree(BinaryNode *t)
    {
        if(t==nullptr)
            return;
        printHouTree(t->left);
        printHouTree(t->right);
        cout << t->ele << ";";
    }

//�����ӡ
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
