#include<iostream>
#include<typeinfo>
using namespace std;
class Base{
public:
virtual void f()
{
cout<<"It is a function inside base class"<<endl;
}
};
class Derived1:public Base{
public:
void f()
{
cout<<"It is a function inside first derived class"<<endl;
}
};
class Derived2:public Base{
public:
void f()
{
cout<<"It is a function inside second derived class"<<endl;
}
};
class X{
public:
virtual void f()
{
}
};
class Y{
public:
virtual void f()
{
}
};
void whattype(Base & b)
{
    cout<<"Type: "<<typeid(b).name()<<endl;
}
int main()
{
    float i;
    Base *pb,ob;
    Derived1 od1;
    Derived2 od2;
    X x1,x2;
    Y y;

    cout<<"Type of i is "<<typeid(i).name()<<endl;
    pb=&ob;
    cout<<"Type of ob is "<<typeid(ob).name()<<endl;
    cout<<"Type of ob is "<<typeid(*pb).name()<<endl;
    pb=&od1;
    cout<<"Type of ob is "<<typeid(od1).name()<<endl;
    cout<<"Type of ob is "<<typeid(*pb).name()<<endl;
    pb=&od2;
    cout<<"Type of ob is "<<typeid(od2).name()<<endl;
    cout<<"Type of ob is "<<typeid(*pb).name()<<endl;
    whattype(ob);
    whattype(od1);
    whattype(od2);
    if(typeid(x1)==typeid(x2))
    {
        cout<<"Same"<<endl;
    }
    else{
      cout<<"Different"<<endl;
    }
    if(typeid(x1)!=typeid(y))
    {
        cout<<"Different"<<endl;
    }
    else{
      cout<<"Same"<<endl;
    }
return 0;
}
