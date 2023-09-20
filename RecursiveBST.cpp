#include <iostream>
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
class BST
{
public:
    Node *insert(Node *node, int d)
    {
        if (node == NULL)
        {
            return create_node(d);
        }
        if (d < node->data)
        {
            node->left = insert(node->left, d);
        }
        else
        {
            node->right = insert(node->right, d);
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
        return node;
    }
    bool search(Node *node, int d)
    {
        bool b;
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
                b = search(node->left, d);
            }
            else
            {
                b = search(node->right, d);
            }
        }
        return b;
    }
    int countNode(Node *node)
    {
        int totalNode;
        if (node == NULL)
        {
            return 0;
        }
        totalNode = 1 + countNode(node->left) + countNode(node->right);
        return totalNode;
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
    int leftSum(Node *node)
    {
        int sum;
        if (node == NULL)
        {
            return 0;
        }
        sum = node->data + leftSum(node->left) + leftSum(node->right);
        return sum;
    }
    int rightSum(Node *node)
    {
        int sum;
        if (node == NULL)
        {
            return 0;
        }
        sum = rightSum(node->right) + node->data + rightSum(node->left);
        return sum;
    }
    int maxOfBST(Node *node)
    {
        while (node->right != NULL)
        {
            node = node->right;
        }
        return node->data;
    }
    int minOfBST(Node *node)
    {
        while (node->left != NULL)
        {
            node = node->left;
        }
        return node->data;
    }
    void PreOrder_traversal(Node *node)
    {
        cout << node->data << " ";
        if (node->left != NULL)
        {
            PreOrder_traversal(node->left);
        }
        if (node->right != NULL)
        {
            PreOrder_traversal(node->right);
        }
    }
    void PostOrder_traversal(Node *node)
    {
        if (node->left != NULL)
        {
            PostOrder_traversal(node->left);
        }
        if (node->right != NULL)
        {
            PostOrder_traversal(node->right);
        }
        cout << node->data << " ";
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
    bool balancedBST(Node *node) /// Condition: "0<=lHeight-rHeight<=1"
    {
        bool b;
        int lheight, rheight;
        if (node == NULL)
        {
            return true;
        }
        else if (node->left == NULL && node->right == NULL)
        {
            return true;
        }
        lheight = height(node->left) + 1;
        rheight = height(node->right) + 1;
        if (abs(lheight - rheight) <= 1)
        {
            b = balancedBST(node->left) && balancedBST(node->right);
        }
        else
        {
            return false;
        }
        return b;
    }
};
int main()
{
    Node *Root=NULL;
    BST bst;
    Root = bst.insert(Root, 5);
    Root = bst.insert(Root, 1);
    Root = bst.insert(Root, 4);
    Root = bst.insert(Root, 3);
    Root = bst.insert(Root, 7);
    Root = bst.insert(Root, 8);
    Root = bst.insert(Root, 9);
    Root = bst.insert(Root, 10);
    Root = bst.insert(Root, 6);
    Root = bst.insert(Root, 2);
    cout << boolalpha << bst.balancedBST(Root) << endl;
    cout << bst.leftSum(Root->left) << endl;
    cout << bst.rightSum(Root->right) << endl;
    cout << bst.height(Root->left) << endl;
    cout << bst.search(Root, 10) << endl;
    cout << bst.search(Root, 9) << endl;
    cout << bst.search(Root, 6) << endl;
    bst.PreOrder_traversal(Root);
    cout << endl;
    cout << bst.countNode(Root) << endl;
    bst.PostOrder_traversal(Root);
    cout << endl;
    bst.InOrder_traversal(Root);
    cout << endl;
    Root = bst.remove(Root, 8);
    bst.PreOrder_traversal(Root);
    cout << endl;
    Root = bst.remove(Root, 2);
    bst.PreOrder_traversal(Root);
    cout << endl;
    Root = bst.remove(Root, 6);
    bst.PreOrder_traversal(Root);
    cout << endl;
    cout << bst.countNode(Root) << endl;
    cout << bst.search(Root, 6) << endl;
    cout << bst.height(Root->left) << endl;
    cout << bst.leftSum(Root->left) << endl;
    cout << bst.balancedBST(Root) << endl;
}
