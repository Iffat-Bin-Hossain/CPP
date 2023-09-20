#include<iostream>
using namespace std;
int main()
{
int t,n[200],m[200],a[200][200],S[200];
cin>>t;
for(int i=0;i<t;i++)
{
    cin>>n[i]>>m[i];
    S[i]=0;
    for(int j=0;j<n[i];j++)
    {

        cin>>a[i][j];
        S[i]+=a[i][j];
    }

}
for(int j=0;j<t;j++)
{
    if(S[j]>=m[j]) cout <<S[j]-m[j]<<endl;
    else cout<<0<<endl;
}

}
