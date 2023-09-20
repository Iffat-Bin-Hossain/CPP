#include<iostream>
using namespace std;
class Area{
double n1,n2;
public:
    void Set(double d1,double d2)
    {
        n1=d1;
        n2=d2;
    }
    void Get(double &d1,double &d2)
    {
      d1=n1;
      d2=n2;
    }
    virtual double area()=0;



};
class Rectangle:public Area{
public:
 double area()
    {
      double d1,d2;
      Get(d1,d2);
      return d1*d2;
    }

};
class Triangle:public Rectangle{
public:
 double area()
    {
      double d1,d2;
      Get(d1,d2);
      return 0.5*d1*d2;
    }

};
void print(Area &a)//Creating Reference of a abstract class
{
    double d1,d2;
    a.Get(d1,d2);
    cout<<d1<<"  "<<d2<<endl;

}
int main()
{
    Area *p;
    Rectangle ob2;
    Triangle ob3;
    //cout<<p->area()<<endl;

    p=&ob2;
    p->Set(5,5);
    cout<<p->area()<<endl;
    p=&ob3;
    p->Set(6,5);
    cout<<p->area()<<endl;
    print(ob2);
    print(ob3);
}
