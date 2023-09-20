#include <bits/stdc++.h>
#include "LinkedListBasedImplementation.cpp"
#include "QueueImplementationwithLinkedList.h"
#include "StackImplementationwithLinkedList.h"
using namespace std;
class Graph
{
    int vertex, edges;
    LinkedList<int> *adjacencyList;

public:
    Graph(int v, int e)
    {
        vertex = v;
        edges = e;
        adjacencyList = new LinkedList<int>[v];
    }
    void addEdge(int incident1, int incident2)
    {
        adjacencyList[incident1].pushBack(incident2);
        adjacencyList[incident2].pushBack(incident1);
    }
    void printGraph()
    {
        for (int i = 0; i < vertex; i++)
        {
            adjacencyList[i].Print();
        }
    }
    bool hasCycleUtil(vector<int> &color, Queue<int> &q, int source)
    {
        color.at(source) = 0;
        q.Enqueue(source);
        while (q.Length() != 0)
        {
            int temp = q.Dequeue();
            color.at(temp) = 1;
            auto current_node = adjacencyList[temp].head;
            while (current_node != NULL)
            {
                if (color.at(current_node->data) == -1)
                {
                    q.Enqueue(current_node->data);
                    color.at(current_node->data) = 0;
                }
                else if (color.at(current_node->data) == 0)
                {
                    return true;
                }
                current_node = current_node->next;
            }
        }
        return false;
    }

    bool hasCycle()
    {
        vector<int> color(vertex, -1);
        Queue<int> q;
        bool hasCycle = false;
        for (int i = 0; i < vertex; i++)
        {
            if (color[i] == -1)
            {
                hasCycle += hasCycleUtil(color, q, i);
            }
        }
        return hasCycle;
    }
};

int main()
{
    cout << boolalpha;
    int v, e;
    cout << "Number of vertex :";
    cin >> v;
    cout << "Number of edges :";
    cin >> e;
    Graph graph(v, e);
    cout << "Enter All Edges:" << endl;
    for (int i = 0; i < e; i++)
    {
        int i1, i2;
        cin >> i1 >> i2;
        graph.addEdge(i1, i2);
    }
    cout << "Adjacency List Of Graph:" << endl;
    graph.printGraph();
    cout << graph.hasCycle() << endl;
}