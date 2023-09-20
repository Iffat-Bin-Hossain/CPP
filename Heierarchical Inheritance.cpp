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
};
class Student:public person{
public:
int ID;
void Display2()
 {
  Display1();
  cout<<"Student ID: "<<ID<<endl;
 }
};

class Banker:public person{
public:
int Acct_NO;
void Display3()
 {
  Display1();
  cout<<"Account NO: "<<Acct_NO<<endl;
 }
};
int main()
{
    Student S;
    S.Name="Iffat Bin Hossain";
    S.Age=21;
    S.ID=2005087;
    cout<<"Student's Information:"<<endl;
    S.Display2();
    Banker B;
    B.Name="Rezwan Chowdhury";
    B.Age=45;
    B.Acct_NO=444567;
    cout<<"Banker's Information:"<<endl;
    B.Display3();
}
