#include<iostream>
using namespace std;
class Student{
string Name;
public:
Student (string Name)
{
 this->Name=Name;
}
void Display()
{
 cout<<Name<<endl;
}
 };
int main(){
 Student ob("Iffat Bin Hossain");
 ob.Display();
}
