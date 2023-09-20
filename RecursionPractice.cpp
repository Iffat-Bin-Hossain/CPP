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
    Node *new_node=new Node;
    new_node->data=d;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}
void pre_order(Node *n)
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
void post_order(Node *n)
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
void in_order(Node *n)
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
    /* Node *One=create_node(1);
     Node *Three=create_node(3);
     Node *Four=create_node(4);
     Node *Six=create_node(6);
     Node *Seven=create_node(7);
     Node *Eight=create_node(8);
     Node *Ten=create_node(10);
     Node *Thirteen=create_node(13);
     Node *fortheen=create_node(14);
     Eight->left=Three;
     Eight->right=Ten;
     Three->left=One;
     Three->right=Six;
     Six->left=Four;
     Six->right=Seven;
     Ten->right=fortheen;
     fortheen->left=Thirteen;
     cout<<"PreOrder:"<<endl;
     pre_order(Eight);
     cout<<"PostOrder:"<<endl;
     post_order(Eight);
     cout<<"InOrder:"<<endl;
     _order(Eight);*/
    char *A,*B;
    A=new char[10];
    B=new char[10];
    int j=9;
    for(int i=0; i<10; i++)
    {
        A[i]=B[j]=65+i;
        j--;
    }
    cout<<A<<" "<<B<<endl;
    if(*A==*B)
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
}


