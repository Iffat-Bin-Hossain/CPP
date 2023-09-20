#include<iostream>
#include<typeinfo>
#include<cmath>
using namespace std;
class Base
{
public:
    virtual void f()
    {
        cout<<"Inside Base classs"<<endl;
    }
};
class Derived:public Base
{
public:
    void f()
    {
        cout<<"Inside Derived classs"<<endl;
    }
};
int main()
{
    Base *bp,b;
    Derived *dp,d;


    dp=dynamic_cast<Derived *>(&d);
    if(dp)
    {
        cout<<"Cast from Derived * to Deried *"<<endl;
        dp->f();
    }
    else
    {
        cout<<"Error"<<endl;
    }

    bp=dynamic_cast<Base *>(&d);
    if(bp)
    {
        cout<<"Cast from Derived * to Base*"<<endl;
        bp->f();
    }
    else
    {
        cout<<"Error"<<endl;
    }

    bp=dynamic_cast<Base*>(&b);
    if(bp)
    {
        cout<<"Cast from Base * to Base *"<<endl;
        bp->f();
    }
    else
    {
        cout<<"Error"<<endl;
    }


    dp=dynamic_cast<Derived *>(&b);
    if(dp)
    {
        cout<<"Cast from Base * to Deried *"<<endl;
        dp->f();
    }
    else
    {
        cout<<"Error"<<endl;
    }

    bp=&d;
    dp=dynamic_cast<Derived *>(bp);
    if(dp)
    {
        cout<<"Cast from Base * to Deried *"<<endl;
        dp->f();
    }
    else
    {
        cout<<"Error"<<endl;
    }
    bp=&b;
    dp=dynamic_cast<Derived *>(bp);
    if(dp)
    {
        cout<<"Cast from Base * to Deried *"<<endl;
        dp->f();
    }
    else
    {
        cout<<"Error"<<endl;
    }
    dp=&d;
    bp=dynamic_cast<Base *>(dp);
    if(dp)
    {
        cout<<"Cast from Deried * to Base *"<<endl;
        bp->f();
    }
    else
    {
        cout<<"Error"<<endl;
    }
}
