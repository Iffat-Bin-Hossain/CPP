#include<iostream>
#include<typeinfo>
using namespace std;
template<class T>
class Node
{
public:
    T  data;
    Node *next;

};
template<class T>
Node<T> *create_node(T item)//Time Complexity O(1)
{
    Node<T> *new_node=new Node<T>;
    if(new_node==NULL)
    {

        cout<<"Allocation Error!!!"<<endl;
        exit(1);
    }
    new_node->data=item;
    new_node->next=NULL;
    return new_node;
}
template<class T>
class LinkedList
{
public:

    int currPos;
    int Size;
    Node<T> *head;

    LinkedList()
    {
        currPos=0;
        Size=0;
        head=NULL;
    }
    LinkedList(const LinkedList<T> &l)
    {
        this->currPos=l.currPos;
        this->Size=0;
        Node<T> * Current=l.head;
        while(Current !=NULL)
        {
            this->pushBack(Current->data);
            Current=Current->next;

        }
    }
    LinkedList(T A[],int s)
    {
        this->currPos=0;
        this->Size=0;
        for(int i=0; i<s; i++)
        {

            this->pushBack(A[i]);

        }
    }
    int ListSize()
    {
        return Size;

    }
    void push(T d)//Time Complexity O(n)
    {
        Size++;

        if(currPos==0)
        {
            Node<T> *new_node=create_node(d);
            new_node->next=head;
            head=new_node;

        }
        else
        {
            Node<T> *current_node=head;
            int i=0;
            while(i!=currPos-1)
            {
                current_node=current_node->next;
                i++;
            }
            Node<T> *new_node=create_node(d);
            new_node->next=current_node->next;
            current_node->next=new_node;
        }


    }
    void pushBack(T d)//Time Complexity O(n)
    {
        if(Size==0)
        {
            Node<T> *new_node=create_node(d);
            head=new_node;

        }
        else
        {
            Node<T> *current_node=head;
            while(current_node->next!=NULL)
            {
                current_node=current_node->next;
            }
            Node<T> *new_node=create_node(d);
            current_node->next=new_node;
        }
        Size++;
    }
    T Erase()//Time Complexity O(n)
    {
        if(Size==0)
        {
            cout<<"Empty Arraylist"<<endl;
            if(typeid(T)==typeid(string))
            {
                return (T)"";
            }
            return NULL;

        }
        else
        {
            T ret_item;

            Node<T> * current_node=head;

            if(currPos==0)
            {
                ret_item=head->data;
                head=head->next;
                Size--;
                return ret_item;
            }
            else
            {
                int i=0;
                while(i!=currPos-1)
                {
                    current_node=current_node->next;
                    i++;
                }
                if(currPos==Size-1)
                {
                    currPos--;
                }
                ret_item=current_node->next->data;
                current_node->next=current_node->next->next;
                Size--;
                return ret_item;
            }


        }
    }
    void setToBegin()//Time Complexity O(1)
    {
        currPos=0;
    }
    void setToEnd()//Time Complexity O(1)
    {
        currPos=Size-1;
    }
    void prev()//Time Complexity O(1)
    {
        if(currPos==0)
        {
            return;
        }
        currPos--;
    }
    void next()//Time Complexity O(1)
    {
        if(currPos==Size-1)
        {
            return;
        }
        currPos++;
    }
    int CurrPos()//Time Complexity O(1)
    {
        return currPos;
    }
    void setToPos(int pos)//Time Complexity O(1)
    {
        if(pos<0 || pos>=Size)
        {
            return;
        }
        currPos=pos;
    }
    T getValue()//Time Complexity O(n)
    {
        if(Size==0)
        {
            cout<<"Empty Arraylist"<<endl;
            /*if(typeid(T)==typeid(string))
            {
                return (T)"";
            }*/
            //return NULL;

        }
        Node<T>* current_node=head;
        int i=0;
        while(i!=currPos)
        {
            current_node=current_node->next;
            i++;
        }
        return current_node->data;
    }
    int Find(T d)//Time Complexity O(n)
    {
        Node<T> * current_node=head;
        int i=0;
        while(i!=Size)
        {

            if(d==current_node->data.value)
            {
                return i;
            }
            current_node=current_node->next;
            i++;

        }


        return -1;
    }

    void Clear()//Time Complexity O(n)
    {
        for(int i=Size-1; i>=0; i--)
        {
            setToPos(i);
            Erase();
        }
    }

    ~LinkedList()
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
    void Print()//Time complexity O(n)
    {
        Node<T>* current_node=this->head;
        int i=0;
        cout<<"< ";
        while(current_node!=NULL)
        {
            cout<<current_node->data<<" ";

            current_node=current_node->next;
            i++;
        }
        cout<<">"<<endl;
    }
};
