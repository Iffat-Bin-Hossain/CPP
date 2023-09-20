#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Graph
{
public:
    vector<int>*adj;
    int *visited,n,m,*dist;
    queue<int>q;
    Graph(int n,int m)
    {
       this->n=n;
       this->m=m;
       adj=new vector<int>[n+1];
       visited=new int[n+1];
       dist=new int[n+1];
       for(int i=0;i<n;i++)
       {
           visited[i]=0;
       }
       for(int i=0;i<n;i++)
       {
           dist[i]=100000;
       }
       dist[0]=0;
       visited[0]=1;
       q.push(0);
    }
    void shortd()
    {
        while(!q.empty())
        {
            int data=q.front();

            q.pop();

            for(auto it:adj[data])
            {
                if(dist[data]+1<dist[it] && !visited[it])
                {
                    visited[it]=1;
                    dist[it]=dist[data]+1;
                    q.push(it);
                }
            }
        }
    }
    void print()
    {
        for(int i=0;i<n;i++)
        {
            cout<<dist[i]<<" ";
        }
    }
};
int main()
{
    int n,m,u,v;
    cin>>n>>m;
    Graph g(n,m);
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        g.adj[u].push_back(v);
        g.adj[v].push_back(u);
    }
    g.shortd();
    g.print();
}
