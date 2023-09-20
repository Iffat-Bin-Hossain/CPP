#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    long long int t,i,j,n;
    cin>>t;
    for(i=0; i<t; i++)
    {
        cin>>n;
        int flag=1;
        int p=log2(n);
        if(pow(2,p)==n){
            flag=0;
        }
        if(flag==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }

}
