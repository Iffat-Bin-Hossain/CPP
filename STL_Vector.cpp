#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << boolalpha << endl;
    vector<int> v;
    for (int i = 1; i <= 9; i++)
    {
        v.push_back(i);
    }
    // begin() & end()
    // identify data type by ownself without exact definition

    // use of begin() & end()
    for (auto i = v.begin(); i != v.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
    // use of constant begin() & constant end()
    for (auto i = v.cbegin(); i != v.cend(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
    // use of reverse begin() & reverse end()
    for (auto i = v.rbegin(); i != v.rend(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
    // use of constant reverse begin() & constant reverse end()
    for (auto i = v.crbegin(); i != v.crend(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;

    // current size of vector
    cout << v.size() << endl;
    // maximum size of vector
    cout << v.max_size() << endl;
    // currently stored space in terms of element number
    cout << v.capacity() << endl;
    // resize vector as length 5
    v.resize(5);
    for (auto i = v.begin(); i != v.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
    // Check if a vector is empty
    cout << v.empty() << endl;

    // reference operator
    cout << v[2] << endl;
    cout << v.at(3) << endl;
    // first element
    cout << v.front() << endl;
    // last element
    cout << v.back() << endl;
    // first pointer of vector contiguous memories
    int *pos = v.data();
    cout << *pos << endl;

    // Assign value=5 for 9 elements
    v.assign(9, 5);
    for (auto i = v.begin(); i != v.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
    // inserting at the end
    v.push_back(10);
    // insert at any position
    v.insert(v.begin(), 1);
    for (auto i = v.begin(); i != v.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
    // remove last element
    v.pop_back();
    for (auto i = v.begin(); i != v.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
    // clearing all elements
    v.clear();
    cout << v.size() << endl;

    vector<int> v1, v2;
    v1.push_back(10);
    v1.push_back(20);
    v2.push_back(30);
    v2.push_back(40);
    v2.push_back(50);
    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << " ";
    cout << endl;
    for (int i = 0; i < v2.size(); i++)
        cout << v2[i] << " ";
    cout << endl;
    // swapping the vactors
    v1.swap(v2);
    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << " ";
    cout << endl;
    for (int i = 0; i < v2.size(); i++)
        cout << v2[i] << " ";
    cout << endl;
}