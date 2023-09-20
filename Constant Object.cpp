#include<iostream>
#include<cmath>
using namespace std;


class Student{
public:
int ID;
float CGPA;
void Display()const
{
     cout<<"Display is called"<<endl;
}
};


int main()
{
   const Student ob;
   ob.Display() const;
}
