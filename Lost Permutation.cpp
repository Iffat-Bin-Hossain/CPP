#include<bits/stdc++.h>

using namespace std;
int main()
{
    int t,m,s,i,j;
    int b[52];
    int A[52]= {0};
    cin>>t;
    for(i=0; i<t; i++)
    {
        cin>>m >>s;

        for(j=0; j<m; j++)
        {
            cin>>b[i];
            int x=b[i];
            A[x-1]=x;
        }
        int Max=A[0];
        int l=sizeof(A)/sizeof(A[0]);
        for(j=1; j<l; j++)
        {
            if(A[i]>Max)
            {
                Max=A[i];
            }
        }
        int Sum=0;
        for(j=0; j<Max; j++)
        {
            if(A[i]==0)
            {
                A[i]=i+1;
                Sum+=A[i];
            }
        }
         int flag=1;
        if(Sum==0)
        {
            flag*=1;
        }
        else
        {
            while(true)

                if(Sum==s)
                {
                    flag*=0;
                    break;
                }
                else if(Sum<s)
                {
                    Max++;
                    Sum+=Max;

                }
                else if(Sum>s){
                    flag*=1;
                    break;
                }
        }
        if(flag==0)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;

    }


}
