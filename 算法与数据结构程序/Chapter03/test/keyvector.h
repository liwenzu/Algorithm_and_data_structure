#pragma once
#include <iostream>
#include <stdexcept>
#include <stddef.h>
using namespace std;

#define nullptr NULL

template <class Object>
class keyVector {
    enum {SPARE_CAPACITY = 16};
    typedef Object *iterator;
    typedef const Object *const_iterator;
public:
    explicit keyVector(int initSize=0)
    {
        cout << "��������,��СΪ:" << initSize << endl;
        theSize = initSize;
        theCapacity=initSize+SPARE_CAPACITY;
        objects = new Object[theCapacity];
    }

    keyVector(const keyVector &rhs)
    {
        objects = nullptr;
        operator=(rhs);
    }

    ~keyVector()
    {
        cout << "�����ռ��ͷ�" << endl;
        delete [] objects;
    }

    keyVector &operator=(const keyVector &rhs)
    {
//        if (this != rhs)
//        {
            delete [] objects;
            theSize = rhs.theSize;
            theCapacity = rhs.theCapacity;
            objects = new Object[theCapacity];
            for(int i=0; i<size();i++)
                objects[i]=rhs.objects[i];
            return *this;
//        }
    }

//�ж������Ƿ�Ϊ��
    bool empty() const {return theSize==0;}

    int size() const {return theSize;}

    int capacity() const {return theCapacity;}

    void clear() {theSize=0;}

//����ָ����С
    void resie(int newSize)
    {
        if (newSize > theCapacity)
            reserve(newSize*2+1);
        theSize=newSize;
    }

    void reserve(int newCapacity)
    {
        if(newCapacity<theSize)
            return;
        Object *oldArry = objects;
        objects = new Object[newCapacity];
        for (int i=0;i<theSize;i++)
            objects[i] = oldArry[i];
        theCapacity=newCapacity;
        delete [] oldArry;
    }

    void push_back(const Object &element)
    {
        if(theSize==theCapacity)
            reserve(2*theCapacity+1);
        objects[theSize++]=element;
    }

    void pop_back() {--theSize;}

//����ָ����Ԫ�أ������ض�Ӧ��λ��i+1
    int find(Object element)
    {
        for(int i=0;i<theSize;i++)
            if(objects[i]==element)
                return i+1;
        return size();
    }

//����Ԫ�ص�ָ��λ��
    void insert(int pos, Object element)
    {
        if (pos<0 || pos>=size())
            throw std::runtime_error("index out of bounds");
        if (size()>=theCapacity)
            throw std::runtime_error("can not insert elements");
        for(int i=size();i>=pos;i--)
            objects[i]=objects[i-1];
        objects[pos]=element;
        theSize++;
    }
 //ɾ��ָ��λ�õ�Ԫ��
    void erase(int index)
    {
        if(index<0 || index>=size() || size()==0)
            throw std::runtime_error("index out of bounds");
        for(int i=index;i<size()-1;i++)
            objects[i]=objects[i+1];
        theSize--;
    }


//ȡֵ�����������[],����һ������
    Object &operator[](int index)
    {
        if (index>=0 && index< size())
            return objects[index];
        else
            throw std::runtime_error("index out of bounds");
    }

    const Object &operator[](int index) const
    {
        if (index>=0 && index< size())
            return objects[index];
        else
            throw std::runtime_error("index out of bounds");
    }

    const Object &back() {return objects[theSize-1];}
    const Object &front() {return objects[0];}

    iterator begin() {return &objects[0];}
    const_iterator begin() const { return &objects[0];}
    iterator end() {return &objects[size()];}
    const_iterator end() const { return &objects[size()];}
private:
    int theSize;
    int theCapacity;
    Object *objects;
};
