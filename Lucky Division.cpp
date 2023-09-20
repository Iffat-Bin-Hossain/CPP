#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n,i;
    int flag=1;
    cin>>n;
    int T=n;
    while(T!=0)
    {
        int r=T%10;
        if(r==4 || r==7){
            flag=flag*1;
        }
        else{
            flag*=0;
            break;
        }
        T/=10;

    }
    if(flag==0)
    {
      if(n%4==0 || n%7==0 ||n%44==0 || n%47==0||n%74==0 || n%77==0||n%444==0 || n%447==0||n%474==0 || n%477==0||n%744==0 || n%747==0||n%774==0 || n%777==0)
      {

          flag=1;
      }
    }
if(flag==1){
  cout<<"YES";
}
else{
    cout<<"NO";
}
}
