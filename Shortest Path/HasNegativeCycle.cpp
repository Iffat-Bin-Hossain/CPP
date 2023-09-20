//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define INT_MAX 2147483647
// } Driver Code Ends

class Solution
{
public:
    int isNegativeWeightCycle(int vertex, vector<vector<int>> edges)
    {
        // Code here
        int cost[vertex][vertex];
        for (int i = 0; i < vertex; i++)
        {
            for (int j = 0; j < vertex; j++)
            {
                if (i != j)
                {
                    cost[i][j] = INT_MAX;
                }
            }
        }
        for (auto i = edges.begin(); i != edges.end(); i++)
        {
            cost[(*i).at(0)][(*i).at(1)] = (*i).at(2);
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
        for(int i = 0; i < vertex; i++){
            for(int j = 0; j < vertex; j++){
                cout<<cost[i][j]<<" ";
            }
            cout<<endl;
        }
        for (int i = 0; i < vertex; i++)
        {
            if (cost[i][i] < 0)
            {
                return 1;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            edges.push_back({x, y, z});
        }
        Solution obj;
        int ans = obj.isNegativeWeightCycle(n, edges);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends