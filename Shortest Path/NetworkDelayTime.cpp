#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> shortestpath(int source, int vertex, vector<pair<int, pair<int, int>>> adj[])
    {
        vector<int> distance(vertex,INT_MAX);
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
    int networkDelayTime(vector<vector<int>> &times, int vertex, int source)
    {
        vector<pair<int, pair<int, int>>> adj[vertex];
        for (int i = 0; i < times.size(); i++)
        {
            int w = times[i][2], u = times[i][0]-1, v = times[i][1]-1;
            adj[u].push_back({w, {u, v}});
        }
        vector<int> distance = shortestpath(source-1, vertex, adj);
        int Max = distance[0];
        for (int i = 0; i < vertex; i++)
        {
            if (distance[i] == INT_MAX)
            {
                return -1;
            }
            Max = max(Max, distance[i]);
        }
        return Max;
    }
};
int main()
{
    ifstream fin("NetworkDelay.txt");
    vector<vector<int>> times;
    int vertex, source;
    fin >> vertex >> source;
    while (!fin.eof())
    {
        vector<int> edges;
        int u, v, w;
        fin >> u >> v >> w;
        edges.push_back(u);
        edges.push_back(v);
        edges.push_back(w);
        times.push_back(edges);
    }
    Solution sol;
    cout<< sol.networkDelayTime(times, vertex, source) << endl;
}