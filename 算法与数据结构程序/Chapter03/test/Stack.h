#pragma once
#include <iostream>
//#include <stdexcept>
//#include <stddef.h>
using namespace std;

template <class T>
class ArrStack{
    enum {SPARE_CAPACITY = 16};
public:
    explicit ArrStack(int initSize=0)
    {
        topOfStack = -1;
        theCapacity = SPARE_CAPACITY + initSize;
        theArry = new T[theCapacity];
        cout << "顺序结构栈初始化，容量为:" << size() << endl;
    }

    ArrStack(ArrStack &rhs)
    {
        theArry = nullptr;
        operator=(rhs);
    }

    ~ArrStack()
    {
        delete[] theArry;
        cout << "顺序栈的删除" << endl;
    }

    ArrStack &operator=(const ArrStack &rhs)
    {
//        if(this != rhs)
  //      {
            delete[] theArry;
            topOfStack = rhs.topOfStack;
            theCapacity = rhs.theCapacity;

            theArry = new T[theCapacity];
            for (int i=0;i<size();i++)
                theArry[i]=rhs.theArry[i];
//        }
        return *this;
    }

    void push(const T &element)
    {
        if(++topOfStack == theCapacity)
        {
            cout << "栈已满" << endl;
            reserve(2*theCapacity+1);
        }

        theArry[topOfStack] = element;
    }

    T &pop()
    {
        return theArry[topOfStack--];
    }

    const T &const_pop()
    {
        return theArry[topOfStack--];
    }

    T &top()
    {
//        cout << "------no const" << endl;
        return theArry[topOfStack];
    }

    const T &top() const
    {
//        cout << "------const" << endl;
        return theArry[topOfStack];
    }

    int size() const {return topOfStack+1;}

    bool empty() const {return topOfStack == -1;}

    void clear()
    {
        while(!empty())
            pop();
    }

private:
    int topOfStack;
    int theCapacity;
    T *theArry;
    void reserve(int newCapacity)
    {
        T *oldArry = theArry;
        theArry = new T[newCapacity];
        for (int i=0;i<size();i++)
            theArry[i] = oldArry[i];
        theCapacity = newCapacity;
        delete[] oldArry;
        cout << "栈容量扩展函数" << endl;
    }
};


template <class T>
class LinkStack{
private:
    struct Node{
        Node(const T &d=T(), Node *n=nullptr)
        {
            data = d;
            next = n;
        }
        T data;
        Node *next;
    };
public:
    LinkStack()
    {
        stackSize = 0;
        head = nullptr;
        cout << "链栈对象创建，以及构造函数调用!" << endl;
    }

    LinkStack(const LinkStack &rhs)
    {
        stackSize=0;
        head=nullptr;
        operator=(rhs);
    }

    ~LinkStack()
    {
        clear();
        cout << "链栈对象释放，内存空间释放!" << endl;
    }

    LinkStack &operator=(const LinkStack &rhs)
    {
        clear();
        Node *src = rhs.head;
        while(src != nullptr)
        {
            push(src->data);
            src = src->next;
        }
        return *this;
    }

    void push(const T &element)
    {
        Node *ptr = new Node(element, head);
        head = ptr;
        stackSize++;
    }

    T &top()
    {
        return head->data;
    }

    const T &top() const
    {
        return head->data;
    }

    void pop()
    {
          Node *ptr = head->next;
          delete head;
          head = ptr;
          stackSize--;
    }

    void clear()
    {
        while(!empty())
            pop();
    }

    bool empty() const {return stackSize == 0;}

    int size() const {return stackSize;}

private:
    int stackSize;
    Node *head;
};


















