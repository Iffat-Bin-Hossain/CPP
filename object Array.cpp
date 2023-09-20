#include<iostream>
using namespace std;
class Student{int x;
public:
Student(){x=0;}
Student(int n){x=n;}
int getx(){return x;}
};
int main()
{
    Student *s;
    Student s2(3);
    s=new Student[5];
    if(!s){cout<<"Allocation Error";}
    for(int i=0;i<5;i++)
    {
        cout<<"s["<<i<<"]:"<<s[i].getx()<<" ";
    }
    cout<<endl;
    for(int i=0;i<5;i++)
    {
      s[i]=s2;
    }

    cout<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<"s["<<i<<"]:"<<s[i].getx()<<" ";
    }
}
