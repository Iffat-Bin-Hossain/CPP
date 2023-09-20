#include<iostream>
using namespace std;
int main()
{
  int n,i,A[102],S[102];
  cin>>n;
  for(i=0;i<n;i++)
  {
      cin>>A[i];
  }
  for(i=0;i<n;i++)
  {
      S[A[i]-1]=i+1;
  }
  for(i=0;i<n;i++)
  {
      cout<<S[i]<<" ";
  }
}
