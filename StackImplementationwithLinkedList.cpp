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
    int TOS;
    Node<T>* head;
public:
    Stack()
    {
        TOS=0;
        head=NULL;
    }
    Stack(T A[],int s=0)
    {
        this->TOS=0;
        for(int i=0; i<s; i++)
        {
            this->push(A[i]);

        }
    }
    void push(T d)//Time Complexity O(1)
    {
        Node<T>* new_node=create_node(d);
        if(TOS==0)
        {
            head=new_node;
        }
        else
        {
            new_node->next=head;
            head=new_node;
        }
        TOS++;

    }
    T pop()//Time Complexity O(1)
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
            Node<T>* temp_node=head->next;
            delete head;
            head=temp_node;
            return temp;
        }
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
            pop();
        }
    }
    int length()
    {
        return TOS;
    }
    T topValue()
    {
        if(TOS==0)
        {
            cout<<"Stack Empty"<<endl;
            if(typeid(T)==typeid(string))
            {
                return (T)"";
            }
            return NULL;
        }
        return head->data;
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
    void Print()
    {
        cout<<"<";
        Node<T>* current_node=head;
        while(current_node!=NULL)
        {
            if(current_node->next!=NULL)
            {
                cout<<current_node->data<<" ";
            }
            else
            {
                cout<<current_node->data;
            }
            current_node=current_node->next;

        }
        cout<<">"<<endl;
    }
};
int main()
{
    int A[5];
    for(int i=0; i<5; i++)
    {
        A[i]=2*i+1;
    }
    Stack<int> s;
    cout<<s.length()<<endl;
    s.Print();
    for(int i=0; i<6; i++)
    {
        s.push((i+1)*2);
    }
    s.Print();
    cout<<s.length()<<endl;
    cout<<s.topValue()<<endl;
    cout<< s.pop()<<endl;
    s.Print();
    cout<<s.topValue()<<endl;
    s.Clear();
    cout<<s.length()<<endl;
    s.Print();
    cout<<s.topValue()<<endl;
    s.push(100);
    s.push(500);
    cout<<s.length()<<endl;
    cout<<s.topValue()<<endl;
    s.Print();
}

