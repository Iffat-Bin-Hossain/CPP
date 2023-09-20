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
        return find(parents[x], parents);
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
        vector<pair<int, pair<int, int>>> allEdges;
        int vertex;
        cin >> vertex;
        int totalCost = 0;
        for (int i = 0; i < vertex; i++)
        {
            for (int j = 0; j < vertex; j++)
            {
                int w;
                cin >>w;
                totalCost +=w;
                if (i != j && w!= 0)
                {
                    allEdges.push_back({w, {i, j}});
                }
            }
        }
        sort(allEdges.begin(), allEdges.end(), compareWeight);
        int parents[vertex];
        for (int i = 0; i < vertex; i++)
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
        int ref = find(0, parents);
        bool status = true;
        for (int i = 1; i < vertex; i++)
        {
            if (find(i, parents) != ref)
            {
                status = false;
                break;
            }
        }
        if(status){
        cout <<"Case "<<p+1<<": "<< totalCost-minCount << endl;
        }
        else{
            cout <<"Case "<<p+1<<": "<<-1<< endl;
        }
    }
}