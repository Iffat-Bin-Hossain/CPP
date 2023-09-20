#include <bits/stdc++.h>
using namespace std;
bool compareWeight(pair<int, pair<int, int>> edge1, pair<int, pair<int, int>> edge2)
{
    return edge1.first < edge2.first;
}
int find(int x, int parents[])
{
    if (x != parents[x])
    {
        return parents[x] = find(parents[x], parents);
    }
    else
    {
        return x;
    }
}
void Union(int x, int y, int parents[])
{
    int px = find(x, parents);
    int py = find(y, parents);
    parents[px] = py;
}
int main()
{
    int vertex, edges;
    float teleCost;
    cin >> vertex >> edges >> teleCost;
    pair<int, pair<int, int>> allEdges[edges];

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        int w;
        cin >> u >> v >> w;
        allEdges[i] = make_pair(w, make_pair(u, v));
    }
    sort(allEdges, allEdges + edges, compareWeight);
    int parents[vertex];
    for (int i = 0; i < vertex; i++)
    {
        parents[i] = i;
    }
    float minCount = 0;
    for (int i = 0; i < edges; i++)
    {
        int px = find(allEdges[i].second.first, parents);
        int py = find(allEdges[i].second.second, parents);
        if (px != py)
        {
            Union(px, py, parents);
            if (teleCost < allEdges[i].first)
            {
                minCount += teleCost;
            }
            else
            {
                minCount += allEdges[i].first;
            }
        }
    }
    cout << minCount << endl;
}