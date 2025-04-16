#include <bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle)
{
    int h = haystack.length();
    int n = needle.length();

    if (n == 0) {
        return 0;
    }

    cout << h << " " << n << endl;
    int i = 0, j = 0;
    
    while (i < h)
    {
        if (haystack[i] == needle[j])
        {
            j++;
            if (j == n)
            {
                return i - n + 1;
            }
        }
        else
        {
            i -= j; 
            j = 0;  
        }
        i++;
    }
    return -1;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << endl << strStr(s1, s2) << endl;
}
