#include <bits/stdc++.h>
using namespace std;
bool hasPath(int source, int sink, vector<int> &parent, vector<pair<int, int>> adj[], vector<vector<int>> &residueGraph)
{
    int vertex = residueGraph.size();

    vector<bool> visited(vertex, false);
    queue<int> Q;
    Q.push(source);
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (auto i = adj[u].begin(); i != adj[u].end(); i++)
        {
            int v = (*i).second;
            if (!visited[v] && residueGraph[u][v] != 0)
            {
                if (v == sink)
                {
                    parent[v] = u;
                    return true;
                }
                Q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;
}
int Edmonds_Karp(int vertex, vector<pair<int, int>> adj[], vector<vector<int>> &residueGraph)
{

    for (auto i = 0; i < vertex; i++)
    {
        for (auto j = adj[i].begin(); j < adj[i].end(); j++)
        {
            residueGraph[i][(*j).second] += (*j).first;
        }
    }
    // for(int i=0;i<vertex;i++){
    // //     for(int j = 0;j<vertex;j++){
    // //         cout<<residueGraph[i][j]<<" ";
    // //     }
    // //     cout<<endl;
    // // }
    int source = vertex - 2, sink = vertex - 1;
    vector<int> parent(vertex, -1);
    int maxFlow = 0;
    while (hasPath(source, sink, parent, adj, residueGraph))
    {
        int node = sink;
        int bottleNeckCapacity = INT_MAX;
        while (node != source)
        {
            bottleNeckCapacity = min(bottleNeckCapacity, residueGraph[parent[node]][node]);
            node = parent[node];
        }
        node = sink;
        while (node != source)
        {
            residueGraph[node][parent[node]] += bottleNeckCapacity;
            residueGraph[parent[node]][node] -= bottleNeckCapacity;
            node = parent[node];
        }
        maxFlow += bottleNeckCapacity;
    }
    return maxFlow;
}
int main()
{
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    int teams;
    cin >> teams;
    int win[teams], lost[teams], left[teams];
    int g[teams][teams];
    map<int, string> teamMap;
    for (int i = 0; i < teams; i++)
    {
        string teamName;
        cin >> teamName >> win[i] >> lost[i] >> left[i];
        teamMap[i] = teamName;
        for (int j = 0; j < teams; j++)
        {
            cin >> g[i][j];
        }
    }
    vector<pair<int, int>> allGames;
    for (int i = 0; i < teams; i++)
    {
        for (int j = i + 1; j < teams; j++)
        {
            allGames.push_back({i, j});
        }
    }
    int maxWin = INT_MIN;
    int maxWinIndex = -1;
    for (int i = 0; i < teams; i++)
    {
        if (maxWin < win[i])
        {
            maxWin = win[i];
            maxWinIndex = i;
        }
    }
    for (int i = 0; i < teams; i++)
    {
        vector<int> teamNode;
        vector<pair<int, int>> gameNode;
        for (auto j = allGames.begin(); j != allGames.end(); j++)
        {
            if ((*j).first != i && (*j).second != i)
            {
                gameNode.push_back((*j));
            }
        }
        map<pair<int, int>, int> gameMap;
        map<int, pair<int, int>> reverseGamemap;
        int k = 0;
        for (auto j = gameNode.begin(); j != gameNode.end(); j++)
        {
            gameMap[(*j)] = teams + k;
            reverseGamemap[teams + k] = *j;
            k++;
        }
        int source = gameMap.size() + teams;
        int sink = gameMap.size() + teams + 1;
        int totalNode = gameNode.size() + teams + 2;
        // cout << source << " ";
        // for (auto j = gameNode.begin(); j != gameNode.end(); j++)
        // {
        //     cout << gameMap[(*j)] << " ";
        // }
        // cout << sink << endl;
        vector<pair<int, int>> adj[totalNode];
        for (auto j = gameNode.begin(); j != gameNode.end(); j++)
        {
            int v = gameMap[(*j)];
            adj[source].push_back({g[reverseGamemap[v].first][reverseGamemap[v].second], v});
            adj[v].push_back({0, source});
            adj[reverseGamemap[v].first].push_back({0, v});
            adj[v].push_back({INT_MAX, reverseGamemap[v].first});
            adj[v].push_back({INT_MAX, reverseGamemap[v].second});
            adj[reverseGamemap[v].second].push_back({0, v});
        }
        for (auto j = 0; j != teams; j++)
        {
            if (i != j)
            {
                adj[j].push_back({max(win[i] + left[i] - win[j], 0), sink});
                adj[sink].push_back({0, j});
            }
        }
        // cout << "Adjacency List While Eliminating " << teamMap[i] << endl;
        // for (int k = 0; k < totalNode; k++)
        // {
        //     for (auto j = adj[k].begin(); j != adj[k].end(); j++)
        //     {
        //         cout << "(" << ((*j).first) << "," << (*j).second << ") ";
        //     }
        //     cout << endl;
        // }
        // cout << "---------------" << endl;
        if (win[i] + left[i] < maxWin)
        {
            cout << teamMap[i] << " is eliminated." << endl;

            cout << "They can win at most " << win[i] << " + " << left[i] << " = " << win[i] + left[i] << " games." << endl;
            cout << teamMap[maxWinIndex] << " has won a total of " << maxWin << " games." << endl;
            cout << "They play each other 0 times." << endl;
            cout << "So on average, each of the teams wins " << maxWin << "/" << 1 << " = " << (double)maxWin << " games." << endl;
        }
        else
        {
            vector<vector<int>> residueGraph(totalNode, vector<int>(totalNode, 0));
            int maxFlow = Edmonds_Karp(totalNode, adj, residueGraph);
            bool blocked = true;
            for (auto j = 0; j < totalNode; j++)
            {
                if (residueGraph[source][j] > 0)
                {
                    blocked = false;
                    break;
                }
            }
            if (!blocked)
            {
                cout << teamMap[i] << " is eliminated." << endl;
                vector<int> minCut;
                int Count = 0;
                vector<int> parents(totalNode, -1);
                for (int j = 0; j < teams; j++)
                {
                    if (hasPath(source, j, parents, adj, residueGraph))
                    {
                        minCut.push_back(j);
                        Count++;
                    }
                }
                cout << "They can win at most " << win[i] << " + " << left[i] << " = " << win[i] + left[i] << " games." << endl;
                if (Count == 1)
                {
                    cout << teamMap[minCut[0]] << " has won a total of " << win[minCut[0]] << " games." << endl;
                    cout << "They play each other 0 times." << endl;
                    cout << "So on average, each of the teams wins " << win[minCut[0]] << "/" << 1 << " = " << (double)win[minCut[0]] << " games." << endl;
                }
                else
                {
                    int j;
                    int totalWin = 0;
                    int remainingGame = 0;
                    for (j = 0; j < minCut.size() - 2; j++)
                    {
                        cout << teamMap[minCut[j]] << ",";
                        totalWin += win[minCut[j]];
                    }
                    for (int t = 0; t < minCut.size(); t++)
                    {
                        for (int k = t + 1; k < minCut.size(); k++)
                        {
                            remainingGame += g[minCut[t]][minCut[k]];
                        }
                    }
                    totalWin = totalWin + win[minCut[j]] + win[minCut[j + 1]];
                    cout << teamMap[minCut[j]] << " and " << teamMap[minCut[j + 1]] << " have won a total of " << totalWin << " games." << endl;
                    cout << "They play each other " << remainingGame << " times." << endl;
                    cout << "So on average, each of the teams wins " << totalWin + remainingGame << "/" << Count << " = " << (double)(totalWin + remainingGame) / Count << " games." << endl
                         << endl;
                }
            }
        }
    }
}