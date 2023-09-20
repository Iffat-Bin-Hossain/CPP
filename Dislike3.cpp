#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        int count = 0;
        int i = 1;
        while (count != k)
        {
            if ((i % 3 != 0 && i%10!=3))
            {
                    count++;
                    
                
            }
            i++;
        }
        cout<<i-1<<endl;
    }
}