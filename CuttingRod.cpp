#include <bits/stdc++.h>
using namespace std;
int main()
{
    int rodLength;
    cin >> rodLength;
    int n; // Permitted Cutting Portion
    cin >> n;
    int len[n];
    int profit[n];
    for (int i = 0; i < n; i++)
    {
        cin >> len[i] >> profit[i];
    }
    int Table[n + 1][rodLength + 1];
    for (int i = 0; i <= n; i++)
    {
        Table[i][0] = 0;
    }
    for (int i = 0; i <= rodLength; i++)
    {
        Table[0][i] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=rodLength;j++){
            if(i>j){
                Table[i][j] = Table[i-1][j];
            }
            else{
                Table[i][j] = max(Table[i-1][j],Table[i][j-len[i-1]]+profit[i-1]);
            }
        }
    }
    //print Table
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=rodLength;j++){
    //         cout<<Table[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<Table[n][rodLength];
}