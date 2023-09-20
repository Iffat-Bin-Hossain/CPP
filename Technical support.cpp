#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int i,j,k, t,n[501],TA[501]= {0},TQ[501]= {0};
    char A[501][102];
    bool B[501];
    cin>>t;

    for(i=0; i<t; i++)
    {
        cin>>n[i];
        for(j=0; j<n[i]; j++)
        {
            cin>>A[i][j];
        }
        for(j=0; j<n[i]-1; j++)
        {

            if(A[i][j]=='Q')
            {
                for(k=j+1; k<n[i]; k++)
                {
                    if(A[i][k]=='A')
                    {
                        A[i][j]='X';
                        A[i][k]='X';
                        break;
                    }
                }
                continue;
            }
            else
            {
                continue;
            }
        }

        for(j=0;j<n[i];j++){
            if(A[i][j]=='Q')
            {
              B[i]=true;
              break;
            }
        }

    }
    for(i=0; i<t; i++)
    {
        if(!B[i]) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }


}
