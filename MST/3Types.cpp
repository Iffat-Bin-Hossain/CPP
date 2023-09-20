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
        return parents[x]=find(parents[x], parents);
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
    cin >> vertex >> edges;
    pair<int, pair<int, int>> allEdges[edges];

    int visited[vertex] = {0};
    for (int i = 0; i < edges; i++)
    {
        int u, v, t;
        cin >> u >> v >> t;
        allEdges[i] = {t, {u - 1, v - 1}};
    }
    sort(allEdges, allEdges + edges, compareWeight);
    vector<pair<int, int>> mMST;
    vector<pair<int, int>> wMST;
    int parents[vertex];
    for (int i = 0; i < vertex; i++)
    {
        parents[i] = i;
    }
    for (int i = 0; i < edges; i++)
    {
        int px = find(allEdges[i].second.first, parents);
        int py = find(allEdges[i].second.second, parents);
        if (px != py)
        {
            if (allEdges[i].first == 3 || allEdges[i].first == 2)
            {
                mMST.push_back({allEdges[i].second.first, allEdges[i].second.second});
                Union(px, py, parents);
            }
        }
    }
    int ref = find(1,parents);
    bool status1 = true;
    for (int i = 0; i < vertex; i++)
    {
        if (find(i,parents) != ref)
        {
            status1 = false;
            break;
        }
    }

    for (int i = 0; i < vertex; i++)
    {
        parents[i] = i;
    }
    int count3 = 0;
    for (int i = 0; i < edges; i++)
    {
        int px = find(allEdges[i].second.first, parents);
        int py = find(allEdges[i].second.second, parents);
        if (px != py)
        {

            if (allEdges[i].first == 3 || allEdges[i].first == 1)
            {
                if (allEdges[i].first == 3)
                {
                    count3++;
                }
                wMST.push_back({allEdges[i].second.first, allEdges[i].second.second});
                Union(px, py, parents);
            }
        }
    }
     ref = find(1,parents);
    bool status2 = true;
    for (int i = 0; i < vertex; i++)
    {
        if (find(i,parents) != ref)
        {
            status2 = false;
            break;
        }
    }
    if(status1 && status2){
cout << edges - (mMST.size() + wMST.size() - count3) << endl;

    }
    else{
        cout<<-1;
    }
}   