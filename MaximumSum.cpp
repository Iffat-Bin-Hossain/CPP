#include <bits/stdc++.h>
using namespace std;
int Sum(int A[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=A[i];
    }
    return sum;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (A[j] < A[i])
                {
                    swap(A[j], A[i]);
                }
            }
        }
        int ans;
        int size = n;
        while (k--)
        {
            if (size >= 2)
            {
                

                if (A[0] + A[1] > A[size - 1])
                {
                    A[size - 1] = 0;
                    size--;
                }
                else
                {
                    for (int i = 0; i < size-2; i++)
                    {
                        A[i] = A[i + 2];
                        
                    }
                    size -= 2;
                }
                ans=Sum(A,size);
            }
        }
        cout<<ans<<endl;
    }
}