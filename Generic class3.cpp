#include<iostream>
using namespace std;
template<class T>class list
{
    T data;
    list *next;
public:
    list(T d);
    void add(list *node)
    {
      node->next=this;
      next=0;//Assigning a null value
      //cout<<node->next<<endl;
    }
    list *getnext()
    {
        return next;
    }
    T getdata()
    {
        return data;
    }


};
template<class T>
list<T>::list(T d)
{
    data=d;
    next=0;
}
int main()
{
    list<char>ob1('a');
    list<char>*p,*ob2;
    int i;
    ob2=&ob1;
    for(i=1;i<26;i++)
    {
        p=new list<char>('a'+i);
        p->add(ob2);
        ob2=p;
    }
    p=&ob1;
    while(p)
    {
        cout<<"         "<<p->getdata()<<endl;
        p=p->getnext();
    }
    return 0;
}
