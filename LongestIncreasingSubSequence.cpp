#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin >> n;
    long long int A[n];
    for (long long int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    long long int Table[n];
    Table[0] = 1;
    for (long long int i = 1; i < n; i++)
    {
        if (A[i] >= A[i - 1])
        {
            Table[i]=Table[i-1]+1;
        }
        else{
            Table[i]=1;
        }
    }
    long long int Max=Table[0];
    for(long long int i = 1; i < n; i++){
        Max=max(Max,Table[i]);
    }
    cout<<Max<<endl;
}