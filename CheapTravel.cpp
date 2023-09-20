#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    float s = b / m;
    int cost = 0;
    if (s < a)
    {
        int T = n;
        while (T - m >= 0)
        {
            T -= m;
            cost += b;
        }

        if ((T * a) > b)
        {
            cost += b;
        }
        else
        {
            cost += (T * a);
        }
    }
    else
    {
        cost += a * n;
    }
    cout << cost << endl;
}