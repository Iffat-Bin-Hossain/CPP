#include<iostream>
using namespace std;
int main()
{
    int y,d[5],T;
    cin>>y;
again:
    y++;
    T=y;
    int i=0;
    while(T!=0)
    {
     d[i]=T%10;
     T/=10;
     i++;
    }
if(d[0]==d[1] || d[0]==d[2] || d[0]==d[3] || d[1]==d[2] || d[1]==d[3] || d[2]==d[3])
    {
    goto again;
    }
else
{
  cout<<y;
}

}
