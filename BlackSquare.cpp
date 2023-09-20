#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int a1, a2, a3, a4;
    string str;
    cin >> a1 >> a2 >> a3 >> a4;
    cin >> str;
    long long int Sum = 0;
    for (long long int i = 0; i < str.size(); i++)
    {
        if (str[i] == '1')
        {
            Sum += a1;
        }
        else if (str[i] == '2')
        {
            Sum += a2;
        }
        else if (str[i] == '3')
        {
            Sum += a3;
        }
        else
        {
            Sum += a4;
        }
    }
    cout << Sum << endl;
}