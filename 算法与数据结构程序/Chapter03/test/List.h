#pragma once
#include <iostream>
#include <stdexcept>
#include <stddef.h>
using namespace std;


//�������ʵ�ַ���
template <class T>
class SingleList
{
private:
    struct Node
    {
        Node(const T &d = T(), Node *n = nullptr)
        {
            data = d;
            next = n;
        }
        T data;
        Node *next;
    };
    Node *head;
    int theSize;

    void init()
    {
        theSize=0;
        head = new Node();
        head->next = nullptr;
    }

public:
    SingleList()
    {
        init();
        cout << "���ù��캯������ʼ�����б������ʼ����СΪ: " << theSize << endl;
    }

//�������캯��
    SingleList(const SingleList & rhs)
    {
        operator=(rhs);
    }

    ~SingleList()
    {
        eraseList(head);
        cout << "���õ����������������ͷŵ�����" << endl;
    }

//ͷ�巨
    bool add(T &element)
    {
        if (contains(element))
            return false;
        else{
            Node *ptr = new Node(element);
            ptr->next = head->next;
            head->next = ptr;
            ++theSize;
        }
        return true;
    }

    bool contains(const T &element)
    {
        Node *ptr = head->next;
        while(ptr!=nullptr)
        {
            if (ptr->data == element)
                return true;
            ptr = ptr->next;
        }
        return false;
    }

    int size() const {return theSize;}

//��ӡ����
    void print()
    {
        Node *ptr = head->next;
        while(ptr!=nullptr)
        {
            cout << ptr->data << endl;
            ptr = ptr->next;
        }
    }

//ɾ������
    void eraseList(Node *L)
    {
        Node *ptr = L;
        Node *nextPtr=nullptr;
        while(ptr!=nullptr)
        {
            nextPtr = ptr->next;
            delete ptr;
            ptr = nextPtr;
        }
    }

//���������[]
    T &operator[](int index)
    {
        if(index<0 || index>size()-1)
            throw std::runtime_error("index out of bounds");
        else
        {
            Node *ptr=head->next;
            while(index)
            {
                ptr = ptr->next;
                index--;
            }
            return ptr->data;
        }
    }

    bool remove(const T &element)
    {
        if(!contains(element))
            return false;
        else
        {
            Node *ptr = head->next;
            Node *lastPtr = nullptr;
            while(element!=ptr->data)
            {
                lastPtr = ptr;
                ptr = ptr->next;
            }
            lastPtr->next = ptr->next;
            delete ptr;
            --theSize;
            return true;
        }
    }

    SingleList &operator=(const SingleList & rhs)
    {
//        eraseList(head);
        delete head;
        init();
        Node *ptr = rhs.head->next;
        while(ptr!=nullptr)
        {
            add(ptr->data);
            ptr = ptr->next;
        }
        theSize = rhs.size();
        return *this;
    }
};


//˫�������ʵ�ֹ���
template <class Object>
class List{
private:
    struct Node{
        Node(const Object &d = Object(), Node *p = nullptr, Node *n = nullptr)
        {
            data = d;
            prev = p;
            next = n;
        }
        Object data;
        Node *prev;
        Node *next;
    };
    int theSize;
    Node *head;
    Node *tail;

    void init()
    {
        theSize=0;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
public:

//����������ʵ����
class const_iterator{
    public:
        const_iterator() : theList(nullptr), current(nullptr) { }
        const Object &operator*() const { return retrieve(); }
        const_iterator &operator++()
        {
            current = current->next;
            return *this;
        }

        const_iterator &operator++(int)
        {
            const_iterator old = *this;
            ++(*this);
            return old;
        }

        const_iterator &operator--()
        {
            current = current->prev;
            return *this;
        }

        const_iterator &operator--(int)
        {
            const_iterator old = *this;
            --(*this);
            return old;
        }

        bool operator==(const const_iterator &rhs) const
        {
            return current == rhs.current;
        }

        bool operator!=(const const_iterator &rhs) const
        {
            return !(*this == rhs);
        }

    protected:
        friend class List<Object>;
        const List<Object> *theList;
        const_iterator(const List<Object> &lst, Node *p) : theList(&lst), current(p) {}
        Node *current;
        Object &retrieve() const { return current->data; }
        void assertIsValid() const
        {
            if (theList == nullptr || current == nullptr || theList->head == current)
                throw std::runtime_error("Iterator out of bounds.");
        }
    };
//��ͨ������ʵ����
class iterator: public const_iterator {
    public:
        iterator(){}

        Object &operator*() { return const_iterator::retrieve(); }
        const Object &operator*() const { return const_iterator::operator*(); }

        iterator &operator++()
        {
            const_iterator::current = const_iterator::current->next;
            return *this;
        }

        iterator &operator++(int)
        {
            iterator old = *this;
            ++(*this);
            return old;
        }
        iterator &operator--()
        {
            const_iterator::current = const_iterator::current->prev;
            return *this;
        }
        iterator &operator--(int)
        {
            iterator old = *this;
            --(*this);
            return old;
        }

        bool operator==(const iterator &rhs) const
        {
            return const_iterator::current == rhs.current;
        }
        bool operator!=(const iterator &rhs) const
        {
            return !(*this == rhs);
        }
    protected:
        friend class List<Object>;
        iterator(const List<Object> &lst, Node *p) : const_iterator(lst, p) { }
};

//˫������������ʵ�ֲ���
public:
    List()
    {
        init();
        cout << "˫������Ĺ��캯����˫������ĳ�ʼ��СΪ:" << theSize << endl;
    }

    List(const List &rhs)
    {
        init();
        *this = rhs;
    }

    ~List()
    {
        cout << "˫�����������������ɾ�������Ķ���" << endl;
    }

    int size() const {return theSize;}

    bool empty() const {return theSize==0;}


    List &operator=(const List &rhs)
    {
        if (this == &rhs)
            return *this;
        clear();
        for (const_iterator itr = rhs.begin(); itr != rhs.end(); ++itr)
            push_back(*itr);
        return *this;
    }

    iterator insert(iterator itr, const Object &x)
    {
        itr.assertIsValid();
        if (itr.theList != this)
            throw std::logic_error("Iterator mismatch.");

        Node *p = itr.current;
        ++theSize;
        return iterator(*this, p->prev = p->prev->next = new Node(x, p->prev, p));
    }

    iterator erase(iterator itr)
    {
        itr.assertIsValid();
        if (itr.theList != this)
            throw std::logic_error("Iterator mismatch.");
        Node *p = itr.current;
        iterator retVal(*itr.theList, p->next);
//ɾ���굱ǰ�ڵ㣬��ָ����һ���ڵ�
        p->prev->next = p->next;
        p->next->prev = p->prev;
        --theSize;
 //�����������������Ҫɾ��
        delete p;
        return retVal;
    }

    iterator erase(iterator start, iterator end)
    {
        start.assertIsValid();
        if (start.theList != this)
            throw std::logic_error("Iterator mismatch.");

        end.assertIsValid();
        if (end.theList != this)
            throw std::logic_error("Iterator mismatch.");

        iterator itr = start;
        while (itr != end)
            itr = erase(itr);
        return end;
    }

    void clear()
    {
        while (!empty())
            pop_front();
    }

    Object &front() {return *begin();}
    const Object &front() const {return *begin();}
    Object &back() {return *--end();}
    const Object &back() const{return *--end();}

    void push_front(const Object &element) {insert(begin(),element);}
    void push_back(const Object &element) {insert(end(), element);}

    void pop_front() {erase(begin());}
    void pop_back() {erase(--end());}

    iterator begin() {return iterator(*this, head->next);}
    const_iterator begin() const {return const_iterator(*this, head->next);}
    iterator end() {return iterator(*this, tail);}
    const_iterator end() const {return const_iterator(*this, tail);}
};



