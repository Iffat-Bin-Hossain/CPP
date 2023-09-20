#include <bits/stdc++.h>
using namespace std;
int main()
{
    
    long long int availableCoins[]={1,5,10,20,100};
    long long int n;
    cin >> n;
    long long int Table[5][n + 1];
    for (int i = 0; i <5; i++)
    {
        Table[i][0] = 0;
    }
    for (long long int i = 1; i <= n; i++)
    {
        if (i % availableCoins[0] == 0)
        {
            Table[0][i] = i / availableCoins[0];
        }
        else
        {
            Table[0][i] = 0;
        }
    }

    for (int i = 1; i < 5; i++)
    {
        for (long long int j = 1; j <= n; j++)
        {
            if (j >= availableCoins[i])
            {
                
                    Table[i][j] = min(Table[i][j - availableCoins[i]] + 1, Table[i - 1][j]);
             
            }
            else
            {
                Table[i][j] = Table[i - 1][j];
            }
        }
    }
    long long int minCoin = Table[4][n];
    cout<< minCoin << endl;
}