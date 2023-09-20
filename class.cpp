#include<iostream>
#include<conio.h>
using namespace std;

class Student{
public:
int ID;
float CGPA;
void SetValue(int x,float y)//parameterized Function
{
    ID=x;
    CGPA=y;
}
void Display()
 {
  cout<<ID<<" " <<CGPA<<endl;
 }
};

int main()
{
    Student Alim,Asif;
    Alim.SetValue(2005087,3.75);
    Alim.Display();
    Asif.SetValue(2005024,4);
    Asif.Display();
}


