#include <bits/stdc++.h>
using namespace std;

double maxProbability(int vertex, vector<vector<int>> &edges, vector<double> &succProb, int source, int destination)
{
    vector<pair<double, pair<int, int>>> adj[vertex];
    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i].at(0)].push_back({succProb[i], {edges[i].at(0), edges[i].at(1)}});
        adj[edges[i].at(1)].push_back({succProb[i], {edges[i].at(1), edges[i].at(0)}});
    }
    vector<double> distance(vertex, -1);
    priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> pq;
    distance[source] = 1;
    pq.push({0, {-1, source}});
    while (!pq.empty())
    {
        auto min = pq.top();
        pq.pop();
        for (auto i = adj[min.second.second].begin(); i != adj[min.second.second].end(); i++)
        {
            if (distance[min.second.second] * (*i).first > distance[(*i).second.second])
            {
                distance[(*i).second.second] = distance[min.second.second] * (*i).first;
                pq.push({distance[(*i).second.second], {(*i).second.first, (*i).second.second}});
            }
        }
    }
    if (distance[destination] == -1)
    {
        return 0;
    }
    return distance[destination];
}

int main(){
    cout<<"Nabil"<<endl;
}