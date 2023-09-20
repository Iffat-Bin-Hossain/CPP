#include<iostream>
#include<typeinfo>
using namespace std;
/*template <class T>
class Node
{
public:
    T data;
    Node* next;
};*/
/*template<class T>
Node<T>* create_node(T d)
{
    Node<T>* new_node=new Node<T>;
    new_node->data=d;
    new_node->next=NULL;
    return new_node;
}*/
template<class T>
class Queue
{
    public:
    int length,Front,Rear;
    Node<T>* head;

    Queue()
    {
        length=0;
        head=NULL;
        Front=Rear=-1;
    }
    Queue(T A[],int l=0)
    {
        this->length=0;
        for(int i=0; i<l; i++)
        {

            this->Enqueue(A[i]);

        }
    }
    void Enqueue(T d)
    {
        if(length==0)
        {
            Front=Rear=0;
            Node<T>* new_node=create_node(d);
            head=new_node;
        }
        else
        {
            Node<T>* new_node=create_node(d);
            Node<T>* current_node=head;
            while(current_node->next!=NULL)
            {
                current_node=current_node->next;
            }
            current_node->next=new_node;
            Rear++;
        }
        length++;
    }
    T Dequeue()
    {
        if(length==0)
        {
            cout<<"Empty Queue"<<endl;
            /*if(typeid(T)==typeid(string))
            {
                return (T)"";
            }
            return NULL;*/

        }
        else
        {
            T ret_item=head->data;
            head=head->next;
            Front++;
            length--;
            return ret_item;

        }

    }
    void Clear()
    {
        int x=length;
        for(int i=0; i<x; i++)
        {
            Dequeue();
        }

        Rear=-1;
        Front=-1;
    }
    int Length()
    {
        return length;
    }
    T frontValue()
    {
        if(length==0)
        {
            cout<<"Empty Queue"<<endl;
            if(typeid(T)==typeid(string))
            {
                return (T)"";
            }
            return NULL;

        }
        return head->data;
    }
    T rearValue()
    {
        if(length==0)
        {
            cout<<"Empty Queue"<<endl;
            if(typeid(T)==typeid(string))
            {
                return (T)"";
            }
            return NULL;

        }
        int i=Front;
        Node<T>* current_node=head;
        while(i!=Rear)
        {
            current_node=current_node->next;
            i++;
        }
        return current_node->data;
    }
    T leaveQueue()
    {
        Node<T>* current_node=head;
        int i=Front;
        while(i<Rear-1)
        {
            current_node=current_node->next;
            i++;
        }
        T x=current_node->next->data;
        current_node->next=NULL;
        Rear--;
        length--;
        return x;
    }
    ~Queue()
    {
        Node<T>* new_node=head;
        while(new_node!=NULL)
        {
            Node<T>* temp_node=new_node->next;
            delete new_node;
            new_node=temp_node;
        }
        delete new_node;

    }

};
/*int main()
{
    int A[30];
    for(int i=0; i<25; i++)
    {
        A[i]=i;
    }
    Queue<int> q(A,25);
    cout<<q.Length()<<endl;
    q.Print();
    //q.Print();
    cout<<q.leaveQueue()<<endl;
    q.Print();
    q.Clear();
    q.Print();
    cout<<q.Length()<<endl;
    for(int i=0; i<28; i++)
    {
        q.Enqueue((i+1)*2);
    }
    q.Print();
    for(int i=0;i<14;i++){
        cout<<q.Dequeue()<<" "<<q.leaveQueue()<<endl;
        q.Print();
    }
}*/
