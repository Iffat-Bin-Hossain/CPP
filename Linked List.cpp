#include<iostream>
using namespace std;
typedef struct node Node;
struct node
{
    int data;
    Node *next;
};
Node *create_node(int item,Node *next)
{
    Node *new_node=(Node*)malloc(sizeof(Node));
    if(new_node==NULL)
    {

        cout<<"Allocation Error!!!"<<endl;
        exit(1);
    }
    new_node->data=item;
    new_node->next=next;
    return new_node;
}
Node *remove_node(Node *head,Node *node)
{
    if(node==head)
    {
        head=head->next;
        free(node);
        return head;

    }
    Node* current_node=head;
    while(current_node->next!=NULL)
    {
        if(current_node->next==node)
        {

            break;
        }
        current_node= current_node->next;

    }
    if(current_node->next==NULL)
    {
        return head;
    }
    current_node->next=node->next;
    free(node);
    return head;

}
Node* prepend_node(int item,Node *head)
{
    Node *new_node=create_node(item,head);
    return new_node;
}
Node* append_node(int item,Node *head)
{
    Node *new_node=create_node(item,NULL);
    if(head==NULL)
    {
        return new_node;
    }
    Node* current_node=head;
    while(current_node->next!=NULL)
    {
        current_node= current_node->next;
    }
    current_node->next=new_node;
    return head;
}
void insert_node(int item,Node *node)
{
    Node *new_node=create_node(item,node->next);
    node->next=new_node;
}
Node* reverse_linked_list(Node *head)
{
    Node* prev,*nxt,*curr;
    curr=head;
    prev=NULL;
    nxt=NULL;
    while(curr!=NULL)
    {
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    head=prev;
    return head;


}
Node* aSort_linked_list(Node *head)//Ascending Sort
{
    int A[100];
    Node *current=head;
    int i=0;
    while(current!=NULL)
    {
        A[i]=current->data;
        current=current->next;
        i++;
    }
    for(int j=0; j<i; j++)
    {
        for(int k=j+1; k<i; k++)
        {
            if(A[j]<A[k])
            {
                int T=A[k];
                A[k]=A[j];
                A[j]=T;
            }

        }
    }
    i--;
    current=head;
    while(current!=NULL)
    {
        current->data=A[i];
        current=current->next;
        i--;
    }
    return head;

}
void print_linked_list(Node* head)
{
    Node* current_node=head;
    while(current_node!=NULL)
    {
        cout<<current_node->data<<" ";
        current_node= current_node->next;
    }
    cout<<endl;


}
int main()
{
    Node *n;
    n=create_node(10,NULL);
    print_linked_list(n);
    n=append_node(23,n);
    n=append_node(43,n);
    n=append_node(14,n);
    n=append_node(35,n);
    print_linked_list(n);
    n=prepend_node(65,n);
    n=prepend_node(20,n);
    print_linked_list(n);
    insert_node(115,n->next->next);
    print_linked_list(n);
    insert_node(29,n->next->next->next->next);
    print_linked_list(n);
    n=remove_node(n,n);
    print_linked_list(n);
    n=remove_node(n,n->next->next->next->next);
    print_linked_list(n);
    n=reverse_linked_list(n);
    print_linked_list(n);
    n=aSort_linked_list(n);
    print_linked_list(n);
}
