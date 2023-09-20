#include<iostream>
using namespace std;


class person{
public:
string Name;
int Age;

 void Display1()
 {
  cout<<"Name: "<<Name<<endl<<"Age: "<<Age<<endl;
 }
};//Parent class/Mother class/Base class/Super class


class Student:public person{
public:
int ID;
void Display2()
{
  Display1();
  cout<<"Student Id: "<<ID<<endl;
}
};//Child class/Daughter class/Derived class/Sub class


int main()
{
    Student ob;
    ob.Name="Istiak Rifti";
    ob.Age=21;
    ob.ID=2005101;
    ob.Display2();
}
