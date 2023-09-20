#include<iostream>
using namespace std;
class coord
{
    int x,y;
public:
 coord(int i=0,int j=0)
 {
     cout<<"Parameterized Constructor"<<endl;
     x=i;
     y=j;
 }
 void get_xy(int &i,int &j){
 i=x;
 j=y;
 }
 coord operator +(coord ob2)
 {
     coord temp;
     temp.x=x+ob2.x;
     temp.y=y+ob2.y;
     return temp;
 }
 coord operator +(int i){
 coord temp;
     temp.x=x+i;
     temp.y=y+i;
     return temp;

 }
 coord operator++(){
 x++;
 y++;

 return *this;
 }
 coord operator++(int notused){
 x++;
 y++;

 return *this;
 }
 bool  operator==(coord ob2)
 {
     return x==ob2.x && y==ob2.y;
 }


};

int main()
{
    coord o1(10,20),o2(5,3),o3(15,23),o4;
    int x,y;
    o4=o1+o2+o3;
    o4.get_xy(x,y);
    cout<<"x="<<x<<"      y="<<y<<endl;
    o4=o1+o2+o3+100;
    o4.get_xy(x,y);
    cout<<"x="<<x<<"     y="<<y<<endl;
    (o4++).get_xy(x,y);
    cout<<"x="<<x<<"     y="<<y<<endl;
    (++o4).get_xy(x,y);
    cout<<"x="<<x<<"     y="<<y<<endl;

    o4=o1;
    o4.get_xy(x,y);
    cout<<"x="<<x<<"      y="<<y<<endl;
    if(o3==(o2+o1))cout<<"Same"<<endl;
    else cout<<"Not same"<<endl;
}


