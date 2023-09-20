#include<iostream>
#include<cstdlib>
#include<cctype>
using namespace std;
class list
{
public:
    list *head,*tail,*next;
    int num;
    list()
    {
        head=tail=next=NULL;

    }
    virtual void store(int i)=0;
    virtual int retrieve()=0;

};
class queue:public list
{
public:
    void store(int i)
    {
        list *item;
        item=new queue;
        item->num=i;
        if(tail)tail->next=item;
        tail=item;
        item->next=NULL;
        if(!head) head=tail;
    }
    int retrieve()
    {
        int i;
        list *p;
        if (!head)
        {
            cout <<"List empty"<<endl;
            return 0;
        }
        i = head->num;
        p = head;
        head = head->next;
        delete p;

        return i;
    }
};
class stack: public list
{
public:
void store(int i)
    {
        list *item;

        item = new stack;
        if (!item)
        {
            cout << "Allocation Error"<<endl;
            exit(1);
        }
        item->num = i;
        if (head) item->next = head;
        head = item;
        if (!tail) tail = head;
    }
    int retrieve()
    {
        int i;
        list *p;
        if(!head)
        {
            cout << "List empty"<<endl;
            return 0;
        }
        i = head->num;
        p = head;
        head = head->next;
        delete p;

        return i;
    }

};
int main()
{
    list *p;
    stack s;
    queue q;
    char c;
    int i;
    for(i=0;i<5;i++)
    {
        cout<<"Stack or Queue(S/Q)?:";
        cin>>c;
        c=tolower(c);
        if(c=='s')p=&s;
        else p=&q;
        p->store(i);

    }
    cout<<"Enter T to terminate"<<endl;
    for( ; ; )
    {
        cout<<"Remove from stack or queue(S/Q)?:";
        cin>>c;
        c=tolower(c);
        if(c=='t')break;
        else if(c=='s')p=&s;
        else p=&q;
        cout<<"Removing "<<p->retrieve()<<"from list"<<endl;
    }
    cout<<endl;

}
