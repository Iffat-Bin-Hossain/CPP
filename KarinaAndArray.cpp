#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long int A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        int l = n * (n - 1);
        vector<long long int> B;
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                
                    B.push_back(A[i] * A[j]);
            }
        }
        cout << *max_element(B.begin(), B.end()) << endl;
    }
}