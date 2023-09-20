#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int t,i,j,n,Sh,Sm,Min,H[102][11],M[102][11],Dh[102],Dm[102],D[102];
    cin >> t;
    for(i=0; i<t; i++)
    {
        cin >> n >> Sh >> Sm;
        vector <int> pv,nv;

        if(Sh>=12)
        {
            Sh-=12;
        }
        if(Sh==0)
        {
            Sh=12;
        }

        int p=(Sh*60)+Sm;
        for(j=0; j<n; j++)
        {
            cin>>H[i][j] >>M[i][j];
            if(H[i][j]>=12)
            {
                H[i][j]-=12;
            }
            if(H[i][j]==0)
            {
                H[i][j]=12;
            }
            D[i]=(H[i][j]*60)+M[i][j];
            if(D[i]>=0)
            {
                pv.push_back(D[i]);
            }
            else
            {
                nv.push_back(D[i]);
            }
        }
        if(pv.empty())
        {
            sort(nv.begin(),vec.end(), less<int>());
            Min=nv.at(0);
        }
        else
        {
            sort(pv.begin(),vec.end(),less<int>());
            Min=pv.at(0);

        }



        if(Sh<H[i][n-1] && Sm>M[i][n-1])
        {
            H[i][n-1]--;
            M[i][n-1]=M[i][n-1]+60;
            Dh[i]=H[i][n-1]-Sh;
            Dm[i]=M[i][n-1]-Sm;

        }
        else if(Sh<=H[i][n-1] && Sm<=M[i][n-1])
        {
            Dh[i]=H[i][n-1]-Sh;
            Dm[i]=M[i][n-1]-Sm;
        }

        else if(Sh>H[i][n-1] && Sm<=M[i][n-1])
        {
            Dh[i]= H[i][n-1]-Sh+12;
            Dm[i]=M[i][n-1]-Sm;
        }
        else
        {
            Dh[i]= H[i][n-1]-Sh+12;
            Dm[i]=M[i][n-1]-Sm;

            Dh[i]--;
            Dm[i]+=60;


        }
    }
    for(i=0; i<t; i++)
    {
        cout<<Dh[i]<<" "<<Dm[i]<<endl;
    }

}
