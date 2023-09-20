#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int k, l, m, n, d;
    cin >> k >> l >> m >> n >> d;
    long long int A[d] = {0};
    long long int count=0;
    for (long long int i = 1; i <= d; i++)
    {
        if (i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0)
        {
            if (A[i - 1] == 0)
            {
                A[i - 1] = 1;
                count++;
            }
        }
    }
    cout<<count<<endl;
}