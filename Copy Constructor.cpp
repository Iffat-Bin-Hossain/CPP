#include<iostream>
#include<cstring>
using namespace std;
class point{
int x,y;
char name[50];
public:
point(int a,int b,char A[50])
{
    x=a;
    y=b;
    strcpy(name,A);
}
point(const point &p)
{
    x=p.x;
    y=p.y;
    strcpy(name,p.name);
}
void display(){
cout<<name<<endl;
}
int getx(){return x;}
int gety(){return y;}

};
int main()
{
    point p1(0,0,"Origin");
    cout<<"p1.x="<<p1.getx()<<" p1.y="<<p1.gety()<<'\t';
    p1.display();
    point p2=p1;//point p2(p1);
    cout<<"p2.x="<<p2.getx()<<" "<<"p2.y="<<p2.gety()<<'\t';
    p2.display();
}
