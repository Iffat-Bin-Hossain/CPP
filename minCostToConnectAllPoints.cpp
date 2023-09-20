#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int v = points.size();
        vector<pair<int, pair<int, int>>> adj[v];
        for (int i = 0; i < v; i++)
        {
            for (int j = i + 1; j < v; j++)
            {
                int d = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({d, {i, j}});
                adj[j].push_back({d, {j, i}});
            }
        }
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int visited[v] = {0};
        pq.push({0, {-1, 0}});
        int minCost = 0;
        while (!pq.empty())
        {
            auto min = pq.top();
            pq.pop();

            if (visited[min.second.second] == 0)
            {
                visited[min.second.second] = 1;
                minCost += min.first;
            }
            else
            {
                continue;
            }
            for (auto i : adj[min.second.second])
            {
                if (visited[i.second.second] == 0)
                {
                    pq.push(i);
                }
            }
        }
        return minCost;
    }
};
int main()
{
    vector<vector<int>> points;
    int i = 5;
    while (i--)
    {
        vector<int> vertex;
        int x, y;
        cin >> x >> y;
        vertex.push_back(x);
        vertex.push_back(y);
        points.push_back(vertex);
    }
    Solution soln;
    int minCost = soln.minCostConnectPoints(points);
    cout << minCost << endl;
}