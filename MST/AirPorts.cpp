// Add some code
#include <bits/stdc++.h>
using namespace std;
int find(int x, int parents[])
{
    if (x == parents[x])
    {
        return x;
    }
    return parents[x]=find(parents[x], parents);
}
void Union(int x, int y, int parents[])
{
    int px = find(x, parents);
    int py = find(y, parents);
    parents[px] = py;
}
int main()
{
    int t;
    cin >> t;
    for (int p = 0; p < t; p++)
    {
        int n, m, a, u, v, w, minCount = 0, airportCount = 0;
        cin >> n >> m >> a;
        vector<pair<int, pair<int, int>>> allEdges;
        int distinct = n;
        int parents[n];
        for (int i = 0; i < n; i++)
        {
            parents[i] = i;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v >> w;
            allEdges.push_back({w, {u - 1, v - 1}});
        }
        sort(allEdges.begin(), allEdges.end());

        for (int i = 0; i < m; i++)
        {
            int px = find(allEdges[i].second.first, parents);
            int py = find(allEdges[i].second.second, parents);
            if (px != py)
            {
                Union(px, py, parents);
                distinct--;
                if (allEdges[i].first >= a)
                {
                    airportCount++;
                    minCount += a;
                }
                else
                {
                    minCount += allEdges[i].first;
                }
            }
        }
        minCount += (distinct * a);
        airportCount += distinct;
        cout << "Case " << p + 1 << ": " << minCount << " " << airportCount << endl;
    }
}