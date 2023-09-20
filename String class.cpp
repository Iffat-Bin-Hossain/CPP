#include<iostream>
#include<cstring>
#include<conio.h>
using namespace std;
int main()
{
 string S1="Anisul",S2=" Islam",S3;
 S3=S1;
 cout<<S3<<endl;
 S3=S1+S2;
 cout<<S3<<endl;
 int L=S1.size();
 cout<<L<<endl;
 cout<<S1.front()<<endl;//print the first character of string
 cout<<S1.back()<<endl;//print the last character of string
}
