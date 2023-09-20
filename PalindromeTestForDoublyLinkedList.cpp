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
            return;

        }
        else if(index==0)
        {
            new_node->next=head;
            head =new_node;
        }
        else
        {
            Node<T>* current_node=head;
            i=0;
            while(i!=index-1)
            {
                current_node=current_node->next;
                i++;
            }
            new_node->prev=current_node;
            new_node->next=current_node->next;
            current_node->next=new_node;

        }
        length++;

    }
    T Delete(int index)
    {
        if(head==NULL)
        {
            cout<<"Empty list"<<endl;
            if(typeid(T)==typeid(string))
            {
                return (T)"";
            }
            return NULL;
        }
        else if(index>length)
        {
            cout<<"Index crosses LL length"<<endl;
            if(typeid(T)==typeid(string))
            {
                return (T)"";
            }
            return NULL;
        }
        else if(index==0)
        {
            head=head->next;
            head->prev=NULL;
            length--;
        }
        else if(index==length-1)
        {
            tail=tail->prev;
            tail->next=NULL;
            length--;
        }
        else
        {
            Node<T>* current_node=head;
            int i=0;
            while(i!=index)
            {
                current_node=current_node->next;
                i++;
            }
            current_node->prev->next=current_node->next;
            current_node->next->prev=current_node->prev;
            length--;
        }
    }
};
int main()
{
    DLL<int> d;


}


