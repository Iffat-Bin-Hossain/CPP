#include <bits/stdc++.h>
using namespace std;
int CheapestFLight(int vertex, vector<vector<int>> &flights, int source, int destination, int K)
{
    vector<pair<int, pair<int, int>>> adj[vertex];
    for (auto i = flights.begin(); i != flights.end(); i++)
    {
        adj[(*i).at(0)].push_back({(*i).at(2), {(*i).at(0), (*i).at(1)}});
    }
    vector<int> distance(vertex, INT_MAX);
    queue<pair<int, pair<int, int>>> Q; //{stops,{source,cost}}
    distance[source] = 0;
    Q.push({0, {source, 0}});
    while (!Q.empty())
    {
        auto x = Q.front();
        Q.pop();
        int stop = x.first;
        int u = x.second.first;
        int cost = x.second.second;

        if (stop > K)
            continue;
        else
        {

            for (auto i = adj[u].begin(); i != adj[u].end(); i++)
            {
                int v = (*i).second.second;
                int w = (*i).first;
                if (w + cost < distance[v] && stop <= K)
                {
                    distance[v] = w + cost;
                    Q.push({stop + 1, {v, distance[v]}});
                }
            }
        }
    }
    if (distance[destination] == INT_MAX)
    {
        return -1;
    }
    else
    {
        return distance[destination];
    }
}
int main()
{
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    int vertex, source, distance, k;
    vector<vector<int>> flights;
    cin >> vertex >> source >> distance >> k;
    while (!feof(stdin))
    {
        int u, v, w;
        cin >> u >> v >> w;
        vector<int> edges;
        edges.push_back(u);
        edges.push_back(v);
        edges.push_back(w);
        flights.push_back(edges);
    }
}