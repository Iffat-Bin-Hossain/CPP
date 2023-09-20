#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int l1 = s1.size();
    int l2 = s2.size();
    int dpTable[l2 + 1][l1 + 1];
    for (int i = 0; i <= l1; i++)
        dpTable[0][i] = 2*i;
    for (int i = 0; i <= l2; i++)
        dpTable[i][0] = 2*i;

    for (int i = 1; i <= l2; i++)
        for (int j = 1; j <= l1; j++)
            if (s2[i - 1] == s1[j - 1])
                dpTable[i][j] = dpTable[i - 1][j - 1];
            else
                if(dpTable[i-1][j-1]<=dpTable[i][j-1] && dpTable[i-1][j-1]<=dpTable[i-1][j] )
                    dpTable[i][j] =dpTable[i-1][j-1] +1;//Substitution Cost 1
                else
                    dpTable[i][j] = min(min(dpTable[i - 1][j - 1], dpTable[i - 1][j]), dpTable[i][j - 1]) +2;//Insertion-Deletion Cost 2

    for (int i = 0; i <= l2; i++)
    {
        for (int j = 0; j <= l1; j++)
        {
            cout << dpTable[i][j] << "  ";
        }
        cout << endl;
    }
}