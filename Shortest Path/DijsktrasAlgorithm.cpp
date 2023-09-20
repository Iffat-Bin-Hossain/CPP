#include <bits/stdc++.h>
using namespace std;

int *shortestpath(int source, int vertex, vector<pair<int, pair<int, int>>> adj[])
{
    int *distance;
    distance = new int[vertex];
    for (int i = 0; i < vertex; i++)
    {
        distance[i] = INT_MAX;
    }
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
                pq.push({distance[(*i).second.second],{(*i).second.first,(*i).second.second}});
            }
            
        }
    }
    return distance;
}
int main()
{
    int vertex, edges;
    cin >> vertex >> edges;
    vector<pair<int, pair<int, int>>> adj[vertex];

    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({abs(w), {u, v}});
    }
    int source;
    cin>>source;
    cout << "Shortest distance from sources:" << endl;
    int *distance = shortestpath(source, vertex, adj);
    for (int i = 0; i < vertex; i++)
    {
        cout << distance[i] << " ";
    }

}