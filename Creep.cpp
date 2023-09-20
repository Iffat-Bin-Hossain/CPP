#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int t,a,b,S[1000];
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>a>>b;
        S[i]=0;
        for(int j=a;j<a+b;j++)
        {
            S[i]+=1*pow(10,j);
        }

    }
  for(int i=0;i<t;i++)
   {
   cout<<S[i]<<endl;
   }


}
