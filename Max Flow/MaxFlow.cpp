//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool hasPath(int source, int sink, vector<int> &parent, vector<int> adj[], vector<vector<int>> &residueGraph)
    {
        int vertex = residueGraph.size();
        vector<bool> visited(vertex, false);
        queue<int> Q;
        Q.push(source);
        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            for (auto i = adj[u].begin(); i != adj[u].end(); i++)
            {
                int v = (*i);
                if (!visited[v] && residueGraph[u][v] != 0)
                {
                    if (v == sink)
                    {
                        parent[v] = u;
                        return true;
                    }
                    Q.push(v);
                    parent[v] = u;
                    visited[v] = true;
                }
            }
        }
        return false;
    }

    int findMaxFlow(int vertex, int edges, vector<vector<int>> Edges)
    {
        vector<int> adj[vertex];
        vector<vector<int>> residueGraph(vertex, vector<int>(vertex, 0));
        for (auto i = 0; i < edges; i++)
        {
            adj[Edges[i][0]].push_back(Edges[i][1]);
            adj[Edges[i][1]].push_back(Edges[i][0]);
            residueGraph[Edges[i][0]][Edges[i][1]] += Edges[i][2];
            residueGraph[Edges[i][1]][Edges[i][0]] += Edges[i][2];
        }
        int source = 0, sink = vertex - 1;
        vector<int> parent(vertex, -1);
        int maxFlow = 0;
        while (hasPath(source, sink, parent, adj, residueGraph))
        {
            int node = sink;
            int minCut = INT_MAX;
            while (node != source)
            {
                minCut = min(minCut, residueGraph[parent[node]][node]);
                node = parent[node];
            }
            node = sink;
            while (node != source)
            {
                residueGraph[node][parent[node]] += minCut;
                residueGraph[parent[node]][node] -= minCut;
                node = parent[node];
            }
            maxFlow += minCut;
        }
        return maxFlow;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int i, j, N, M, u, v, w;
        int res;
        scanf("%d %d", &N, &M);
        vector<vector<int>> Edges;
        for (i = 0; i < M; i++)
        {
            scanf("%d %d %d", &u, &v, &w);
            Edges.push_back({u, v, w});
        }
        Solution obj;
        res = obj.findMaxFlow(N, M, Edges);
        cout << res << endl;
    }
    return 0;
}
// } Driver Code Ends