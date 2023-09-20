#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[6] = {10, 2, 4, 8, 6, 9};
    //priority que as max heap;
    priority_queue<int> pq1;
    for (auto i : arr)
    {
        cout << i << " ";
        pq1.push(i);
    }
    cout << endl;
    while (!pq1.empty())
    {
        cout << pq1.top() << " ";
        pq1.pop();
    }
    //priority que as min heap;
    priority_queue<int,vector<int>,greater<int>> pq2;
    for (auto i : arr)
    {
       
        pq2.push(i);
    }
    cout << endl;
    while (!pq2.empty())
    {
        cout << pq2.top() << " ";
        pq2.pop();
    }
    for (auto i : arr)
    {
       
        pq2.push(i);
    }
    cout<<pq2.size()<<endl;
    cout<<pq2.top()<<endl;
    //pq1.swap(pq2);
}