#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    int l1 = s1.length();
    int l2 = s2.length();
    int Table[l1 + 1][l2 + 1];
    for (int i = 0; i <= l1; i++)
    {
        Table[i][0] = 0;
    }
    for (int i = 0; i <= l2; i++)
    {
        Table[0][i] = 0;
    }
    for (int i = 1; i <= l1; i++)
    {
        for (int j = 1; j <= l2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                Table[i][j] = Table[i - 1][j - 1] + 1;
            }
            else
            {
                Table[i][j] = 0;
            }
        }
    }
    int Max = Table[0][0];
    for (int i = 0; i <=l1; i++)
    {
        for (int j = 0; j <= l2; j++)
        {
            Max = max(Max, Table[i][j]);
        }
    }
    cout << Max << endl;
}