#include<iostream>
using namespace std;
class Point
{
 int x,y;
 public:
     Point(int x,int y)
     {
         this->x=x;
         this->y=y;
     }
    int getx(){return x;}
    int gety(){return y;}
};
int main()
{
 Point ob[2]={Point(1,2),Point(5,6)};
 Point o(3,4);
 Point *p;
 p=&o;
 cout<< p->getx() <<" "<<p->gety()<<endl;
 p=ob;
 for(int i=0;i<2;i++)
 {
    cout<<p->getx()<<" "<<p->gety()<<endl;
    p++;
 }
}
