#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char S[102];
    int i;
    int flag=1;
    cin>>S;


    for(i=1; i<strlen(S); i++)
    {
        if(S[i]<=90)
        {
            flag=flag*1;

        }
        else{
            flag=flag*0;
        }

    }
    if(flag==1)
    {
     if(S[0]>=97){
        S[0]-=32;
     }
     else{
        S[0]+=32;
     }
     for(i=1;i<strlen(S);i++)
     {
       if(S[i]<=90){
        S[i]+=32;
       }

     }

    }
    cout<<S;

}
