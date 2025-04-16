#include <bits/stdc++.h>
using namespace std;
string reverseStr(string &str)
{
    int n = str.length();

    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);

    return str;
}
int binToDec(string s)
{
    int dec = 0;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        dec += (s[i] - 48) * pow(2, s.length() - 1 - i);
    }
    return dec;
}
string decToBin(int num)
{
    string bin = "";
    int div = num;
    while (div != 0)
    {
        int rem = div % 2;
        div = div / 2;
        bin = bin + to_string(rem);
    }
    return reverseStr(bin);
}
string addBinary(string a, string b)
{
    return decToBin(binToDec(a) + binToDec(b));
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << addBinary(s1, s2) << endl;
}