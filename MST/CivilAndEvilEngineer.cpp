#include <bits/stdc++.h>
using namespace std;
bool compareWeight1(pair<int, pair<int, int>> edge1, pair<int, pair<int, int>> edge2)
{
    return edge1.first < edge2.first;
}
bool compareWeight2(pair<int, pair<int, int>> edge1, pair<int, pair<int, int>> edge2)
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
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        //cout<<endl;
        int n;
        cin >> n;
        vector<pair<int, pair<int, int>>> allEdges;
        int u = -1, v = -1, w = -1;
        while (u != 0 || v != 0 || w != 0)
        {
            cin >> u >> v >> w;
            if (u != 0 || v != 0 || w != 0)
                allEdges.push_back({w, {u, v}});
        }

        sort(allEdges.begin(), allEdges.end(), compareWeight1);
        int parents[n + 1];
        for (int i = 0; i < n + 1; i++)
        {
            parents[i] = i;
        }
        int minCount = 0;
        for (auto i = allEdges.begin(); i != allEdges.end(); i++)
        {
            int px = find((*i).second.first, parents);
            int py = find((*i).second.second, parents);
            if (px != py)
            {
                Union(px, py, parents);
                minCount += (*i).first;
            }
        }

        sort(allEdges.begin(), allEdges.end(), compareWeight2);
        for (int i = 0; i < n + 1; i++)
        {
            parents[i] = i;
        }
        int maxCount = 0;
        for (auto i = allEdges.begin(); i != allEdges.end(); i++)
        {
            int px = find((*i).second.first, parents);
            int py = find((*i).second.second, parents);
            if (px != py)
            {
                Union(px, py, parents);
                maxCount += (*i).first;
            }
        }
       if((minCount+maxCount)%2==0){
         cout<<"Case "<<i+1<<": "<<(minCount+maxCount)/2<<endl;
       }
       else{
        cout<<"Case "<<i+1<<": "<<(minCount+maxCount)<<"/2"<<endl;
       }
    }
}
