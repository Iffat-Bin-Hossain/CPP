
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> bellman_ford(int vertex, vector<vector<int>> & allEdges, int source)
    {
        // Code here
        vector<pair<int, pair<int, int>>> adj[vertex];
        for (auto i = allEdges.begin(); i != allEdges.end(); i++)
        {
            adj[(*i).at(0)].push_back({(*i).at(2), {(*i).at(0), (*i).at(1)}});
        }
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
};

//{ Driver Code Starts.

int main()
{
    int vertex, edges;
    cin >> vertex >> edges;
    vector<vector<int>> adj;

    for (int i = 0; i < edges; ++i)
    {
        vector<int> temp;
        for (int j = 0; j < 3; ++j)
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        adj.push_back(temp);
    }

    int src;
    cin >> src;

    Solution obj;
    vector<int> res = obj.bellman_ford(vertex, adj, src);

    for (auto x : res)
    {
        cout << x << " ";
    }
    cout << "\n";
}

// } Driver Code Ends