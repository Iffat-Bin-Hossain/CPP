#include<iostream>
#include<typeinfo>
#include<cmath>
using namespace std;
class Base
{
public:
    virtual void f()
    {

    }
};
class Derived:public Base
{
public:
    void f()
    {

    }
};
int main()
{
    Base *bp,b;
    Derived *dp,d;
    bp=&b;
    dp=dynamic_cast<Derived *>(bp);
    if(dp)
    {
        cout<<"Cast Ok"<<endl;
    }
    else
    {
        cout<<"Cast Failed"<<endl;
    }
    bp=&d;
    dp=dynamic_cast<Derived *>(bp);
    if(dp)
    {
        cout<<"Cast Ok"<<endl;
    }
    else
    {
        cout<<"Cast Failed"<<endl;
    }
    dp=&d;
    bp=dynamic_cast<Base *>(dp);
    if(bp)
    {
        cout<<"Cast Ok"<<endl;
    }
    else
    {
        cout<<"Cast Failed"<<endl;
    }
    /*dp=&b;//Error
    bp=dynamic_cast<Base *>(dp);
    if(bp)
    {
        cout<<"Cast Ok"<<endl;
    }
    else
    {
        cout<<"Cast Failed"<<endl;
    }*/
}
