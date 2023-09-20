#include<iostream>
using namespace std;
int main()
{
    long int n,i,Count=0;
  int C[100005];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>C[i];
    }

    for(i=0;i<n-1;i++)
    {
       if(C[i]!=C[i+1])
       {
         Count++;
       }
    }
    cout<<Count+1;
}
