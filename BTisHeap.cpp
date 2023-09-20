#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left,*right;
};
Node *create_node(int d)
{
    Node* node=new Node;
    node->data=d;
    node->left=NULL;
    node->right=NULL;
    return node;
}
class BT
{
    Node *root;
public:
    BT()
    {
        root=NULL;
    }
    int CountNode(Node * root)
    {
        if(root==NULL)
        {
            return 0;
        }
        return 1+CountNode(root->left)+CountNode(root->right);
    }
    bool isCompleteBT(Node* node,int nodeCount,int i)
    {
        bool b;
        if(node==NULL)
        {
            return true;
        }
        if(i>=nodeCount)
        {
            return false;
        }
        b=isCompleteBT(node->left,nodeCount,(2*i)+1) && isCompleteBT(node->right, nodeCount,(2*i)+2);
        return b;
    }
    bool hasHeapProperty(Node *node)
    {
        bool b;
        if(node==NULL){
            return true;
        }
        if (node->left==NULL && node->right==NULL)
        {
            return true;
        }
        if(node->right==NULL)
        {
            return node->left->data<=node->data;
        }
        else
        {
            if(node->left->data<=node->data && node->right->data<=node->data)
            {
                return hasHeapProperty(node->left) && hasHeapProperty(node->right);
            }
            else
            {
                return false;
            }
        }

    }
    bool isHeap(Node* node)
    {
        int nodeCount=CountNode(node);
        return isCompleteBT(node,nodeCount,0) && hasHeapProperty(node);
    }
};

int main()
{


    Node *root=NULL;
    BT b;
    root = create_node(10);
    root->left = create_node(9);
    root->right = create_node(8);
    root->left->left =create_node(7);
    root->left->right =create_node(6);
    root->right->left = create_node(5);
    root->right->right = create_node(4);
    root->left->left->left = create_node(3);
    root->left->left->right = create_node(2);
    root->left->right->left = create_node(1);
    if (b.isHeap(root))
        cout << "Given binary tree is a Heap\n";
    else
        cout << "Given binary tree is not a Heap\n";

}
