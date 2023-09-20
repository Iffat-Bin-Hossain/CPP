#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int t,i,n,Count,j;
    cin>>t;
    for(i=0; i<t; i++)
    {
        cin>>n;
        int A[n];
        int t=n;
        Count=0;
        int k=0;
        while(t!=0)
        {
            int r=t%10;
            if(r!=0)
            {
                Count++;
            }
            A[k]=r;
            k++;
            t=t/10;

        }
        cout<<Count<<endl;
        if(Count==1)
        {
            cout<<n<<endl;
        }
        else
        {
            for(j=k-1; j>=0; j--)
            {
                if(A[j]!=0)
                {
                    cout<<A[j]*pow(10,j)<<" ";
                }
            }
            cout<<endl;
        }
    }
//cout<<endl;

}


