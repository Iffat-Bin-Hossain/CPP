#include<iostream>
using namespace std;
class person{
public:
virtual void display()
{
    cout<<"This is a Person class"<<endl;
}

};
class student:public person{
public:
void display()
{
    cout<<"This is a Student class"<<endl;
}

};
int main()
{
    person p,*b;
    b=&p;
    b->display();
    student s;
    b=&s;
    b->display();
}
