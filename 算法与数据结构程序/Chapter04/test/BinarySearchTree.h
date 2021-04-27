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

    BinarySearchTree(const BinarySearchTree &rhs)
    {
        root = nullptr;
        operator=(rhs);
    }

    ~BinarySearchTree()
    {
        makeEmpty();
        cout << "二叉树析构函数,删除树创建时开辟的空间" << endl;
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
        //使用先序序列创建二叉树
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
        cout << "默认先序遍历" << endl;
    }

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

//使用后序遍历删除
    void makeEmpty(BinaryNode *&t)
    {
        if (t != nullptr)
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
//用于防止野指针
        t = nullptr;
    }

//找左孩子，因为树是按照左小，右大建立的
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

//不是特别熟悉
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
            t->ele = findMin(t->right)->ele;//使用当前节点右子树最小值代替当前值
            remove(t->ele, t->right);//删除右子树中的最小值
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
        cout << "请输入，需要插入的元素，如果当前节点没孩子节点则输入-1" << endl;
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
