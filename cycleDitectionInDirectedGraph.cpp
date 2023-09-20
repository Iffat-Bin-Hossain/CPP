//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool cycleUtil(int v, bool visited[], bool recStack[], vector<int> adj[])
    {
        if (!visited[v])
        {
            visited[v] = true;
            recStack[v] = true;
            for (auto i = adj[v].begin(); i != adj[v].end(); i++)
            {
                if(! visited[*i])
                {
                    if (cycleUtil(*i, visited, recStack, adj))
                    {
                        return true;
                    }
                }
                else if (visited[*i] && recStack[*i])
                {
                    return true;
                }
            }
        }
        recStack[v] = false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[])
    {
        // Code here
        bool visited[V]={false};
        bool recStack[V]={false};
        for (int i = 0;i < V; i++)
        {
            if (!visited[i])
            {
                if (cycleUtil(i, visited, recStack, adj))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
