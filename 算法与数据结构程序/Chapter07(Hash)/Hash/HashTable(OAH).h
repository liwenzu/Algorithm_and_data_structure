#include <iostream>
#include <vector>

using namespace std;

//template <class T>
class HashTable_OAH{

    enum EntryType {ACTIVE, EMPTY, DELETED};

    int primes[24] = {
    53, 97, 193, 389, 769, 1453, 3079, 6151, 12893, 24593, 49157, 98317,
    196613, 393241, 786433, 1572869, 3145739, 6291469, 12582917,
    25165843, 50331653, 100663319, 201326611, -1
    };

    int nextPrime(int n)
    {
        for(int i=0;i<24;i++)
            if(n<primes[i])
                return primes[i];
        return primes[23];
    }

private:
    struct HashEntry {
        HashEntry(const int &e=int(), EntryType i = EMPTY)
        {
            ele = e;
            info = i;
        }
        int ele;
        EntryType info;
    };

public:

    HashTable_OAH() = delete;

    explicit HashTable_OAH(int size)
    {
        cout << "Constructor" << endl;
        curSize = 0;
        arr.resize(size);
        makeEmpty();

//        cout << arr.size() << endl;
    }

    HashTable_OAH(const HashTable_OAH &rhs) { operator=(rhs); }

    ~HashTable_OAH() = default;

    HashTable_OAH &operator=(const HashTable_OAH &rhs)
    {
        if (this != &rhs) {
            makeEmpty();
            for(int i=0;i<rhs.arr.size();i++)
                insert(rhs.arr[i].ele);

//            for (const auto HE : rhs.arr) {
//                insert(HE);

        }
        return *this;
    }

    bool contains(const int &x)
    {
        return isActive(findPos(x));
    }

    int size() const {return curSize;}

    int sizeOfArr() const {return arr.size();}

    bool insert(const int &x)
    {
        int curPos = findPos(x);
        if(isActive(curPos))
            return false;
        arr[curPos] = HashEntry(x, ACTIVE);
        if (++curSize > (arr.size()>>1))
            rehash();
        return true;
    }

    bool remove(const int &x)
    {
        int curPos = findPos(x);
        if (!isActive(curPos))
            return false;

        arr[curPos].info = DELETED;
        --curSize;
        return true;
    }

    void makeEmpty()
    {
        curSize = 0;
        for(int i = 0;i<arr.size();i++)
            arr[i].info = EMPTY;
    }

    void print()
    {
        for(int i=0;i<arr.size();i++)
        {
            cout << arr[i].ele << ":" << arr[i].info << endl;
        }
    }

private:

    bool isActive(int curPos) const
    {
        return arr[curPos].info == ACTIVE;
    }

    int findPos(const int &x)
    {
        int offset = 1;
        int curPos = myHash(x);
        while(arr[curPos].info != EMPTY && arr[curPos].ele != x)
        {
            curPos +=offset;
            offset+=2;
            if(curPos>=arr.size())
                curPos-=int(arr.size());
        }
        return curPos;
    }

    int myHash(const int &x)
    {

        int hashVal = hash_value(x);
        hashVal%=arr.size();
        if (hashVal<0)
            hashVal+=int(arr.size());
        return hashVal;
    }

    void rehash()
    {
        vector<HashEntry> oldArr = arr;
        arr.resize(nextPrime(int(oldArr.size()<<1)));
        for(int i=0;i<arr.size();i++)
            arr[i].info = EMPTY;
        curSize=0;
        for(int i=0;i<oldArr.size();i++)
        {
            if(oldArr[i].info == ACTIVE)
                insert(oldArr[i].ele);
        }
    }

    int hash_value(int n)
    {
        vector<int> dp(n+1);
        dp[0]=1;
        for(int i=1;i<=n;i++)
            dp[i]=dp[i-1]+2*i-1;
        return (dp[n]);
    }

private:
    vector<HashEntry> arr;
    int curSize;
};
