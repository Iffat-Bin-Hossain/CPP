//Palindrome denote those numbers which remain exactly same even if they are reversed.This program will find out nth palindrome
#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
    int n,C=0,N=1,T,r;
    cout<<"Enter the value of n : ";
    cin>>n;
    while(C!=n)
    {
    T=N;
    int Sum=0;
    while(T!=0)
    {
     r=T%10;
     Sum=Sum*10+r;
     T/=10;
    }
    if(Sum==N)C++;
    if(C<n)N++;
    }
    cout<<n<<"th Palindrome : "<<N;
    getch();
}
