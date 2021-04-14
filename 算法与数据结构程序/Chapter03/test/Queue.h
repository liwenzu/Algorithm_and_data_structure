#pragma once
#include <iostream>
#include <vector>
//#include <stdexcept>
//#include <stddef.h>
using namespace std;

template <class T>
class ArrQueue {
public:
    ArrQueue(int size=16)
    {
        maxSize = size;
        front = 0;
        rear = 0;
        theArry.resize(maxSize);
        cout << "顺序队列的创建, 队列最大容量为:"<< maxSize << endl;
    }

    ArrQueue(const ArrQueue & rhs)
    {
        maxSize = 16;
        front = 0;
        rear = 0;
        theArry.resize(maxSize);
        cout << "顺序队列的创建(拷贝构造函数), 队列最大容量为:"<< maxSize << endl;
        operator=(rhs);
    }

    ~ArrQueue()
    {
        clear();
        cout << "顺序队列的删除" << endl;
    }

    ArrQueue &operator=(const ArrQueue &rhs)
    {
        clear();
        front = rhs.front;
        rear = rhs.rear;
        maxSize = rhs.maxSize;
        theArry.resize(maxSize);
        for (int i=0;i<maxSize;i++)
            theArry[i]=rhs.theArry[i];
        return *this;
    }

    void enqueue(const T &element)
    {
        if (!full())
        {
            theArry[rear] = element;
            rear = (rear+1)%maxSize;
        }
    }

    T &headQueue()
    {
        return theArry[front];
    }

    T const &headQueue() const
    {
        return theArry[front];
    }

    T dequeue()
    {
//        T element;
//        if(!empty())
//        {
            T element = theArry[front];
            front = (front+1)%maxSize;
            return element;
//        }
//        return element;
    }

    void clear()
    {
        while (!empty())
            dequeue();
    }

    int length()
    {
        return (rear - front + maxSize)%maxSize;
    }

    bool empty() const {return front == rear;}

    bool full() const {return (rear+1)%maxSize == front;}

private:
    int front, rear;
    int maxSize;
    vector<T> theArry;
};

template <class T>
class LinkQueue
{
public:
    LinkQueue()
    {
        front = nullptr;
        rear = nullptr;
        length = 0;
        cout << "链队列的初始化(构造函数)" << endl;
    }

    LinkQueue(const LinkQueue &rhs)
    {
        cout << "链队列的初始化(拷贝构造函数)" << endl;
        front = nullptr;
        rear = nullptr;
        length = 0;
        operator=(rhs);
    }

    ~LinkQueue()
    {
        clear();
        cout << "链队列的销毁(析构函数)" << endl;
    }

    LinkQueue &operator=(const LinkQueue &rhs)
    {
        clear();
        Node *src = rhs.front;
        while (src != nullptr)
        {
            enqueue(src->data);
            src = src->next;
        }
        return *this;
    }

    void enqueue(const T &element)
    {
        Node *ptr = new Node(element);
        if (rear != nullptr)
        {
            rear->next = ptr;
            rear = ptr;
        }
        else
            front = rear = ptr;
        length++;
    }

    T dequeue()
    {
        T tmp = front->data;
        Node *ptr = front;
        if (front->next == nullptr)
            front = rear = nullptr;
        else
            front = front->next;
        delete ptr;
        length--;
        return tmp;
    }

    T &headQueu()
    {
        return front->data;
    }

    int size() const
    {
        return length;
    }

    void clear()
    {
        while (front != nullptr)
            dequeue();
    }
private:
    struct Node {
    Node(const T &d=T(), Node *p = nullptr): data(d), next(p)
    {}
    T data;
    Node *next;
    };
    Node *front;
    Node *rear;
    int length;
};

