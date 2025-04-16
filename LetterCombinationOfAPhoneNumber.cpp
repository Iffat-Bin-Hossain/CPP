#include <bits/stdc++.h>
using namespace std;
vector<string> myMap(int n)
{
    if (n == 2)
        return {"a", "b", "c"};
    else if (n == 3)
        return {"d", "e", "f"};
    else if (n == 4)
        return {"g", "h", "i"};
    else if (n == 5)
        return {"j", "k", "l"};
    else if (n == 6)
        return {"m", "n", "o"};
    else if (n == 7)
        return {"p", "q", "r", "s"};
    else if (n == 8)
        return {"t", "u", "v"};
    else if (n == 9)
        return {"w", "x", "y", "z"};
    else
        return {};
}
void Solve(string digits, vector<string> &ans, string current, int index)
{
    
    if (index == digits.length())
    {
        ans.push_back(current);
        return;
    }
int p=((int)digits[index])-48;
    for (auto x : myMap(p))
    {
        Solve(digits, ans, current + x, index + 1);
    }
}
vector<string> letterCombinations(string digits)
{
    vector<string> ans;
    
    if (digits.length() == 0){
return ans;
    }
        
    Solve(digits, ans, "", 0);
    return ans;
}
int main()
{
    string s;
    cin >> s;
    for (auto x : letterCombinations(s))
    {
        cout << x << " ";
    }
}