#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string s)
{

    string new_s = "";

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 65 && s[i] < 91)
        {
            new_s += s[i] + 32;
        }
        else if ((s[i] >= 97 && s[i] < 123) || (s[i] >= 48 && s[i] <= 57))
        {
            new_s += s[i];
        }
    }

    int l = new_s.size();

    for (int i = 0; i < (l / 2); i++)
    {
        if (new_s[i] != new_s[l - 1 - i])
        {
            return false;
        }
    }
    return true;
}

int main()
{

    cout << boolalpha << isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << isPalindrome(" ") << endl;
    cout << isPalindrome("race a car") << endl;
    cout << isPalindrome("0P");
}