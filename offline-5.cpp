#include<iostream>
using namespace std;
class Vertex
{
public:
    string color;
    int distance;
    Vertex* pi;
};
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

};
class Search
{

};
int main()
{


}
