#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    string S;
    int flag=0;
    cin>>S;
    for(int i=0; i<S.size(); i++)
    {
        if(S[i]=='H'||S[i]=='Q'||S[i]=='9')
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
}
