#include<iostream>
#include<conio.h>
using namespace std;

class Student{
public:
int ID;
float CGPA;
Student(int x,float y)//Parameterized Constructor.No return type
{
    ID=x;
    CGPA=y;
}
Student()//Default Constructor.Don't have any Parameter
{
   cout<<"Default Constructor"<<endl;
}
void Display()
 {
  cout<<ID<<" " <<CGPA<<endl;
 }
};

int main()
{
    Student Alim(2005087,3.89),Asif(2005024,4);
    Student Nabil;
    Asif.Display();
    Alim.Display();


}



