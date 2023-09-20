#include<iostream>
#include<cstring>
#include<conio.h>
using namespace std;
class Student{
private:
 string S;
public:
  void Setter(string x)
  {
      S=x;
  }
  string Getter()
  {
      return S;
  }

};
int main()
{
 Student ob1;
 ob1.Setter("Iffat Bin Hossain");
 cout<<ob1.Getter()<<endl;
}
