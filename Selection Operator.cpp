#include<iostream>
#include<conio.h>
using namespace std;

class Student{
public:
int ID;
float CGPA;
Student()//Constructor.No return type
{
    cout<<"Constructor is called"<<endl;
}
~Student()//Destructor.No return type
{
    cout<<"Destructor is called"<<endl;
}
void Display()
{
   cout<<"Display is called"<<endl;
}
void SetValue()
{
   cout<<"SetValue is called"<<endl;
}
};
int main(){
Student ob1;
Student *P=&ob1;
P->Display();
P->SetValue();
}

