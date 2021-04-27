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

    BinarySearchTree(const BinarySearchTree &rhs)
    {
        root = nullptr;
        operator=(rhs);
    }

    ~BinarySearchTree()
    {
        makeEmpty();
        cout << "��������������,ɾ��������ʱ���ٵĿռ�" << endl;
    }

    BinarySearchTree &operator=(const BinarySearchTree &rhs)
    {
        makeEmpty();
        root = clone(rhs.root);
        return *this;
    }

    void insert (const T &x) {insert (x, root);}

    void xianInsert()
    {
        //ʹ���������д���������
        xianInsert(root);
    }

    bool empty( ) const {return root == nullptr;}

    void makeEmpty()
    {
        makeEmpty(root);
    }

    const T &findMin() const
    {
        return findMin(root)->ele;
    }

    const T &findMax() const
    {
        return findMax(root)->ele;
    }

    bool contains(const T &x) const
    {
        return contains(x, root);
    }



    void printTree() const
    {
        printTree(root);
        cout << "Ĭ���������" << endl;
    }

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

    void remove(const T &x)
    {
        remove(x, root);
    }

    int treeDepth()
    {
        return treeDepth(root);
    }

    int nodeCount()
    {
        return nodeCount(root);
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

    void printDepth(const T &x, int depth = 0) const
    {
        while(depth--)
            cout << "\t";
        cout << "[" << x << "]" << endl;
    }

    void printTree(BinaryNode *t, int depth=0) const
    {
        if (t==nullptr)
            return;

        printDepth(t->ele, depth);

        printTree(t->left, depth+1);

//        printDepth(t->ele, depth);

        printTree(t->right, depth+1);
    }

//ʹ�ú������ɾ��
    void makeEmpty(BinaryNode *&t)
    {
        if (t != nullptr)
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
//���ڷ�ֹҰָ��
        t = nullptr;
    }

//�����ӣ���Ϊ���ǰ�����С���Ҵ�����
    BinaryNode *findMin(BinaryNode *t) const
    {
        if (t == nullptr)
            return nullptr;
        if (t->left == nullptr)
            return t;
        return findMin(t->left);
    }

    BinaryNode *findMax(BinaryNode *t) const
    {
        if (t==nullptr)
            return nullptr;
        if (t->right == nullptr)
            return t;
        return findMax(t->right);
    }

    bool contains(const T &x, BinaryNode *t) const
    {
        if (t==nullptr)
            return false;
        else if (t->ele > x)
            return contains(x, t->left);
        else if (t->ele < x)
            return contains(x, t->right);
        else
            return true;
    }

//�����ر���Ϥ
    void remove(const T &x, BinaryNode *&t)
    {
        if (t==nullptr)
            ;//todo
        if (x < t->ele)
            remove(x, t->left);
        else if (x > t->ele)
            remove(x, t->right);
        else if (t->left != nullptr && t->right != nullptr)
        {
            t->ele = findMin(t->right)->ele;//ʹ�õ�ǰ�ڵ���������Сֵ���浱ǰֵ
            remove(t->ele, t->right);//ɾ���������е���Сֵ
        }
        else
        {
            BinaryNode *old = t;
            t = (t->left != nullptr) ? t->left : t->right;
            delete old;
        }
    }

    BinaryNode *clone(BinaryNode *t) const
    {
        if (t == nullptr)
            return nullptr;
        return new BinaryNode(t->ele, clone(t->left), clone(t->right));
    }

    int treeDepth(BinaryNode *t)
    {
        if (t == nullptr)
            return 0;
        int m = treeDepth(t->left);
        int n = treeDepth(t->right);
        return max(m,n)+1;
    }

    int nodeCount(BinaryNode *t)
    {
        if (t==nullptr)
            return 0;
        return nodeCount(t->left)+nodeCount(t->right)+1;
    }

    void xianInsert(BinaryNode *&t)
    {
        T input;
        cout << "�����룬��Ҫ�����Ԫ�أ������ǰ�ڵ�û���ӽڵ�������-1" << endl;
        cin >> input;
        if (input == -1)
            t = nullptr;
        else{
            t = new BinaryNode(input, nullptr, nullptr);
            xianInsert(t->left);
            xianInsert(t->right);
        }
    }

private:
    BinaryNode *root;
};
