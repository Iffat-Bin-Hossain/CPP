#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
Node *create_node(int d)
{
    Node *new_node=new Node;
    new_node->data=d;
    new_node->next=NULL;
    return new_node;
}
class LinkedList{
Node *head;
public:

};
int main(){




}
