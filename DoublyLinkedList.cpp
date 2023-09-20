#include<iostream>
#include<typeinfo>
using namespace std;
template <class T>
class Node
{
public:
    T data;
    Node* prev;
    Node* next;
};
template<class T>
Node<T>* create_node(T d)
{
    Node<T>* new_node=new Node<T>;
    new_node->data=d;
    new_node->prev=NULL;
    new_node->next=NULL;
    return new_node;
}
template <class T>
class DLL
{
public:
    Node<T> *head;
    Node<T>* tail;
    int length;
    DLL()
    {
        head=NULL;
        tail=NULL;
        length=0;
    }
    void Prepend(T d)
    {
        Node<T>* new_node=create_node(d);
        if(length==0)
        {
            head=new_node;
            tail=head;
        }
        else
        {
            head->prev=new_node;
            new_node->next=head;
            head=new_node;
        }
        length++;

    }
    void Append(T d)
    {
        Node<T>* new_node=create_node(d);
        if(length==0)
        {
            head=new_node;
            tail=head;
        }
        else
        {
            tail->next=new_node;
            new_node->prev=tail;
            tail=new_node;

        }
        length++;

    }
    void Insert(T d,int index)
    {
        int i=0;
        Node<T>* new_node=create_node(d);
        if(index>=length)
        {
            cout<<"Index crosses LL length"<<endl;

        }
        else if(index==0)
        {

        }
        while()



            length++;

    }
    T ()
    {
        if(head==NULL)
        {
            cout<<"Empty Arraylist"<<endl;
            if(typeid(T)==typeid(string))
            {
                return (T)"";
            }
            return NULL;
        }
    }
};
int main()
{


}

