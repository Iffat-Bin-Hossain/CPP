#include<iostream>
#include<conio.h>
using namespace std;
void Display(int a=20,int b=30)
{
    cout<<a<<" "<<b<<endl;
}
int main()
{
    Display();//this call will use default values of parameter
    Display(80);//this call will replace the first parameter's value
    Display(50,60);//this call will replace both values of parameters
    getch();
}
