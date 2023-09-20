#include<iostream>
using namespace std;
int main()
{
    int t,i,x,a,b,c,Count[20];
    cin>>t;
    for(i=0; i<t; i++)
    {
        cin>>x;
        cin>>a>>b>>c;
        Count[i]=0;
        int T=x;
        for(int j=0; j<3; j++)
        {
            if(T==1)
            {
                Count[i]++;
                if(a!=0)
                {
                    T=a;
                }
                else break;
            }
            else if(T==2)
            {
                Count[i]++;
                if(b!=0)
                {
                    T=b;
                }
                else break;
            }
            else
            {
                Count[i]++;
                if(c!=0)
                {
                    T=c;
                }
                else break;
            }
        }

    }
    for(i=0;i<t;i++)
    {
        if(Count[i]==3) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }

}
