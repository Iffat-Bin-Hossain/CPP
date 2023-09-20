#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int primeCount=0;
    for (int i = n+1; i <m; i++)
    {
        int count = 1;
        for (int j = 2; j <=i; j++)
        {
            if (i % j == 0)
            {
                count++;
            }
        }
        if(count==2){
            primeCount++;
        }
    }
    if(primeCount==0)
    {
        int count = 1;
        for (int j = 2; j <=m; j++)
        {
            if (m % j == 0)
            {
                count++;
            }
        }
        if(count==2){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    else{
         cout<<"NO"<<endl;
    }
}