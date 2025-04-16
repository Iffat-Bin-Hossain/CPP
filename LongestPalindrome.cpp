#include <bits/stdc++.h>
using namespace std;


int longestPalindrome(string s)
{
    unordered_map<char, int> map;
    
    for (int i = 0; i < s.length(); i++)
    {
        map[s[i]]++;
    }
    
    
    int l = 0;
    bool found = false;
    for (auto &it : map)
    {
        
        
        if (it.second % 2 == 0)
        {
            l += it.second;
        }
        else
        {
            l += it.second - 1;
            found = true;
        }
        
    }
    if (found)
            return l + 1;
        return l;
}
int main()
{
    cout << longestPalindrome("abccccdd");
}