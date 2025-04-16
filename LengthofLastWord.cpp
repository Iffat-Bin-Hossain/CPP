#include <bits/stdc++.h>
using namespace std;
int main()
{

    string str = "luffy is still joyboy";

    string s;

    stringstream ss(str);

    vector<string> v;

    while (getline(ss, s, ' '))
    {
        if (s != "")
        {
            v.push_back(s);
        }
    }

    cout << v[v.size() - 1].size() << endl;
}