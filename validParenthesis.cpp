#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    stack<char> stk;
    for (int i = 0; i < s.length(); i++)
    {
        if (stk.empty())
        {
            stk.push(s[i]);
        }
        else if ((stk.top() == '(' && s[i] == ')') || 
                 (stk.top() == '{' && s[i] == '}') || 
                 (stk.top() == '[' && s[i] == ']'))
        {
            stk.pop();
        }
        else
        {
            stk.push(s[i]);
        }
    }
    return stk.empty();
}

int main(){
    string s;
    cin >> s;
    cout << (isValid(s) ? "true" : "false") << endl;
    return 0;
}
