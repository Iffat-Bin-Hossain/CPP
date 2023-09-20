#include<iostream>
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        cin>>n;
        int A[n];
        for(int j=0; j<n; j++)
        {
            cin>>A[j];
        }
        int s;
        if(A[0]==A[1])
        {
            for(int k=2; k<n; k++)
            {
                if(A[k]!=A[0])
                {
                    s=k+1;
                    break;
                }
            }
        }
        else
        {
            if(A[0]==A[2])
            {
                s=2;
            }
            else
            {
                s=1;
            }
        }
        cout<<s<<endl;

    }



}
