#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        if (str.length() % 2 != 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            int flag=1;
            int l = str.length() / 2;
            for (int i = 0; i < l; i++)
            {
                if(str[i]!=str[l+i]){
                    flag=0;
                    break;
                }
            }
            if(flag==0){
                cout << "NO" << endl; 
            }
            else{
                 cout << "YES" << endl;
            }
        }
    }
}