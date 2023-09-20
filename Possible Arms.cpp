#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

int main()
{
   int A,B,C,Count;
   cin>>A>>B;
   C=1;
   while(C+A<=B || B+C<=A || A+B<=C)
   {
       C++;
   }
   Count=0;


      while(C+A>B && B+C>A && A+B>C)
   {
       Count++;
       C++;
   }

   cout<<Count;
}
