#include<iostream>
using namespace std;
int main()
{
    string s;
    int A[26]= {0};
    int n,i;
    int flag;
    cin>>n;
    cin>>s;

    for(i=0; i<n; i++)
    {
        if(s[i]<91)
        {
            A[s[i]-65]=1;
        }
        else
        {
            A[s[i]-97]=1;
        }
    }
    flag=0;
    for(i=0;i<26;i++){
        if(A[i]==0){
            flag=0;
            break;
        }
        else{
            flag=1;
        }
    }
    if(flag==0){
        cout<<"NO";
    }
    else{
        cout<<"YES";
    }


}
