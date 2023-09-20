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
void remove_node(Node *head,Node *node)
{
    if(node==head)
    {
        head=head->next;
        free(node);

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
    current_node->next=node->next;
    free(node);


}
void prepend_node(int item,Node *head)
{
    Node *new_node=create_node(item,head);
    head=new_node;

}
void append_node(int item,Node *head)
{
    Node *new_node=create_node(item,NULL);
    Node* current_node=head;
    if(head==NULL){

        current_node=new_node;
    }
    else{
    while(current_node->next!=NULL)
    {
        current_node= current_node->next;
    }
    current_node->next=new_node;
    }
}
void insert_node(int item,Node *node)
{
    Node *new_node=create_node(item,node->next);
    node->next=new_node;
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
append_node(20,n);
append_node(30,n);
append_node(40,n);
append_node(50,n);
print_linked_list(n);
prepend_node(5,n);
prepend_node(0,n);
print_linked_list(n);
insert_node(15,n->next->next);
print_linked_list(n);
insert_node(25,n->next->next->next->next);
print_linked_list(n);
remove_node(n,n);
print_linked_list(n);
remove_node(n,n->next->next->next->next);
print_linked_list(n);
}

