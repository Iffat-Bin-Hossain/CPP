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
    for (int p = 0; p < t; p++)
    {
        int edges;
        cin >> edges;
        unordered_set<string> cities;
        vector<pair<int, pair<string, string>>> tempAdj;
        vector<pair<int, pair<int, int>>> allEdges;
        for (int j = 0; j < edges; j++)
        {
            string s1, s2;
            int w;
            cin >> s1 >> s2 >> w;
            tempAdj.push_back({w, {s1, s2}});
            if (!cities.count(s1))
            {
                cities.insert(s1);
            }
            if (!cities.count(s2))
            {
                cities.insert(s2);
            }
        }
        int vertex = cities.size();
        map<string, int> cityMap;
        int x = 0;
        for (auto i = cities.begin(); i != cities.end(); i++)
        {
            cityMap.insert(pair<string, int>(*i, x++));
        }

        for (auto i = tempAdj.begin(); i != tempAdj.end(); i++)
        {
            allEdges.push_back({(*i).first, {cityMap[(*i).second.first], cityMap[(*i).second.second]}});
        }

        sort(allEdges.begin(), allEdges.end(), compareWeight);
        int parents[vertex];
        for (int i = 0; i < vertex; i++)
        {
            parents[i] = i;
        }
        int minCount = 0;
        for (int i = 0; i < edges; i++)
        {
            int px = find(allEdges[i].second.first, parents);
            int py = find(allEdges[i].second.second, parents);
            if (px != py)
            {
                Union(px, py, parents);
                minCount += allEdges[i].first;
            }
        }
        int ref = find(1, parents);
        bool status = true;
        for (int i = 0; i < vertex; i++)
        {
            if (find(i, parents) != ref)
            {
                status = false;
                break;
            }
        }
        if(status){
        cout <<"Case "<<p+1<<": "<< minCount << endl;
        }
        else{
            cout <<"Case "<<p+1<<": Impossible"<< endl;
        }
    }
}