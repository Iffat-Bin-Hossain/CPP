#include<iostream>
using namespace std;
int main()
{
    int n,i,p[105],q[105];
    cin>>n;
    int C=0;
    for(i=0; i<n; i++)
    {
        cin>>p[i]>>q[i];
    }
    for(i=0; i<n; i++)
    {
        if(q[i]-p[i]>=2)
        {
            C++;
        }
    }
    cout<<C;

}
