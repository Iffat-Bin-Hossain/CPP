#include<iostream>
using namespace std;
class B
{
public:
    int i;
    B()
    {
        cout<<"Constructing B"<<endl;
    }
    ~B()
    {
        cout<<"Destructing B"<<endl;
    }
};
class D1:virtual public B{
public:
    int j;
    D1():B()
    {
        cout<<"Constructing D1"<<endl;
    }
    ~D1()
    {
        cout<<"Destructing D1"<<endl;
    }

};
class D2:virtual public B{
public:
    int k;
    D2():B()
    {
        cout<<"Constructing D2"<<endl;
    }
    ~D2()
    {
        cout<<"Destructing D2"<<endl;
    }

};
class D3:public D1,public D2{
public:
    int k;
    D3():D1(),D2()
    {
        cout<<"Constructing D3"<<endl;
    }
    ~D3()
    {
        cout<<"Destructing D3"<<endl;
    }

};
int main(){
D3 ob;
ob.i=9;
ob.j=7;

}


