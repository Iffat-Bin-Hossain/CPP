#include <bits/stdc++.h>
using namespace std;
int Sum(int A[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
    }
    return sum;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++)
        {
            A[i] = i + 1;
        }
        int p = n - 1;
        while (Sum(A, n) % n != 0)
        {
            if (A[p] < 1000)
            {
                A[p] = A[p] + (p + 1);
                if (A[p] > 1000)
                {
                    A[p] -= (p + 1);
                    p--;
                }
            }
            else
            {
                p--;
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
}