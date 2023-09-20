#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        int flag1 = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (A[j] <= A[i])
            {
                flag1 = 0;
                break;
            }
        }
        int flag2=1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (A[j] >=A[i])
            {
                flag2 = 0;
                break;
            }
        }
        if(flag1==1 || flag2==1){
            count++;
        }

    }
    cout<<count<<endl;
}