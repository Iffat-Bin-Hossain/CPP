#include<bits\stdc++.h>
using namespace std;
int longestValidParentheses(string s) {
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
        return s.length()-stk.size();
    }
int main(){
string s;
cin>>s;
cout<<longestValidParentheses(s);
}