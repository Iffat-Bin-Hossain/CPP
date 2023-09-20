#include<iostream>
using namespace std;
int main()
{
    int n,i,j,k;
    cin>>n;
    int A[n][n];
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            cin>>A[i][j];
        }

    }
    if(n==1)
    {
        cout<<A[0][0];
    }
    else
    {
        int det=0;
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                for(k=0; k<n; k++)
                {
                    if(j!=1 && i!=k)
                    {
                        if(i%2!=0)
                        {
                            det+=A[1][i]*A[j][k];
                        }
                        else
                        {
                            det-=A[1][i]*A[j][k];
                        }
                    }
                }
            }
        }
        cout<<det;
    }
}
