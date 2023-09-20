#include<iostream>
using namespace std;
int main()
{
    int t,n,i,j;
    char S[105];
    cin>>t;
    for(i=0; i<t; i++)
    {
        cin>>n;
        char Max='a';
        for(j=0; j<n; j++)
        {
            cin>>S[j];
            if(S[j]>Max)
            {
                Max=S[j];
            }


        }

cout<<((int)Max)-96<<endl;
    }

}

