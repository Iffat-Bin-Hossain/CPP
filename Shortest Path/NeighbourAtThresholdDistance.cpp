#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findTheCity(int vertex, vector<vector<int>> &edges, int distanceThreshold)
    {
        int cost[vertex][vertex];
        for (int i = 0; i < vertex; i++)
        {
            for (int j = 0; j < vertex; j++)
            {
                if (i == j)
                {
                    cost[i][j] = 0;
                }
                else
                {
                    cost[i][j] = INT_MAX;
                }
            }
        }
        for (auto i = edges.begin(); i != edges.end(); i++)
        {
            cost[(*i).at(0)][(*i).at(1)] = (*i).at(2);
            cost[(*i).at(1)][(*i).at(0)] = (*i).at(2);
        }

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
        int count[vertex];
        for (int i = 0; i < vertex; i++)
        {
            count[i] = 0;
        }

        for (int i = 0; i < vertex; i++)
        {
            for (int j = 0; j < vertex; j++)
            {
                if (cost[i][j] <= distanceThreshold && i != j)
                {
                    count[i]++;
                }
            }
        }
        int Min = count[0];
        int minIndex = 0;
        for (int i = 1; i < vertex; i++)
        {
            if (count[i] <= Min)
            {
                Min = count[i];
                minIndex = i;
            }
        }
        return minIndex;
    }
};
int main()
{
    ifstream fin("Neighbour.txt");
    vector<vector<int>> allEdges;
    int vertex, distanceThreshold;
    fin >> vertex >> distanceThreshold;
    while (!fin.eof())
    {
        vector<int> edges;
        int u, v, w;
        fin >> u >> v >> w;
        edges.push_back(u);
        edges.push_back(v);
        edges.push_back(w);
        allEdges.push_back(edges);
    }
    Solution sol;
    cout << sol.findTheCity(vertex, allEdges, distanceThreshold) << endl;
}