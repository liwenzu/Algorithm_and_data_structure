#include <iostream>
#include "keyvector.h"
#include "List.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

class NodeData{
public:

    bool operator==(const NodeData & rhs)
    {
        if (m_number == rhs.m_number && m_name == rhs.m_name && m_age == rhs.m_age)
            return true;
        return false;
    }
    string m_number;
    string m_name;
    int m_age;
};


void tes1()
{
    NodeData elem1,elem2,elem3;
    elem1.m_number="123";
    elem1.m_name="liwenzu";
    elem1.m_age=20;

    elem2.m_number="456";
    elem2.m_name="liwenzu1";
    elem2.m_age=23;

    elem3.m_number="789";
    elem3.m_name="liwenzu2";
    elem3.m_age=26;

    keyVector<NodeData> dp;
    dp.push_back(elem1);
    dp.push_back(elem2);
    dp.push_back(elem2);

    for (int i=0; i<dp.size();i++)
        cout << dp[i].m_number << ":" << dp[i].m_name << ":" << dp[i].m_age <<endl;

    cout << dp.find(elem1) << endl;

}

void test()
{
    keyVector<int> key(5);
//    if (key.empty())     cout << "向量为空" << endl;
    cout << "向量实际大小:" << key.size() << endl;
    cout << "向量大总小为:" << key.capacity() << endl;

    for (int i=0; i<key.size();i++)
        key[i] = 0;

    key.push_back(100);
    key[2]=40;

//    key.clear();
//    key.pop_back();
//    key.insert(1,30);
//    key.erase(5);



    cout << "向量实际大小:" << key.size() << endl;
    cout << "向量大总小为:" << key.capacity() << endl;

    for (int i=0; i<key.size();i++)
        cout << key[i] <<endl;

//    key.back() = 200;

//    *key.begin()=200;
//    *key.end()=1200;

    cout << "第一个元素为:" << key.front() << endl;
    cout << "最后一个元素为:" << key.back() << endl;
    cout << "第一个元素地址为:" << key.begin() << endl;
    cout << "最后一个元素为:" << key.end() << endl;
//    keyVector<int> key1(key);
//
//    cout << "--------------------" <<endl;
//
//    cout << "向量实际大小:" << key1.size() << endl;
//    cout << "向量大总小为:" << key1.capacity() << endl;
//
//    for (int i=0; i<key1.size();i++)
//        cout << key1[i] <<endl;
//
//    keyVector<int> key2 = key;
//
//    cout << "*********************" <<endl;
//
//    cout << "向量实际大小:" << key2.size() << endl;
//    cout << "向量大总小为:" << key2.capacity() << endl;
//
//    for (int i=0; i<key2.size();i++)
//        cout << key2[i] <<endl;

}

void signleTest()
{
    SingleList<int> list;
    for(int i=5;i>=0;i--)
        list.add(i);

    list.print();
    cout << "链表的大小为" << list.size() << endl;


//    cout << "链表的i个位置元素为" << list[5] << endl;
//    list[5]=15;
//    cout << "链表的i个位置元素为" << list[5] << endl;

//    list.remove(3);

    SingleList<int> list1(list);

    list1.print();
    cout << "链表的大小为" << list1.size() << endl;
}

void doubleList()
{
    List<int> dlist;

//    if(dlist.empty())
    cout << "链表的大小为:"  << dlist.size() << endl;
    for (int i=0; i<6;i++)
        dlist.push_back(i);
    cout << "链表的大小为:"  << dlist.size() << endl;
    int a=20;
    for (List<int>::iterator it=dlist.begin();it!=dlist.end();++it)
    {
        cout << *(it) << endl;
        *(it)=a++;
    }
//        cout << dlist.back() << endl;

//    dlist.erase(dlist.begin(), dlist.end());


    cout << "-----------------" << endl;
    for (List<int>::const_iterator it=dlist.begin();it!=dlist.end();++it)
    {
        cout << *(it) << endl;
    }

}

void stackTest()
{
    ArrStack<int> stackE;
//    if(stackE.empty())
//        cout << "----------" << endl;
    for (int i=0;i<20;i++)
        stackE.push(i+100);

    cout << "栈的容量大小为:" << stackE.size() << endl;

    cout << "栈顶的元素为:" << stackE.top() << endl;
//    stackE.top() = 300;
//    cout << "栈顶的元素为:" << stackE.top() << endl;
//    while(!stackE.empty())
//        cout << stackE.pop() << endl;
//    stackE.clear();

//    cout << "栈的容量大小为:" << stackE.size() << endl;



//    ArrStack<int> stackE1=stackE;
    ArrStack<int> stackE1(stackE);

    while(!stackE1.empty())
        cout << stackE1.pop() << endl;
}

void stackList()
{
    LinkStack<int> linStack;
    for(int i=0; i<5; i++)
        linStack.push(20+i);
    if (linStack.empty())
        cout << "链栈为空" << endl;
    cout << "链栈的大小为:" << linStack.size() << endl;

//    linStack.top()=60;
//    linStack.const_top()=60;

//    cout << "链栈的顶层元素为:" << linStack.top() << endl;


//    while(!linStack.empty())
//    {
//        cout << linStack.top() << endl;
//        linStack.pop();
//    }
//    cout << "链栈的大小为:" << linStack.size() << endl;

    cout << "--------------------------" << endl;

//    LinkStack<int> linStack1 = linStack;

    LinkStack<int> linStack1 = linStack;
    cout << "第二个链栈的大小为:" << linStack1.size() << endl;
    while(!linStack1.empty())
    {
        cout << linStack1.top() << endl;
        linStack1.pop();
    }
    cout << "第二个链栈的大小为:" << linStack1.size() << endl;



}

//顺序队列测试的例子
void arrque()
{
    ArrQueue<int> queueT;
     for (int i=0;i<5;i++)
        queueT.enqueue(i*i);


    if (queueT.empty())
        cout << "队列为空" << endl;

    cout << "队列的长度为:" << queueT.length() << endl;


//    while (!queueT.empty())
//        cout << queueT.dequeue() << endl;

    cout << "队头元素为:" << queueT.headQueue() << endl;

    queueT.headQueue() = 10;

    cout << "队头元素为:" << queueT.headQueue() << endl;

    cout << "队列的长度为:" << queueT.length() << endl;


//    ArrQueue<int> queueT1 = queueT;
      ArrQueue<int> queueT1;
//    ArrQueue<int> queueT1(queueT);
      queueT1 = queueT;


    while (!queueT.empty())
        cout << queueT.dequeue() << endl;
}

//链表形式队列的创建
void listque()
{
    LinkQueue<int> queueT;

    for (int i=2; i<7;i++)
        queueT.enqueue(i*i);

    cout << "链队列的长度为:" << queueT.size() << endl;

//    queueT.headQueu()=20;
//
//    cout << "队列的头数据为:" << queueT.headQueu() << endl;

//    while (queueT.size() !=0)
//        cout << queueT.dequeue() << endl;

    LinkQueue<int> queueT1(queueT);
//    queueT1 = queueT;

    cout << "链队列的长度为:" << queueT1.size() << endl;

    while (queueT1.size() !=0)
        cout << queueT1.dequeue() << endl;


    cout << "链队列的长度为:" << queueT1.size() << endl;

}

int main()
{

//    test();
//    tes1();
//    signleTest();
//    doubleList();
//    stackTest();
//    stackList();
//    arrque();
    listque();

    cout << "Hello world!" << endl;
    return 0;
}
