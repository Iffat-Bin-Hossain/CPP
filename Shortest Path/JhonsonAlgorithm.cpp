#include <bits/stdc++.h>
using namespace std;
vector<int> SSSP_By_Dijsktra_Algorithm(int source, vector<vector<pair<int, pair<int, int>>>> &adj)
{
    int vertex = adj.size();
    vector<int> distance(vertex, INT_MAX);
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    distance[source] = 0;
    pq.push({0, {-1, source}});
    while (!pq.empty())
    {
        auto min = pq.top();
        pq.pop();
        for (auto i = adj[min.second.second].begin(); i != adj[min.second.second].end(); i++)
        {
            if (distance[min.second.second] + (*i).first < distance[(*i).second.second])
            {
                distance[(*i).second.second] = distance[min.second.second] + (*i).first;
                pq.push({distance[(*i).second.second], {(*i).second.first, (*i).second.second}});
            }
        }
    }
    return distance;
}

vector<int> SSSP_By_BellmanFord_Algorithm(int source, vector<vector<pair<int, pair<int, int>>>> &adj)
{
    int vertex = adj.size();
    vector<int> distance(vertex, INT_MAX);
    distance[source] = 0;
    for (int i = 0; i < vertex - 1; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            for (auto k = adj[j].begin(); k != adj[j].end(); k++)
            {
                if (distance[j] + (*k).first < distance[(*k).second.second] && distance[j] != INT_MAX)
                {
                    distance[(*k).second.second] = distance[j] + (*k).first;
                }
            }
        }
    }
    int newDistance[vertex];
    for (int i = 0; i < vertex; i++)
    {
        newDistance[i] = distance[i];
    }
    for (int j = 0; j < vertex; j++)
    {
        for (auto k = adj[j].begin(); k != adj[j].end(); k++)
        {
            if (newDistance[j] + (*k).first < newDistance[(*k).second.second] && newDistance[j] != INT_MAX)
            {
                newDistance[(*k).second.second] = newDistance[j] + (*k).first;
            }
        }
    }
    for (int i = 0; i < vertex; i++)
    {
        if (newDistance[i] != distance[i])
        {
            vector<int> negdistance;
            negdistance.push_back(-1);
            return negdistance;
        }
    }
    return distance;
}
vector<vector<int>> APSP_By_Jhonson_Algorithm(vector<vector<pair<int, pair<int, int>>>> &adj)
{
    int vertex = adj.size();
    vector<vector<int>> cost(vertex);
    vector<vector<pair<int, pair<int, int>>>> modifiedAdj = adj;

    vector<pair<int, pair<int, int>>> newNode;
    for (int i = 0; i < vertex; i++)
    {
        newNode.push_back({0, {vertex, i}});
    }
    modifiedAdj.push_back(newNode);
    vector<int> vertexWeight = SSSP_By_BellmanFord_Algorithm(vertex, modifiedAdj);
    if (vertexWeight.size() == 1 && vertexWeight[0] == -1)
    {
        cout << "Negative Weight Cycle detected" << endl;
    }
    else
    {
        for (int i = 0; i < vertex; i++)
        {
            for (auto j = adj[i].begin(); j != adj[i].end(); j++)
            {
                (*j).first += (vertexWeight[(*j).second.first] - vertexWeight[(*j).second.second]);
            }
        }
        for (int i = 0; i < vertex; i++)
        {
            cost[i] = SSSP_By_Dijsktra_Algorithm(i, adj);
        }
        for (int i = 0; i < vertex; i++)
        {
            for (int j = 0; j < vertex; j++)
            {
                if (cost[i][j] != INT_MAX)
                {
                    cost[i][j] -= (vertexWeight[i] - vertexWeight[j]);
                }
            }
        }
    }
    return cost;
}
int main()
{
    freopen("APSP_Input.txt", "r", stdin);
    freopen("APSP_Output.txt", "w", stdout);
    int vertex, edges;
    cin >> vertex >> edges;
    vector<vector<pair<int, pair<int, int>>>> adj(vertex);

    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u ].push_back({w, {u, v}});
    }
    vector<vector<int>> cost = APSP_By_Jhonson_Algorithm(adj);
    for (int i = 0; i < cost.size(); i++)
    {
        for (int j = 0; j < cost.size(); j++)
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