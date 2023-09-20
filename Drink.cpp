#include<iostream>
using namespace std;
int main()
{
  double n,p[100],S=0,vf;
  int i;
  cin>>n;
  for(i=0;i<n;i++)
  {
      cin>>p[i];
      S+=p[i];
  }
  vf=S/n;
  printf("%.12f",vf);

}
