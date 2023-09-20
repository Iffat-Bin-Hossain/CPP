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
Node<T> *create_node(T item)
{
    Node<T> *new_node=new Node<T>();
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
class MyList
{
    int currPos;
    int Size;
    Node<T> *head;
public:
    MyList()
    {
        currPos=0;
        Size=0;
        head=NULL;
    }
    int ListSize()
    {
        return Size;

    }
    void push(T d)
    {
        Size++;

        if(currPos==0)
        {
            Node<T> *new_node=create_node(d);
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
    void pushBack(T d)
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
    T Erase()
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
            Size--;
            Node<T> * current_node=head;
            int i=0;
            if(currPos==0)
            {
                ret_item=head->data;
                head=head->next;
                return ret_item;
            }
            else
            {

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
                return ret_item;
            }

        }
    }
    void setToBegin()
    {
        currPos=0;
    }
    void setToEnd()
    {
        currPos=Size-1;
    }
    void prev()
    {
        if(currPos==0)
        {
            return;
        }
        currPos--;
    }
    void next()
    {
        if(currPos==Size-1)
        {
            return;
        }
        currPos++;
    }
    int CurrPos()
    {
        return currPos;
    }
    void setToPos(int pos)
    {
        currPos=pos;
    }
    T getValue()
    {
        Node<T>* current_node=head;
        int i=0;
        while(i!=currPos)
        {
            current_node=current_node->next;
            i++;
        }
        return current_node->data;
    }
    int Find(T d)
    {
        Node<T> * current_node=head;
        int i=0;
        while(i!=Size)
        {

            if(d==current_node->data)
            {
                 return i;
            }
              current_node=current_node->next;
            i++;

        }


        return -1;
    }
    void Clear()
    {
        for(int i=Size-1; i>=0; i--)
        {
            setToPos(i);
            Erase();
        }
    }
    void Print()
    {
        Node<T>* current_node=head;
        int i=0;
        cout<<"<";
        while(current_node!=NULL)
        {

            if(i==currPos)
            {
                cout<<"|"<<current_node->data<<" ";
            }
            else if(i!=Size-1)
            {
                cout<<current_node->data<<" ";
            }
            else
            {
                cout<<current_node->data;
            }
            current_node=current_node->next;
            i++;
        }
        cout<<">"<<endl;
    }

};
int main()
{
    MyList<string> l1;
    l1.Print();
    l1.pushBack("nabil");
    cout<<l1.ListSize()<<endl;
    l1.Print();
    l1.pushBack("sadi");
    l1.next();
    l1.Print();
    l1.push("rahin");
    l1.pushBack("ekin");
    l1.pushBack("ahon");
    l1.pushBack("sumon");
    l1.Print();
    l1.setToBegin();
    l1.Print();

    cout<<l1.ListSize()<<endl;
    cout<<l1.CurrPos()<<endl;

    l1.next();
    l1.Print();
    l1.setToEnd();
    l1.Print();
    cout<<l1.getValue()<<endl;
    l1.prev();
    l1.Print();
    cout<<l1.getValue()<<endl;
    cout<<l1.Find("iffat")<<endl;
    cout<<l1.Find("ahon")<<endl;

    l1.setToPos(3);
    l1.Print();
    cout<<l1.Erase()<<endl;

    l1.Print();
    cout<<l1.CurrPos()<<endl;
    cout<<l1.Erase()<<endl;
    l1.Print();
    cout<<l1.CurrPos()<<endl;
    l1.Print();

    l1.Clear();
    cout<<l1.Erase()<<endl;
    l1.Print();


}
