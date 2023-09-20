#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int x,Sum;
    cin>>x;


    int len=log10(x);
    cout<<len<<endl;
    int i=len;
    int T=x;
    Sum=0;
    while(T!=0)
    {
        int r=T%10;
        Sum=Sum+(r*pow(10,i));
        cout<<Sum<<endl;
        T=T/10;
        i--;

    }
    cout<<Sum;

}
