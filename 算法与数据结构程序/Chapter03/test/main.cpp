#include <iostream>
#include "keyvector.h"

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

int main()
{

    test();
    tes1();

    cout << "Hello world!" << endl;
    return 0;
}
