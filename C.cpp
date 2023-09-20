#include<iostream>
#include<vector>
using namespace std;
int main()
{

    long long int t,i,n,j,k,x;
    cin>>t;
    for(i=0; i<t; i++)
    {
        cin>>n;
        long long int A[n],S[n];
        for(j=0; j<n; j++)
        {
            cin>>A[j];

        }
        int Max=A[0];
        for(j=1; j<n; j++)
        {
           if(A[j]>Max) {
            Max=A[j];
            x=j;
           }
        }
        int Second_Max;
        if(Max!=A[0]){
        Second_Max= A[0];
        }
        else{
           Second_Max=A[1];
        }
        for(j=0;j<n;j++){
            if(A[j]>Second_Max && j!=x){
                Second_Max=A[j];
            }
        }
        for(j=0; j<n; j++)
        {
            if(A[j]==Max){
                cout<<Max-Second_Max<<" ";
            }
            else{
                cout<<A[j]-Max<<" ";
            }

        }
cout<<endl;
    }

}

