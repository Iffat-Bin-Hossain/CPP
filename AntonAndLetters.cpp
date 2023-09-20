#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    getline(cin, str);
    int A[26]={0};
    for (int i = 1; i < str.size()-1; i+=3)
    {
        A[str[i] - 97]++;
    }
    int count = 0;
    for (int i = 0; i < 26; i++)
    {
        if (A[i] != 0)
        {
            count++;
        }
    }
    cout<<count;
}