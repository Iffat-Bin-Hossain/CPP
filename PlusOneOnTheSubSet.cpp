#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        long long int A[n];
        long long int Max = INT_MIN;
        long long int Min = LONG_LONG_MAX;
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
            Max = max(Max, A[i]);
            Min = min(Min, A[i]);
        }
        cout<<Max-Min<<endl;
    }
}