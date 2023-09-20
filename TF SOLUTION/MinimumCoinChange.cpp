#include <bits/stdc++.h>
using namespace std;
int main()
{
    int numberOfCoins;
    vector<int> availableCoins;
    cout << "Available Coins:";
    cin >> numberOfCoins;
    for (int i = 0; i < numberOfCoins; i++)
    {
        int coinValue;
        cin >> coinValue;
        availableCoins.push_back(coinValue);
    }
    for(int i=0;i<availableCoins.size();i++){
        for(int j=i+1;j<availableCoins.size();j++){
            if(availableCoins[j]<availableCoins[i]){
                swap(availableCoins[j],availableCoins[i]);
            }
        }
    }
    int n;
    cout << "Amount:";
    cin >> n;
    int Table[numberOfCoins][n + 1];
    for (int i = 0; i < numberOfCoins; i++)
    {
        Table[i][0] = 0;
    }
    for (int i = 1; i <= n; i++)
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

    for (int i = 1; i < numberOfCoins; i++)
    {
        for (int j = 1; j <= n; j++)
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
    cout << "DP Table:" << endl;
    for (int i = 0; i < numberOfCoins; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << Table[i][j] << " ";
        }
        cout << endl;
    }
    int minCoin = Table[numberOfCoins - 1][n];
    cout << "Minimum Coin:" << minCoin << endl;
    vector<int> takenCoin;
    int i = numberOfCoins - 1;
    int j = n;
    while (i >= 0 && j > 0)
    {
        if (Table[i][j] == Table[i - 1][j])
        {
            i--;
        }
        else
        {
            j = j - availableCoins[i];
            takenCoin.push_back(availableCoins[i]);
        }
    }
    cout << "Taken Coins:";
    for (int i = takenCoin.size() - 1; i >= 0; i--)
    {
        cout << takenCoin.at(i) << " ";
    }
}
