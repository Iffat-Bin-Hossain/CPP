#include <bits/stdc++.h>
using namespace std;

vector<int> shortestpath(int source, int vertex, vector<pair<int, pair<int, int>>> adj[])
{
    vector<int> distance(vertex, INT_MAX);
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    distance[source] = 0;
    pq.push({0, {-1, source}});
    while (!pq.empty())
    {
        auto min = pq.top();
        pq.pop();
        for (auto i = adj[min.second.second].begin(); i != adj[min.second.second].end(); i++)
        {
            if (distance[min.second.second] + (*i).first < distance[(*i).second.second])
            {
                distance[(*i).second.second] = distance[min.second.second] + (*i).first;
                pq.push({distance[(*i).second.second], {(*i).second.first, (*i).second.second}});
            }
        }
    }
    return distance;
}
int main()
{
    freopen("SpecialPath.txt", "r", stdin);
    unordered_set<pair<int, int>> points;
    vector<int> start, target;
    vector<vector<int>> specialRoads;
    int startX, startY, targetX, targetY;
    cin >> startX >> startY >> targetX >> targetY;
    points.insert({startX, startY});
    points.insert({targetX, targetY});
    start.push_back(startX);
    start.push_back(startY);
    target.push_back(targetX);
    target.push_back(targetY);
    while (!feof(stdin))
    {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        specialRoads.push_back({x1, y1, x2, y2, c});
        points.insert({x1, y1});
        points.insert({x2, y2});
    }

    map<pair<int, int>, int> Map;
    int k = 0;
    for (auto i = points.begin(); i != points.end(); i++)
    {
        Map.insert({*i, k++});
    }
    // for (auto i = Map.begin(); i != Map.end(); i++)
    // {
    //     cout << "(" << (*i).first.first << "," << (*i).first.second << ")"
    //          << "--> " << (*i).second << endl;
    // }
    int vertex = points.size();
    vector<pair<int, pair<int, int>>> adj[vertex];
    for (auto i = points.begin(); i != points.end(); i++)
    {
        for (auto j = i; j != points.end(); j++)
        {
            int u = Map[{(*i).first, (*i).second}];
            int v = Map[{(*j).first, (*j).second}];
            int w = abs((*i).first - (*j).first) + abs((*i).second - (*j).second);
            if (w != 0)
            {
                adj[u].push_back({w, {u, v}});
              //adj[v].push_back({w, {v, u}});
            }
        }
    }
    for (auto i = specialRoads.begin(); i != specialRoads.end(); i++)
    {
        int u = Map[{(*i).at(0), (*i).at(1)}];
        int v = Map[{(*i).at(2), (*i).at(3)}];
        int w = (*i).at(4);
        if (adj[u].at(v).first > w)
        {
            adj[u].erase(find_if(adj[u].begin(), adj[u].end(), [&u, &v](pair<int, pair<int, int>> &p)
                                 { return p.second.first == u && p.second.second == v; }));
            //adj[v].erase(find_if(adj[v].begin(), adj[v].end(), [&u, &v](pair<int, pair<int, int>> &p)
                               //  { return p.second.first == u && p.second.second == v; }));
            adj[u].push_back({w, {u, v}});
            //adj[v].push_back({w, {v, u}});
        }
    }

    vector<int> distance = shortestpath(Map[{startX, startY}], points.size(), adj);
    for (int i = 0; i < points.size(); i++)
    {
        cout << distance[i] << " ";
    }
    cout << endl
         << distance[Map[{targetX, targetY}]];
}
