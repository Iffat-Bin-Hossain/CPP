#include<iostream>
#include<fstream>
using namespace std;
template<class T>
class Node
{
public:
    T data;
    Node *left;
    Node *right;
};
template<class T>
Node<T> *create_node(int d)
{
    Node<T> *new_node=new Node<T>;
    new_node->data=d;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}
template<class T>
class BST
{
    Node<T>* root;
    Node<T>* parent;
public:
    BST()
    {
        root=NULL;
        parent=NULL;
    }


};
ofstream fout;
template<class T>
void pre_order(Node<T> *n)
{
    cout<<n->data<<endl;
    if(n->left!=NULL)
    {
        pre_order(n->left);
    }
    if(n->right!=NULL)
    {
        pre_order(n->right);
    }
}
template<class T>
void post_order(Node<T> *n)
{
    if(n->left!=NULL)
    {
        post_order(n->left);
    }
    if(n->right!=NULL)
    {
        post_order(n->right);
    }
    cout<<n->data<<endl;
}
template<class T>
void in_order(Node<T> *n)
{
    if(n->left!=NULL)
    {
        in_order(n->left);
    }
    cout<<n->data<<endl;
    if(n->right!=NULL)
    {
        in_order(n->right);
    }
}
int main()
{
ifstream fin;
fin.open("input.txt");
fout.open("output.txt");
}

