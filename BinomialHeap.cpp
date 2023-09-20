#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int key, degree;
    Node *parent, *leftMostChild, *sibling;
};
Node *createNode(int data)
{
    Node *newNode = new Node;
    newNode->key = data;
    newNode->degree = 0;
    newNode->parent = NULL;
    newNode->leftMostChild = NULL;
    newNode->sibling = NULL;
    return newNode;
}
class Binomial_Heap
{
public:
    Node *mergeTree(Node *node1, Node *node2)
    {
        if (node1->key < node2->key)
        {
            node2->parent = node1;
            node2->sibling = node1->leftMostChild;
            node1->leftMostChild = node2;
            node1->degree++;
            return node1;
        }
        else
        {
            node1->parent = node2;
            node1->sibling = node2->leftMostChild;
            node2->leftMostChild = node1;
            node2->degree++;
            return node2;
        }
    }
    vector<Node *> Union(vector<Node *> &heap1, vector<Node *> &heap2)
    {
        vector<Node *> allCollection;
        auto i = heap1.begin();
        auto j = heap2.begin();
        while (i != heap1.end() && j != heap2.end())
        {
            if ((*i)->degree < (*j)->degree)
            {
                allCollection.push_back((*i));
                i++;
            }
            else
            {
                allCollection.push_back((*j));
                j++;
            }
        }
        while (i != heap1.end())
        {
            allCollection.push_back((*i));
            i++;
        }
        while (j != heap2.end())
        {
            allCollection.push_back((*j));
            j++;
        }
        vector<Node *>::iterator current, nextOfCurrent, siblingOfNext;
        current = allCollection.begin();
        nextOfCurrent = current;
        if (current != allCollection.end())
            nextOfCurrent++;
        siblingOfNext = nextOfCurrent;
        if (nextOfCurrent != allCollection.end())
            siblingOfNext++;
        while (current != allCollection.end())
        {
            if (nextOfCurrent == allCollection.end())
            {
                current++;
            }
            else if ((*current)->degree != (*nextOfCurrent)->degree)
            {
                current++;
                nextOfCurrent++;
                if (siblingOfNext != allCollection.end())
                {
                    siblingOfNext++;
                }
            }
            else if (siblingOfNext != allCollection.end() && (*current)->degree == (*nextOfCurrent)->degree && (*nextOfCurrent)->degree == (*siblingOfNext)->degree)
            {
                current++;
                nextOfCurrent++;
                siblingOfNext++;
            }
            else if ((*current)->degree == (*nextOfCurrent)->degree)
            {
                *current = mergeTree(*current, *nextOfCurrent);
                nextOfCurrent = allCollection.erase(nextOfCurrent);
                if (siblingOfNext != allCollection.end())
                {
                    siblingOfNext++;
                }
            }
        }
        return allCollection;
    }
    vector<Node *> Insert(vector<Node *> &heap, int data)
    {
        vector<Node *> newHeap;
        Node *newNode = createNode(data);
        newHeap.push_back(newNode);
        return Union(heap, newHeap);
    }
    Node *FindMin(vector<Node *> &heap)
    {
        int Min = INT_MAX;
        Node *minNode = NULL;
        for (auto i = heap.begin(); i != heap.end(); i++)
        {
            if (Min > (*i)->key)
            {
                Min = (*i)->key;
                minNode = (*i);
            }
        }
        return minNode;
    }
    Node *ExtractMin(vector<Node *> &heap)
    {
        vector<Node *> updatedHeap, newHeap;
        auto minNode = FindMin(heap);
        for (auto i = heap.begin(); i != heap.end(); i++)
        {
            if ((*i) != minNode)
            {
                newHeap.push_back((*i));
            }
        }
        for (auto i = minNode->leftMostChild; i != NULL; i = i->sibling)
        {
            auto j = i;
            j->parent = j->sibling = NULL;
            updatedHeap.push_back(j);
        }
        heap = Union(newHeap, updatedHeap);
        return minNode;
    }
    void Print(vector<Node *> &heap)
    {
        cout << "Printing Binomial Heap..." << endl;

        for (auto i = heap.begin(); i != heap.end(); i++)
        {
            int level = 0;
            cout << "Binomial Tree, B" << (*i)->degree << endl;
            for (auto j = (*i); j != NULL; j = j->leftMostChild)
            {
                cout << "Level " << level++ << " : ";
                for (auto k = j; k != NULL; k = k->sibling)
                {
                    cout << k->key << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
    }
};

int main()
{
    freopen("in2.txt", "r", stdin);
    freopen("BinomialHeapOutput.txt", "w", stdout);
    Binomial_Heap BHeap;
    vector<Node *> heap;
    string line;

    while (getline(cin, line))
    {
        // cout<<line<<" "<<endl;
        char operation;
        stringstream ss(line);
        ss >> operation;
        if (operation == 'P')
        {
            BHeap.Print(heap);
        }

        if (operation == 'I')
        {
            int data;
            ss >> data;
            heap = BHeap.Insert(heap, data);
        }
        else if (operation == 'F')
        {
            cout << "Find-Min returned " << BHeap.FindMin(heap)->key << endl;
        }
        else if (operation == 'E')
        {
            cout << "Extract-Min returned " << BHeap.ExtractMin(heap)->key << endl;
        }
        else if (operation == 'U')
        {
            int data;
            vector<Node *> secondHeap;
            while (ss >> data)
            {
                secondHeap = BHeap.Insert(secondHeap, data);
                // cout << "printing second heap" << endl;
                // BHeap.Print(secondHeap);
            }
            heap = BHeap.Union( heap,secondHeap);
        }
    }
}
