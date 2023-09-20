#include<iostream>
#include<typeinfo>
using namespace std;
class Shape{
public:
    virtual void example()=0;
};
class Triangle:public Shape{
public:
 void example()
 {
  cout<<" * \n * * \n * * * \n * * * *"<<endl;
 }
};
class Rectangle:public Shape{
public:
void example()
 {
   cout<<" *****\n *   *\n *   *\n *****"<<endl;
 }
};
class Line:public Shape{
public:
void example()
 {
  cout<<"**********"<<endl;
 }

};
class Nullshape:public Shape{
public:
void example()
 {

 }
};
Shape *Generator(){
switch(rand()%4)
{
case 0:
    return new Nullshape;
case 1:
    return new Line;
case 2:
    return new Triangle;
case 3:
    return new Rectangle;

}

}
int main()
{
    int i;
    Triangle T;
    Shape *p;

    for(i=0;i<10;i++)
    {
        p=Generator();
        cout<<typeid(*p).name()<<endl;
        if(typeid(*p)!=typeid(Nullshape))
        {
            p->example();
        }
    }
}
