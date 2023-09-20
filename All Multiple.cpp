
#include<iostream>
using namespace std;
int main()
{
    int t,i,j,n,x;
    cin>>t;
    for(int k=0;k<t;k++){
    cin>>n>>x;
    int A[n]= {0};
    int flag=1;
    A[0]=x;
    A[n-1]=1;
    for(i=2; i<n; i++)
    {
        for(j=i+1; j>=n; j++)
        {
            if(j%i==0 && j!=x)
            {
                A[i-1]=j;
                break;
            }

        }

    }
    for(i=0;i<n;i++){
        if(A[i]==0){
            flag=0;
            break;
        }
    }
    if(flag==1){
       for(i=0;i<n;i++){
           cout<<A[i]<<" ";
       }
       cout<<endl;
    }
    else{
        cout<<-1<<endl;
    }
    }
}
