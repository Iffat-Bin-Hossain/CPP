#include<iostream>
using namespace std;
class Graph
{
    int edge,vertex;
    int **graph;
public:
    Graph(int edge,int vertex)
    {
        graph=(int**)malloc(sizeof(int*)*vertex);
        for(int i=0; i<vertex; i++)
        {
            graph[i]=(int *)malloc(sizeof(int)*vertex);
        }
        this->edge=edge;
        this->vertex=vertex;
        for(int i=0; i<vertex; i++)
        {
            for(int j=0; j<vertex; j++)
            {
                graph[i][j]=0;
            }
        }
    }
    void inputGraphInAdjacencyMatrix()
    {
        cout<<"Input the incidents of edges:"<<endl;
        for(int i=0; i<edge; i++)
        {
            int incident1,incident2;
            cin>>incident1>>incident2;
            graph[incident1-1][incident2-1]=1;
            graph[incident2-1][incident1-1]=1;
        }
    }
    void printGraphInAdjacencyMatrix()
    {
        cout<<"Adjacency matrix of the graph:"<<endl;
        for(int i=0; i<vertex; i++)
        {
            for(int j=0; j<vertex; j++)
            {
                cout<<graph[i][j]<<" ";
            }
            cout<<endl;
        }
    }

};
int main()
{

    int edge,vertex;
    cout<<"Enter total vertex of the graph:";
    cin>>vertex;
    cout<<"Enter total edges of the graph:";
    cin>>edge;
    Graph g(edge,vertex);
    g.inputGraphInAdjacencyMatrix();
    g.printGraphInAdjacencyMatrix();

}
