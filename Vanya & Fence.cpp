#include<iostream>
using namespace std;
int main()
{
 int n,i,h,a[2005],W=0;
 cin>>n>>h;
 for(i=0;i<n;i++)
 {
     cin>>a[i];
     if(a[i]>h)
     {
         W+=2;
     }
     else W++;
 }
 cout<<W;
}
