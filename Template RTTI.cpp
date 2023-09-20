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
    switch(rand()%3)
    {
    case 0:
        return new Sqrroot<double>(rand()%10);
    case 1:
        return new Square<double>(rand()%5);
    case 2:
        return new Cube<double>(rand()%7);
    }
}
int main()
{
    Num<double>ob1(10),*p;
    Square<double>ob2(5);
    Cube<double>ob3(3);
    int i;
    if(rand()%2) p=&ob3;
    else p=&ob2;
    if(typeid(*p)==typeid(Square<double>))
    {
        cout<<"Square Class"<<endl;
        cout<<p->get_val()<<endl;
    }
    else
    {
        cout<<"Cube Class"<<endl;
        cout<<p->get_val()<<endl;
    }
    for(i=0;i<10;i++)
    {
        p=Generator();
        cout<<typeid(*p).name()<<"\t"<<p->get_val() <<endl;
    }
}
