#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int A[26]={0};
    char S[50];
    cin>>S;
    int L=strlen(S);
    for(int i=0;i<L;i++)
    {
        S[i] = toupper(S[i]);
        int j=S[i]-65;
        A[j]++;

    }
    int C=0;
    for(int j=0;j<26;j++)
    {
        if(A[j]>1)
        {
          C+=A[j];
        }
    }
cout<<C;
}
