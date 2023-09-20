//Palindrome denote those numbers which remain exactly same even if they are reversed.This program will find out nth palindrome
#include<iostream>
#include<conio.h>
using namespace std;
int Palindrome(int x);
int main()
{
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;
    cout<<n<<"th Palimndrome : "<<Palindrome(n);

}

int Palindrome(int x)
{
  int C=0,N=1,T,r;
  while(C!=x)
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
    if(C<x)N++;
    }
    return N;
}
