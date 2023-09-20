#include<iostream>
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
    Node *new_node=new Node;
    new_node->data=d;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}
class BST
{
    Node * root;
public:
    BST()
    {
        root=NULL;
    }
    BST(const BST &bst)
    {
        root=NULL;
        Copy(bst.root,root);
    }
    void Copy(Node<T> *n,Node<T> *r)
    {
        if(n==NULL)
        {
            return;
        }
        r=Insert(n->data);
        Copy(n->left,r);
        Copy(n->right,r);
    }
    Node Insert(T d)
    {
        Node new_node=create_node(d);
        if(root==NULL)
        {
            root=new_node;
        }
        else
        {
            Node parent_node=root;
            while(parent_node!=NULL)
            {
                if(d<parent_node->data)
                {
                    if(parent_node->left==NULL)
                    {
                        parent_node->left=new_node;
                        break;
                    }
                    parent_node=parent_node->left;

                }
                else
                {
                    if(parent_node->right==NULL)
                    {
                        parent_node->right=new_node;
                        break;
                    }
                    parent_node=parent_node->right;
                }
            }
        }
        return root;
    }


};

