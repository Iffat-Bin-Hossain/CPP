#include <bits/stdc++.h>
using namespace std;
void MatrixMultiplication(vector<vector<int>> &cost1)
{
    int vertex = cost1.size();
    vector<vector<int>> cost2 = cost1;

    for (int t = 1; t <= vertex; t *= 2)
    {
        for (int i = 0; i < vertex; i++)
        {
            for (int j = 0; j < vertex; j++)
            {
                int Min = cost1[i][j];
                for (int k = 0; k < vertex; k++)
                {
                    if (cost1[i][k] == INT_MAX || cost1[k][j] == INT_MAX)
                    {
                        Min = min(Min, INT_MAX);
                    }
                    else
                    {
                        Min = min(Min, cost1[i][k] + cost1[k][j]);
                    }
                }
                cost2[i][j] = Min;
            }
        }
        cost1 = cost2;
    }
    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            if (cost2[i][j] == INT_MAX)
            {
                cout << "INF ";
            }
            else
            {
                cout << cost2[i][j] << " ";
            }
        }
        cout << endl;
    }
}
int main()
{
    freopen("APSP_Input.txt", "r", stdin);
    freopen("APSP_Output.txt", "w", stdout);
    int vertex, edges;
    cin >> vertex >> edges;
    vector<vector<int>> cost(vertex, vector<int>(vertex, INT_MAX));
    for (int i = 0; i < vertex; i++)
    {
        cost[i][i] = 0;
    }
    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        cost[u][v] = w;
    }
    MatrixMultiplication(cost);
    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            if (cost[i][j] == INT_MAX)
            {
                cout << "INF ";
            }
            else
            {
                cout << cost[i][j] << " ";
            }
        }
        cout << endl;
    }
}