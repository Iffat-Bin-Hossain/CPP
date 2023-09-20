#include <bits/stdc++.h>
using namespace std;
bool compareWeight(pair<int, pair<int, int>> edge1, pair<int, pair<int, int>> edge2)
{
    return edge1.first > edge2.first;
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
   freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdin);
    int vertex, edges;
    cout << "Enter vertex and edges:";
    cin >> vertex >> edges;
    pair<int, pair<int, int>> allEdges[edges];

    cout << "Enter incidents and weight:" << endl;
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        int w;
        cin >> u >> v >> w;
        allEdges[i] = make_pair(w, make_pair(u, v));
    }
    sort(allEdges, allEdges + edges, compareWeight);
    vector<pair<int,pair<int, int>>> MPST;
    int parents[vertex];
    for (int i = 0; i < vertex; i++)
    {
        parents[i] = i;
    }

    int maxCount = 1;
    for (int i = 0; i < edges; i++)
    {
        int px = find(allEdges[i].second.first, parents);
        int py = find(allEdges[i].second.second, parents);
        if (px != py)
        {
            MPST.push_back({allEdges[i].first,{allEdges[i].second.first, allEdges[i].second.second}});
            Union(px, py, parents);
            maxCount *= allEdges[i].first;
        }
    }
    cout << "Maximum Product Spanning Tree:" << endl;
    for (int i = 0; i < MPST.size(); i++)
    {
        cout << "(" << MPST[i].first << " " << MPST[i].second.first<<" "<<MPST[i].second.second << ")"
             << " ";
    }
    cout << endl;
    cout << "Maximum Product:" << maxCount << endl;
}