#include<iostream>
using namespace std;
int main()
{
    int i;
    char *p="My name is nabil";
    i=reinterpret_cast<int>(p);
    cout<<i<<endl;
    char *q="My Name is Nabil";
    i=reinterpret_cast<int>(q);
    cout<<i<<endl;
}
