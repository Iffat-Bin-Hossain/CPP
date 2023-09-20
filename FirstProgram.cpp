//Find out the Minimum Deviation of n integer numbers
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
 int n,i,N[1000],Sum=0;
 float MD,Avg,T=0;
 cout<<"Enter the value of n:";
 cin>>n;
 cout<<endl;
 for(i=0;i<n;i++)
 {
     cin>>N[i];
     Sum+=N[i];
 }
 Avg=Sum/n;
 for(i=0;i<n;i++)
 {
   T+=fabs(Avg-N[i]);
 }
 MD=T/n;
 cout<<"Minimum Deviation:"<<MD;
}
