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
        if (n % 4 == 0)
        {
            cout << "YES" << endl;

            long long int l = n / 2;
            long long int ESum=0;
            long long int OSum=0;
            for (long long int i = 0; i < l; i++)
            {
                A[i] = (2 * i) + 2;
                ESum+=A[i];
                if (i != l - 1)
                {
                    A[l + i] = (2 * i) + 1;
                    OSum+=A[l+i];
                }
            }
            A[n-1]=ESum-OSum;
            for(long long int i = 0; i < n; i++){
                cout<<A[i]<<" ";
            }
            cout<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}