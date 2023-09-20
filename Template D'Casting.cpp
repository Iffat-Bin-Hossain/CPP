#include<iostream>
#include<typeinfo>
#include<cmath>
using namespace std;
template <class T>class Num
{
public:
    T x;
    Num(T i)
    {
        x=i;
    }
    virtual T get_val()
    {
        return x;
    }
};
template <class T>class Square:public Num<T>
{
public:
    Square(T i):Num<T>(i) {}
    T get_val()
    {
        return this->x*this->x;
    }
};
template <class T>class Cube:public Num<T>
{
public:
    Cube(T i):Num<T>(i) {}
    T get_val()
    {
        return this->x*this->x*this->x;
    }
};
template <class T>class Sqrroot:public Num<T>
{
public:
    Sqrroot(T i):Num<T>(i) {}
    T get_val()
    {
        return sqrt((double)this->x);
    }
};
Num<double> * Generator()
{
    switch(rand()%2)
    {

    case 0:
        return new Square<double>(rand()%5);
    case 1:
        return new Cube<double>(rand()%7);
    }
}
int main()
{
    Num<double>ob1(10),*p1;
    Square<double>ob2(5),*p2;
    Cube<double>ob3(3),*p3;
    int i;

    for(i=0;i<10;i++)
    {
        p1=Generator();
        p2=dynamic_cast<Square<double>*>(p1);
        if(p2)
        {
            cout<<"Cast(1 to 2)Ok"<<endl;
            cout<<p2->get_val()<<endl;
        }
        else{cout<<"Cast(1 to 2)Failed"<<endl;}
        p3=dynamic_cast<Cube<double>*>(p1);
        if(p3)
        {
            cout<<"Cast(1 to 3)Ok"<<endl;
            cout<<p3->get_val()<<endl;
        }
        else{cout<<"Cast(1 to 3)Failed"<<endl;}
    }
}

