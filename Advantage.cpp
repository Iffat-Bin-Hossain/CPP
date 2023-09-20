#include<iostream>
using namespace std;
int main()
{
    int t,n,i,j,k;
    cin>>t;
    int Max,second_max;
    for(i=0; i<t; i++)
    {
        cin>>n;
        int A[n];
        Max=0;
        for(j=0; j<n; j++)
        {
            cin>>A[j];
            if(A[j]>Max)
            {
                Max=A[j];
                k=j;
            }

        }
        second_max=A[0];
        for(j=0; j<n; j++)
        {
            if(A[j]>second_max && j!=k)
            {
                second_max=A[j];

            }
        }
        for(j=0;j<n;j++){
            if(A[j]==Max){
                cout<<Max-second_max<<" ";
            }
            else{
                cout<<A[j]-Max<<" ";
            }
        }
        cout<<endl;
    }
}
