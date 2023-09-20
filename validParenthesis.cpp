//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> par;
        for (int i = 0; i < x.size(); i++)
        {
            if ((x[i] == ']' || x[i] == '}' || x[i] == ')') && par.size() == 0)
            {
                par.push(x[i]);
            }
            else if ((x[i] == ']' && par.top() == '[') || (x[i] == '}' && par.top() == '{') || (x[i] == ')' && par.top() == '('))
            {
                par.pop();
            }

            else
            {
                par.push(x[i]);
            }
        }
        if (par.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    string a;
    cin >> t;
    while (t--)
    {
        cin >> a;
        Solution obj;
        if (obj.ispar(a))
            cout << "balanced" << endl;
        else
            cout << "not balanced" << endl;
    }
}
// } Driver Code Ends