#include<iostream>
using namespace std;
int main()
{
    long long int i,t,a,b,k;
    cin>>t;
    for(i=0; i<t; i++)
    {
        cin>>a>>b;
        if(a<=b)
        {
            cout<<b-a<<endl;
        }
        else
        {
            if(a%b==0) cout<<0<<endl;
            else
            {
                k=a/b;
                cout<<((k+1)*b)-a<<endl;
            }
        }
    }
}
