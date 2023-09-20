#include <bits/stdc++.h>
using namespace std;

class HashTable
{
    int capacity;
    list<int> *hashTable;

public:
    HashTable(int capacity)
    {
        this->capacity = capacity;
        hashTable = new list<int>[capacity];
    }
    int hashFunction(int value)//K%n method
    {
        int key = value % capacity;
        return key;
    }
    void add(int value)
    {
        int key = hashFunction(value);
        hashTable[key].push_back(value);
    }
    void remove(int value)
    {
        int key = hashFunction(value);
        list<int>::iterator i;
        for (i = hashTable[key].begin(); i != hashTable[key].end(); i++)
        {
            if (*i == value)
            {
                hashTable[key].erase(i);
                break;
            }
        }
    }
    bool search(int value)
    {
        int key = hashFunction(value);
        list<int>::iterator i;
        for (i = hashTable[key].begin(); i != hashTable[key].end(); i++)
        {
            if (*i == value)
            {
                return true;
            }
        }
        return false;
    }
    void display()
    {
        cout<<"Hashtable"<<endl;
        for (int i = 0; i < capacity; i++)
        {
            for (auto x : hashTable[i])
            {
                cout << " " << x;
            }
            cout << endl;
        }
    }
};
int main()
{
    cout<<boolalpha << endl;
    int Arr[] = {15, 11, 27, 8, 12, 24,25,34,51,55};
    int size = sizeof(Arr) / sizeof(Arr[0]);
    HashTable table(10);
    for (int i = 0; i < size; i++)
    {
        table.add(Arr[i]);
    }
    table.display();
    cout<<table.search(35)<<endl;
    cout<<table.search(27)<<endl;
    for (int i = 0; i < size; i++)
    {
        table.remove(Arr[i]);
        table.display();
    }

}