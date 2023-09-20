#include<iostream>
#include"LinkedListBasedImplementation.cpp"
#include"QueueImplementationwithLinkedList.h"
#include<fstream>
using namespace std;
ofstream fout;
template<class T>
class Graph
{
    int edges,vertex;
    LinkedList <T>* adj;
    string *color;
public:
    Graph(int edge,int vertex)
    {
        this->edges=edges;
        this->vertex=vertex;
        adj=new LinkedList<T>[vertex];
        color=new string[vertex];
    }
    void makeAllUnExplored()
    {
        for(int i=0; i<vertex; i++)
        {
            color[i]="WHITE";
        }
    }

    void CreateEdge(T incident1,T incident2)
    {
        adj[incident1-1].pushBack(incident2);
    }
    void PrintGraph()
    {
        for(int i=0; i<vertex; i++)
        {
            adj[i].Print();
        }
    }
    void BFS(T source)
    {
        makeAllUnExplored();
        Queue<T> q;
        color[source-1]="GRAY";
        q.Enqueue(source);
        T explored;
        while(q.Length()!=0)
        {
            explored=q.Dequeue();
            fout<<explored<<" ";
            Node<T> *current_node=adj[explored-1].head;
            while(current_node!=NULL)
            {
                int i=current_node->data-1;
                if(color[i]=="WHITE")
                {
                    q.Enqueue(current_node->data);
                    color[i]="GRAY";

                }
                current_node=current_node->next;

            }
        }
        makeAllUnExplored();
    }
    void DFS(T source)
    {
        color[source-1]="GRAY";
        Node<T> *current_node=adj[source-1].head;
        while(current_node!=NULL)
        {
            int i=current_node->data-1;
            if(color[i]=="WHITE")
            {
                DFS(current_node->data);
            }
            current_node=current_node->next;
        }
        fout<<source<<" ";
    }
};
int main()
{
    ifstream fin("input1.txt");
    fout.open("output1.txt");
    if(!fin){
        cout<<"File can not be opened"<<endl;
    }
    if(!fout){
        cout<<"File can not be opened"<<endl;
    }
    int edges,vertex;
    fin>>vertex>>edges;
    Graph<int> graph(edges,vertex);
    for(int i=0; i<edges; i++)
    {
        int incident1,incident2;
        fin>>incident1>>incident2;
        graph.CreateEdge(incident1,incident2);
    }
    int source;
    fin>>source;
    fout<<"BFS Tree:"<<endl;
    graph.BFS(source);
    fout<<endl;
    fout<<"DFS Tree:"<<endl;
    graph.DFS(source);


}
