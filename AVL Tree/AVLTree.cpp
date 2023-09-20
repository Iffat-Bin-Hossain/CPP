#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
};
Node *create_node(int d)
{
    Node *new_node = new Node;
    new_node->data = d;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
class AVLTree
{
public:
    Node *insert(Node *node, int data)
    {
        if (node == NULL)
        {
            return create_node(data);
        }
        if (data < node->data)
        {
            node->left = insert(node->left, data);
        }
        else
        {

            node->right = insert(node->right, data);
        }
        int balancefactor = balanceFactor(node);
        if (balancefactor > 1)
        {
            if (data > node->left->data)
            {
                node->left = antiClockWiseRotation(node->left);
            }
            return clockWiseRotation(node);
        }
        if (balancefactor < -1)
        {
            if (data < node->right->data)
            {
                node->right = clockWiseRotation(node->right);
            }
            return antiClockWiseRotation(node);
        }
        return node;
    }
    int balanceFactor(Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        return height(node->left) - height(node->right);
    }
    int height(Node *node)
    {
        int h;
        if (node == NULL)
        {
            return 0;
        }
        h = max(height(node->left) + 1, height(node->right) + 1);
        return h;
    }
    Node *clockWiseRotation(Node *node)
    {
        Node *leftNode = node->left;
        Node *lrightNode = leftNode->right;
        leftNode->right = node;
        node->left = lrightNode;
        return leftNode;
    }
    Node *antiClockWiseRotation(Node *node)
    {
        Node *rightNode = node->right;
        Node *rleftNode = rightNode->left;
        rightNode->left = node;
        node->right = rleftNode;
        return rightNode;
    }
    Node *remove(Node *node, int d)
    {
        if (node == NULL)
        {
            return NULL;
        }
        if (d < node->data)
        {
            node->left = remove(node->left, d);
        }
        else if (d > node->data)
        {
            node->right = remove(node->right, d);
        }
        else
        {
            Node *temp = new Node;
            if (node->left == NULL && node->right == NULL)
            {
                delete (node);
                return NULL;
            }
            else if (node->left == NULL)
            {
                temp = node->right;
                delete (node);
                return temp;
            }
            else if (node->right == NULL)
            {
                temp = node->left;
                delete (node);
                return temp;
            }
            // temp=Predecessor_node(node);
            // node->data=temp->data;
            // node->left=remove(node->left,temp->data);
            temp = Successor_node(node);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
        if (balanceFactor(node) > 1)
        {
            if (balanceFactor(node->left) < 0)
            {
                node->left = antiClockWiseRotation(node->left);
            }
            return clockWiseRotation(node);
        }
        if (balanceFactor(node) < -1)
        {
            if (balanceFactor(node->right) > 0)
            {
                node->right = clockWiseRotation(node->right);
            }
            return antiClockWiseRotation(node);
        }
        return node;
    }
    Node *Predecessor_node(Node *node)
    {
        node = node->left;
        while (node->right != NULL)
        {
            node = node->right;
        }
        return node;
    }
    Node *Successor_node(Node *node)
    {
        node = node->right;
        while (node->left != NULL)
        {
            node = node->left;
        }
        return node;
    }
    bool find(Node *node, int d)
    {
        if (node == NULL)
        {
            return false;
        }
        else if (d == node->data)
        {
            return true;
        }
        else
        {
            if (d < node->data)
            {
                return find(node->left, d);
            }
            else
            {
                return find(node->right, d);
            }
        }
    }
    void InOrder_traversal(Node *node)
    {
        if (node->left != NULL)
        {
            InOrder_traversal(node->left);
        }
        cout << node->data << " ";
        if (node->right != NULL)
        {
            InOrder_traversal(node->right);
        }
    }
    void printAVLTree(Node *node)
    {
        if (node == NULL)
        {
            return;
        }
        cout << node->data;
        if (node->left == NULL && node->right == NULL)
            return;
        cout << "(";
        printAVLTree(node->left);
        cout << ",";
        printAVLTree(node->right);
        cout << ")";
    }
};
int main()
{
    freopen("in.txt", "r", stdin);
    FILE *out = freopen("avl_out.txt", "w", stdout);
    double insertionTime = 0, deletionTime = 0, searchTime = 0, traversalTime = 0;
    int totalInsertion = 0, totalDeletion = 0, totalSearch = 0, totalTraversal = 0;
    Node *root = NULL;
    AVLTree avlTree;
    char operation;
    while (cin >> operation)
    {
        int data;

        if (operation == 'T')
        {
            totalTraversal++;
            auto start = chrono::high_resolution_clock::now();
            avlTree.InOrder_traversal(root);
            auto end = chrono::high_resolution_clock::now();
            traversalTime += chrono::duration_cast<chrono::duration<double, milli>>(end - start).count();
            cout << endl;
            continue;
        }
        cin >> data;
        if (operation == 'I')
        {
            totalInsertion++;
            auto start = chrono::high_resolution_clock::now();
            root = avlTree.insert(root, data);
            auto end = chrono::high_resolution_clock::now();
            insertionTime += chrono::duration_cast<chrono::duration<double, milli>>(end - start).count();
            avlTree.printAVLTree(root);
            cout << endl;
        }
        else if (operation == 'D')
        {
            totalDeletion++;
            auto start = chrono::high_resolution_clock::now();
            root = avlTree.remove(root, data);
            auto end = chrono::high_resolution_clock::now();
            deletionTime += chrono::duration_cast<chrono::duration<double, milli>>(end - start).count();
            avlTree.printAVLTree(root);
            cout << endl;
        }
        else if (operation == 'F')
        {
            totalSearch++;
            auto start = chrono::high_resolution_clock::now();
            bool found = avlTree.find(root, data);
            auto end = chrono::high_resolution_clock::now();
            searchTime += chrono::duration_cast<chrono::duration<double, milli>>(end - start).count();
            if (found)
            {
                cout << "found" << endl;
            }
            else
            {
                cout << "not found" << endl;
            }
        }
    }
    fclose(out);
    freopen("report_avl.txt", "w", stdout);
    cout << "Operation  time(ms)" << endl;
    cout << "insertion  " << insertionTime << endl;
    cout << "deletion  " << deletionTime << endl;
    cout << "search  " << searchTime << endl;
    cout << "trav  " << traversalTime << endl;
    cout << "total  " << insertionTime + deletionTime + searchTime + traversalTime << endl
         << endl;
    cout << "operation   average time(ms)" << endl;
    cout << "insertion  " << insertionTime / totalInsertion << endl;
    cout << "deletion  " << deletionTime / totalDeletion << endl;
    cout << "search  " << searchTime / totalSearch << endl;
    cout << "trav  " << traversalTime / totalTraversal << endl;
}
