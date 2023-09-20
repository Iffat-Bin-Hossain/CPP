#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    int vertex, edges;
    cout << "Enter vertex and edges:";
    cin >> vertex >> edges;
    list<pair<int, pair<int, int>>> adjList[vertex];

    int visited[vertex]={0};
    cout << "Enter incidents and weight:" << endl;
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        int w;
        cin >> u >> v >> w;
        adjList[u].push_back(make_pair(w, make_pair(u, v)));
        adjList[v].push_back(make_pair(w, make_pair(v, u)));
    }
    vector<pair<int, int>> MST;
    int source;
    cout << "Enter source:";
    cin >> source;
    pq.push(make_pair(0, make_pair(-1, source)));
    int minCost = 0;
    while (!pq.empty())
    {
        auto min = pq.top();
        pq.pop();
        if (visited[min.second.second] == 0)
        {
            visited[min.second.second] = 1;
            if(min.second.first!=-1)
                MST.push_back(make_pair(min.second.first, min.second.second));
            minCost += min.first;
        }
        else{
            continue;
        }
        for (auto i : adjList[min.second.second])
        {
            if (visited[i.second.second] == 0)
            {
                pq.push(i);
            }
        }
    }
    cout << "Minimum Spanning Tree:" << endl;
    for(int i=0;i<MST.size();i++){
        cout<<"("<<MST[i].first<<" "<<MST[i].second<<")"<<" ";
    }
    cout<<endl;
    cout << "Minimum Cost:" << minCost << endl;
}