#include<iostream>
#include<limits>
#include"LinkedListBasedImplementation.cpp"
#include"QueueImplementationwithLinkedList.h"
#include<list>
using namespace std;
template<class T>
class Vertex
{
public:
    T value;
    string color="";
    int distance=-1;
    Vertex* pi=NULL;
    void set_color(string color)
    {
        this->color=color;
    }
    void set_distance(int d)
    {
        distance=d;
    }
    void set_pi(Vertex *v)
    {
        pi=v;
    }
};
template<class T>
Vertex<T> create_vertex(T d)
{
    Vertex<T> new_vertex;
    new_vertex.value=d;
    new_vertex.color="WHITE";
    new_vertex.distance= numeric_limits<float>::infinity();
    new_vertex.pi=NULL;
    return new_vertex;
}
template<class T>
Vertex<T> create_vertex_source(T d)
{
    Vertex<T> new_vertex;
    new_vertex.value=d;
    new_vertex.color="WHITE";
    new_vertex.distance= numeric_limits<float>::infinity();
    new_vertex.pi=NULL;
    return new_vertex;
}
template<class T>
class Graph
{
    int edges,vertex;
    LinkedList <Vertex<int>>* adj;
public:
    Graph(int edge,int vertex)
    {
        this->edges=edges;
        this->vertex=vertex;
        adj=new LinkedList<Vertex<int>>[vertex];
    }
    void CreateEdge(T incident1,T incident2)
    {
        adj[incident1-1].pushBack(create_vertex(incident2));
    }
    void PrintGraph()
    {
        for(int i=0; i<vertex; i++)
        {
            adj[i].Print();
        }
    }
    void BFS(T s)
    {
        Vertex<T> v=create_vertex_source(s);
        v.color="GRAY";
      /*  for(int i=0; i<vertex; i++)
        {
            Node<T>* node=adj[i].head;
            if(node->data.value==s)
            {
                node->data.color="GRAY";
                node->data.distance=0;
                node->data.pi=NULL;
                break;
            }
            node=node->next;
        }*/


        Queue<Vertex<T>> q;
        q.Enqueue(v);
        while(q.Length()!=0)
        {
            Vertex<T> explored=q.Dequeue();
            cout<<explored.value<<" ";
            Node<Vertex<T>> *current_node=adj[explored.value-1].head;
            while(current_node!=NULL)
            {
                if(current_node->data.color=="WHITE" && current_node->data.value!=s)
                {
                    q.Enqueue(current_node->data);
                    current_node->data.color="GRAY";
                    current_node->data.distance=explored.distance+1;
                    current_node->data.pi=&explored;
                }
                current_node=current_node->next;
            }
            //explored.color="BLACK";
        }
    }
};
//DFS(Graph &graph,T s)

int main()
{
    int edges,vertex;
    cout<<"Enter total vertex of the graph:";
    cin>>vertex;
    cout<<"Enter total edges of the graph:";
    cin>>edges;
    //Taking input the directed graph
    Graph<int> graph(edges,vertex);
    cout<<"Input the incidents of edges:"<<endl;
    for(int i=0; i<edges; i++)
    {
        int incident1,incident2;
        cin>>incident1>>incident2;
        graph.CreateEdge(incident1,incident2);
    }
    graph.PrintGraph();
    int source;
    cin>>source;
    graph.BFS(source);

}
