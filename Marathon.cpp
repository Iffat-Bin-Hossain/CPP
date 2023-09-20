#include<iostream>
using namespace std;
int main()
{
    long int a,b,c,d;
    long int t,C[10002];
    cin>>t;
    for(long int i=0;i<t;i++)
    {
     cin>>a>>b>>c>>d;
     C[i]=0;
     if(a<b) C[i]++;
     if(a<c) C[i]++;
     if(a<d) C[i]++;
    }
    for(long int j=0;j<t;j++)
    {
     cout<<C[j]<<endl;
    }


}
