#include <iostream>
#include "HashTable(OAH).h"
#include "HashTable(SC).h"

using namespace std;


void Hash()
{
    cout << "Hash function test" << endl;

    HashTable_OAH  ha(10);
    for(int i=1;i<6;i++)
        ha.insert(i*i);

    ha.print();

    cout << ha.size() << endl;
    cout << ha.sizeOfArr() << endl;

    if(ha.contains(26))
        cout << "the position of element" << endl;

//    if(ha.insert(24))
//        cout << "Inserted successfully" << endl;

//    ha.print();

}

void Hash1()
{
    cout << "Hash function test" << endl;

    HashTable_SC  ha(10);
    for(int i=1;i<40;i++)
        ha.insert(i*i);

    ha.print();

    cout << ha.size() << endl;
    cout << ha.sizeOfArr() << endl;

    if(ha.contains(529))
        cout << "the position of element" << endl;

}

int main()
{
//    Hash();
    Hash1();

    cout << "Hello world!" << endl;
    return 0;
}
