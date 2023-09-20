#include<iostream>
#include<typeinfo>
using namespace std;
template <class T>
class Node
{
public:
    T data;
    Node* next;
};
template<class T>
Node<T>* create_node(T d)
{
    Node<T>* new_node=new Node<T>;
    new_node->data=d;
    new_node->next=NULL;
    return new_node;
}
template <class T>
class Stack
{
    int Size;
    int TOS;
    Node<T>* head;
public:
    Stack(int s)
    {
        Size=s;
        TOS=0;
        head=NULL;
    }
    void Push(T d)//Time Complexity O(1)
    {
        Node<T>* new_node=create_node(d);
        if(TOS>=Size)
        {
            cout<<"Stack Overflow"<<endl;
        }
        else if(TOS==0)
        {
            head=new_node;
            TOS++;
        }
        else
        {
            new_node->next=head;
            head=new_node;
            TOS++;
        }

    }
    T Pop()//Time Complexity O(1)
    {
        if(head==NULL)
        {
            cout<<"Stack Empty"<<endl;
            if(typeid(T)==typeid(string))
            {
                return (T)"";
            }
            return (T)NULL;
        }
        else
        {
            TOS--;
            T temp=head->data;
            head=head->next;
            return temp;
        }
    }
    void Reverse()
    {
        T A[TOS+1];
        if(TOS==0){
            return;
        }
        int i=0;
        Node<T>* current_node=head;
        while(current_node!=NULL)
        {
            A[i]=current_node->data;
            current_node=current_node->next;
            i++;
        }
        i--;
        current_node=head;
        while(current_node!=NULL)
        {
            current_node->data=A[i];
            current_node=current_node->next;
            i--;
        }

    }
    void aSort_linked_list()//Ascending Sort
    {
        int A[100];
        Node<T> *current=head;
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
                    int temp=A[k];
                    A[k]=A[j];
                    A[j]=temp;
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
    }
    void Print()
    {
        Node<T>* current_node=head;

        while(current_node!=NULL)
        {
            cout<<"[";
            cout<<current_node->data<<","<<current_node->next;
            current_node=current_node->next;
            cout<<"]  ";
        }
        cout<<endl;
    }
    void Clear()
    {
        if(TOS==0)
        {
            cout<<"Stack Empty"<<endl;
            return;
        }
        int x=TOS;
        for(int i=0; i<x; i++)
        {
            Pop();
        }
    }
    ~Stack()
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
int main()
{
    Stack<int> s1(5);
    for(int i=0; i<5; i++)
    {
        s1.Push(rand()%50);
    }
    s1.Print();
    s1.aSort_linked_list();
    s1.Print();
    s1.Reverse();
    s1.Print();
    s1.Clear();
    s1.Print();
}
