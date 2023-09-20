#include<iostream>
using namespace std;
class Base
{

public:
    int x;
    Base(int n)
    {
        x=n;
    }
    virtual void Get()
    {
        cout<<"x:"<<x<<endl;
    }

};
class Derived:public Base
{

public:
    Derived(int n):Base(n) {}
    void Get()
    {
        cout<<"x^2:"<<x*x<<endl;
    }

};
int main()
{
    int i,j;
    Base *bp;
    Base b(10);
    Derived d(20);
    for(i=0; i<10; i++)
    {
        j=rand();
        cout<<j<<endl;
        if(j%2)
        {
            bp=&b;
        }
        else
        {
            bp=&d;
        }
        bp->Get();
    }


}
