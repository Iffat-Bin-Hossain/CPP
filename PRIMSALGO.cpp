#include <bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    int vertex, edges;
    cout << "Enter vertex and edges:";
    cin >> vertex >> edges;
    vector<pair<int, int>> adjList[vertex];

    vector<int>visited;
    for (int i = 0; i < vertex; i++)
    {
        visited.push_back(0) ;
    }
    cout << "Enter incidents and weight:" << endl;
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        int w;
        cin >> u >> v >> w;
        adjList[u].push_back({w, v});
        adjList[v].push_back({w, u});
    }
    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < adjList[i].size(); j++)
        {
            cout << "(" << adjList[i][j].first << "," << adjList[i][j].second << ")";
        }
        cout << endl;
    }
    vector<pair<int, int>> MST;
    int source;
    cout << "Enter source:";
    cin >> source;



    pq.push({0, {-1, source}});
    visited[source] = 1;
    int minCost = 0;
    while (!pq.empty())
    {
        auto Min = pq.top();
        pq.pop();
        if (Min.second.first != -1 && !visited[Min.second.second])
        {
            visited[Min.second.second] = 1;
            MST.push_back({Min.second.first, Min.second.second});
            minCost += Min.first;
        }
        for (auto it : adjList[Min.second.second])
        {
            if (!visited[it.second])
            {
                pq.push({it.first, {Min.second.second, it.second}});
            }
        }
    }
    cout << "MST:" << endl;
    for (int i = 0; i < MST.size(); i++)
    {
        cout << "(" << MST[i].first << " " << MST[i].second << ")" << endl;
    }
    cout << "Minimum Cost:" << minCost << endl;
}