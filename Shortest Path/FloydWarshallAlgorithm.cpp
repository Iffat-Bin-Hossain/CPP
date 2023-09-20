#include <bits/stdc++.h>
using namespace std;
void floydWarshallAlgorithm(vector<vector<int>> &cost)
{
    int vertex = cost.size();
    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            for (int k = 0; k < vertex; k++)
            {
                if (cost[j][i] == INT_MAX || cost[i][k] == INT_MAX)
                {
                    cost[j][k] = min(cost[j][k], INT_MAX);
                }
                else
                {
                    cost[j][k] = min(cost[j][k], cost[j][i] + cost[i][k]);
                }
            }
        }
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
    floydWarshallAlgorithm(cost);
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
        cout << "\n";
    }
    return 0;
}