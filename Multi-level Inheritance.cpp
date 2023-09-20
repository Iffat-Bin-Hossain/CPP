#include<iostream>
using namespace std;


class person{
public:
string Name;
int Age;

 void Display1()
 {
      cout<<"Display1:"<<endl;
  cout<<"Name: "<<Name<<endl<<"Age: "<<Age<<endl;
 }
};

class Student:public person{
public:
int ID;
long long int Cell_NO;
void Display2()
{
    cout<<"Display2:"<<endl;
  Display1();
  cout<<"Student Id: "<<ID<<endl<<"Cell No: "<<Cell_NO<<endl;
}
};

class Student_Details:public Student{
public:
string Father_Name,Mother_Name;
int Room_NO;
void Display3()
{
    cout<<"Display3:"<<endl;
  Display2();
  cout<<"Father's Name: "<<Father_Name<<endl<<"Mother's Name: "<<Mother_Name<<endl<<"Room Number: "<<Room_NO<<endl;
}
    };
 int main()
 {
     Student_Details ob;
    ob.Name="Iffat Bin Hossain";
    ob.Age=21;
    ob.ID=2005087;
    ob.Cell_NO=8801754117613;
    ob.Father_Name="Nabab Hossain";
    ob.Mother_Name="Shahinur Akther";
    ob.Room_NO=109;
    ob.Display3();
}

