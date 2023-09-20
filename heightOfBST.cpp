#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<cstring>
using namespace std;
ofstream fout;
template<class T>
class Node
{
public:
    T data;
    Node *left;
    Node *right;
};
int flag;
template<class T>
Node<T> *create_node(T d)
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
    Node <T>*toBeDeleted;
    Node<T>* ancestor;
public:
    BST()
    {
        root=NULL;
        toBeDeleted=NULL;
        ancestor=NULL;
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
    Node<T>* Insert(T d)
    {
        Node<T>* new_node=create_node(d);
        if(root==NULL)
        {
            root=new_node;
        }
        else
        {
            Node<T>* parent_node=root;
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
    Node<T>* Delete(T d)
    {
        flag=1;
        if(Find(d)=="True")
        {
            if(toBeDeleted->left==NULL && toBeDeleted->right==NULL)
            {
                if(toBeDeleted==root)
                {
                    root=NULL;
                }
                else
                {
                    if(toBeDeleted->data<ancestor->data)
                    {
                        Node<T>* temp_node=ancestor->left;
                        ancestor->left=NULL;
                        delete temp_node;
                    }
                    else
                    {
                        Node<T>* temp_node=ancestor->right;
                        ancestor->right=NULL;
                        delete temp_node;
                    }
                }
            }
            else
            {
                flag=0;
                fout<<"Invalid Operation"<<endl;
            }
        }
        else
        {
            flag=0;
            cout<<"Element not found!!!"<<endl;
        }
        return root;
    }
    string Find(T d)
    {
        if(root==NULL)
        {
            return "False";
        }
        else
        {
            Node<T>* parent_node=root;
            ancestor=NULL;
            while(parent_node!=NULL)
            {
                if(parent_node->left!=NULL || parent_node->right!=NULL)
                {
                    ancestor=parent_node;
                }
                if(d==parent_node->data)
                {
                    toBeDeleted=parent_node;
                    return "True";
                }
                else
                {
                    if(d<parent_node->data)
                    {
                        parent_node=parent_node->left;

                    }
                    else
                    {
                        parent_node=parent_node->right;
                    }
                }

            }
            return "False";
        }
    }
    void deleteNode(Node<T> *n)
    {
        if(n!=NULL)
        {
            deleteNode(n->left);
            deleteNode(n->right);
            delete n;
        }

    }
    ~BST()
    {
        deleteNode(root);
    }

};
template<class T>
void Print(Node<T> * curr_node,string & s)
{
    if(curr_node==NULL)
    {
        return;
    }
    s+=to_string(curr_node->data);
    if(curr_node->left==NULL && curr_node->right==NULL)
    {
        return;
    }
    s+="(";
    Print(curr_node->left,s);
    s+=")";
    s+="(";
    Print(curr_node->right,s);
    s+=")";
}
template<class T>
void pre_order(Node<T> *n,string &s)
{
    s+=to_string(n->data)+" ";
    if(n->left!=NULL)
    {
        pre_order(n->left,s);
    }
    if(n->right!=NULL)
    {
        pre_order(n->right,s);
    }
}
template<class T>
void post_order(Node<T> *n,string &s)
{
    if(n->left!=NULL)
    {
        post_order(n->left,s);
    }
    if(n->right!=NULL)
    {
        post_order(n->right,s);
    }
    s+=to_string(n->data)+" ";
}
template<class T>
void in_order(Node<T> *n,string &s)
{
    if(n->left!=NULL)
    {
        in_order(n->left,s);
    }
    s+=to_string(n->data)+" ";
    if(n->right!=NULL)
    {
        in_order(n->right,s);
    }
}
int main()
{
    

}
