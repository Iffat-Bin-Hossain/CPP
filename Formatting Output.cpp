#include<iostream>
#include<conio.h>
#include<cstring>
#include<iomanip>
using namespace std;

int main()
{
float num1,num2;
char S[100];
cout<<"Enter two numbers : ";
cin>>num1>>num2;
//cout<<skipws;
gets(S);
cout<<S<<endl;
cout<<showpoint;
cout<<fixed;
cout<<setprecision(2);
float Sum=num1+num2;
cout<<setw(50)<<"Summation of the two numbers : "<<Sum<<endl;
//cout<<noshowpoint;
float Sub=num1-num2;
cout<<setw(50)<<"Substraction of the two numbers : "<<Sub<<endl;
float Mul=num1*num2;
cout<<setw(50)<<"Multiplication of the two numbers : "<<Mul<<endl;

float Div=num1/num2;
cout<<setw(50)<<"Division of the two numbers : "<<Div<<endl;
}
