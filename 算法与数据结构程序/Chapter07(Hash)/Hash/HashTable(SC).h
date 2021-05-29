#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class HashTable_SC{
    int primes[24] = {
        53, 97, 193, 389, 769, 1453, 3079, 6151, 12893, 24593, 49157, 98317,
        196613, 393241, 786433, 1572869, 3145739, 6291469, 12582917,
        25165843, 50331653, 100663319, 201326611, -1
    };

    int nextPrime(int n)
    {
        for(int i=0;i<24;i++)
        {
            if(n<primes[i])
                return primes[i];
        }
        return primes[23];
    }

public:
    HashTable_SC() = delete;

    explicit HashTable_SC(int size1)
    {
        curSize =0;
        theLists.resize(size1);
        makeEmpty();
    }

    HashTable_SC(const HashTable_SC &rhs)
    {
        curSize=0;
        theLists.resize(rhs.theLists.size());
        makeEmpty();
        operator=(rhs);
    }

    ~HashTable_SC() = default;

    HashTable_SC &operator=(const HashTable_SC &rhs)
    {
        makeEmpty();
        for(int i=0;i<rhs.theLists.size();i++)
        {
            list<int> med=rhs.theLists[i];
            list<int>::iterator iter;
            {
                for(iter = med.begin();iter!=med.end();iter++)
                    insert(*iter);
            }
        }
        return *this;
    }

    int size() const
    {
        return curSize;
    }

    bool contains(const int &x)
    {
        list<int> &li = theLists[myHash(x)];
        if(find(li.begin(), li.end(), x) != li.end());
    }

    bool insert(const int &x)
    {
        list<int> &whichList = theLists[myHash(x)];
        if (find(whichList.begin(), whichList.end(), x) != whichList.end())
            return false;

        whichList.push_back(x);
        if(++curSize>theLists.size())
            rehash();
        return true;
    }

    void makeEmpty()
    {
        curSize=0;
        for(int i=0;i<theLists.size();i++)
            theLists[i].clear();
    }

    bool remove(const int &x)
    {
        list<int> &whichList = theLists[myHash(x)];
        list<int>::iterator iter;
        iter = find(whichList.begin(), whichList.end(), x);
        if(iter == whichList.end())
            return false;
        whichList.erase(iter);
        --curSize;
        return true;
    }

    void print()
    {
        for(int i=0;i<theLists.size();i++)
        {
            const list<int> &med=theLists[i];
            list<int>::const_iterator iter;

            cout << i << ":";

            for(iter = med.begin();iter != med.end();iter++)
                cout << *iter << ";";

            cout << endl;
        }
    }

        int sizeOfArr() const {return theLists.size();}

private:
    int myHash(const int &x)
    {
        int hashVal = hash_value(x);
        hashVal %= theLists.size();
        if (hashVal < 0)
            hashVal += int(theLists.size());
        return hashVal;
    }

    int hash_value(int n)
    {
        vector<int> dp(n+1);
        dp[0]=1;
        for(int i=1;i<=n;i++)
            dp[i]=dp[i-1]+2*i-1;
        return (dp[n]);
    }

    void rehash()
    {
        vector<list<int> > oldlists = theLists;
        theLists.resize(nextPrime(theLists.size()<<1));
        for(int i=0;i<theLists.size();i++)
            theLists[i].clear();
        curSize=0;
        for(int i=0;i<oldlists.size();i++)
        {
            list<int> med=oldlists[i];
            list<int>::iterator iter;
            {
                for(iter = med.begin();iter!=med.end();iter++)
                    insert(*iter);
            }
        }
    }

private:
    vector<list<int> > theLists;
    int curSize;
};
