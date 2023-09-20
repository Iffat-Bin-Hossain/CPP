#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int Max, Min;
        int ans;
        if (a > b)
        {
            Max = a;
            Min = b;
        }
        else if (a == b)
        {
            ans = 2 * a * 2 * b;
            cout << ans << endl;
            continue;
        }
        else
        {
            Max = b;
            Min = a;
        }
        int l = 2 * Min;
        while (l < Max)
        {
            l++;
        }
        ans = pow(l, 2);
        cout << ans << endl;
    }
}