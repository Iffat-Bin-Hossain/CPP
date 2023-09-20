#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s1 = "that I hate ";
    string s2 = "that I love ";
    cout << "I hate ";
    for (int i = 1; i < n; i++)
    {
        if (i % 2 == 0)
            cout << s1;
        else
            cout << s2;
    }
    cout << "it";
}