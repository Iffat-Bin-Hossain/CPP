#include <bits/stdc++.h>
using namespace std;
string reverseStr(string &str)
{
    int n = str.length();

    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
    return str;
}
string addBinary(string a, string b)
{
    int l;
    string s;
    if (a.length() > b.length())
    {
        l = a.length() - b.length();
        s = b;
        for (int i = 0; i < l; i++)
        {
            s = "0" + s;
        }
        b = s;
    }
    else
    {
        l = b.length() - a.length();
        s = a;
        for (int i = 0; i < l; i++)
        {
            s = "0" + s;
        }
        a = s;
    }
    int rem = 0;
    string sum;
    for (int i = a.length() - 1; i >= 0; i--)
    {
        if (rem == 0)
        {
            if (a[i] == '1' && b[i] == '1')
            {
                sum += "0";
                rem = 1;
            }
            else if (a[i] == '0' && b[i] == '0')
            {
                sum += "0";
                rem = 0;
            }
            else
            {
                sum += "1";
                rem = 0;
            }
        }

        else
        {
            if (a[i] == '1' && b[i] == '1')
            {
                sum += "1";
                rem = 1;
            }
            else if (a[i] == '0' && b[i] == '0')
            {
                sum += "1";
                rem = 0;
            }
            else
            {
                sum += "0";
                rem = 1;
            }
        }
    }
    if (rem == 1)
        sum += "1";
    return reverseStr(sum);
}
int main()

{
    string s1, s2;
    cin >> s1 >> s2;
    cout << addBinary(s1, s2);
}