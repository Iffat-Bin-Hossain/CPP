//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
public:
    bool comparator(pair<int, pair<int, int>> edge1, pair<int, pair<int, int>> edge2)
    {
        return edge1.first > edge2.first;
    }
    void DFS(int source, vector<bool> &visited, vector<pair<int, pair<int, int>>> adj[])
    {
        visited[source] = true;
        for (auto i = adj[source].begin(); i != adj[source].end(); i++)
        {
            if (!visited[(*i).second.second])
            {
                DFS((*i).second.second, visited, adj);
            }
        }
    }
    bool allVisited(int vertex, vector<bool> visited)
    {
        for (int i = 0; i < vertex; i++)
        {
            if (!visited[i])
            {
                return false;
            }
        }
        return true;
    }
    int RevDelMST(int Arr[], int vertex, int edges)
    {
        int minCost = 0;
        vector<pair<int, pair<int, int>>> allEdges;
        vector<pair<int, pair<int, int>>> adj[vertex];
        int k = 0;
        for (int i = 0; i < edges; i++)
        {
            int u = Arr[k], v = Arr[k + 1], w = Arr[k + 2];
            allEdges.push_back({w, {u, v}});
            adj[u].push_back({w, {u, v}});
            adj[v].push_back({w, {v, u}});
            k += 3;
        }
        sort(allEdges.begin(), allEdges.end(), comparator);
        for (auto i = allEdges.begin(); i != allEdges.end(); i++)
        {
            vector<bool> visited(vertex);
            int u = (*i).second.first;
            int v = (*i).second.second;
            int w = (*i).first;
            adj[u].erase(find_if(adj[u].begin(), adj[u].end(), [&v, &w](pair<int, pair<int, int>> &p)
                                 { return p.second.second == v && p.first == w; }));
            adj[v].erase(find_if(adj[v].begin(), adj[v].end(), [&u, &w](pair<int, pair<int, int>> &p)
                                 { return p.second.second == u && p.first == w; }));

            DFS((*i).second.first, visited, adj);
            if (!allVisited(vertex, visited))
            {
                adj[(*i).second.first].push_back({(*i).first, {(*i).second.first, (*i).second.second}});
                adj[(*i).second.second].push_back({(*i).first, {(*i).second.second, (*i).second.first}});
                minCost += w;
            }
        }
        return minCost;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,E;
        cin>>V>>E;

        int Arr[3*E];
        for(int i=0; i<3*E; i++)
            cin>>Arr[i];

        Solution ob;
        cout << ob.RevDelMST(Arr,V,E) << endl;
    }
    return 0;
}
// } Driver Code Ends