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
    string BFS(int source)
    {
        vector<int> color(vertex, 0);
        Queue<int> q;
        color.at(source) = 1;
        q.Enqueue(source);
        string s = "";
        while (q.Length() != 0)
        {
            int temp = q.Dequeue();
            string p = to_string(temp);
            s.append(p);
            s.append(" ");
            auto current_node = adjacencyList[temp].head;
            while (current_node != NULL)
            {
                if (color.at(current_node->data) == 0)
                {
                    q.Enqueue(current_node->data);
                    color.at(current_node->data) = 1;
                }
                current_node = current_node->next;
            }
        }
        return s;
    }
    string DFS(int source)
    {
        vector<int> color(vertex, 0);
        Stack<int> S;
        S.push(source);
        string s = "";
        while (S.Length() != 0)
        {
            int temp = S.pop();
            if (color.at(temp) == 0)
            {
                color.at(temp) = 1;
                string p = to_string(temp);
                s.append(p);
                s.append(" ");
            }
            auto current_node = adjacencyList[temp].head;
            while (current_node != NULL)
            {
                if (color.at(current_node->data) == 0)
                {
                    S.push(current_node->data);
                }
                current_node = current_node->next;
            }
        }
        return s;
    }

    bool bipartiteCheckingWithBFS()
    {
        vector<int> color(vertex, -1);
        Queue<int> q;
        color.at(0) = 1;
        q.Enqueue(0);
        while (q.Length() != 0)
        {
            int temp = q.Dequeue();
            auto current_node = adjacencyList[temp].head;
            while (current_node != NULL)
            {
                // Checking self loop
                if (current_node->data == temp)
                {
                    return false;
                }

                else if (color.at(current_node->data) == -1)
                {
                    q.Enqueue(current_node->data);
                    color.at(current_node->data) = 1 - color.at(temp);
                }
                else if (color.at(current_node->data) == color.at(temp))
                {
                    return false;
                }
                current_node = current_node->next;
            }
        }
        return true;
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
    bool bipartite = graph.bipartiteCheckingWithBFS();
    if (bipartite)
        cout << "This Graph Is Bipartite" << endl;
    else
        cout << "This Graph Is Not Bipartite" << endl;
    int source;
    cout << "Enter the source:";
    cin >> source;
    cout << "BFS Tree:" << graph.BFS(source) << endl;
    cout << "DFS Tree:" << graph.DFS(source) << endl;
}
