#include<iostream>
#include<fstream>
#include<sstream>
#include "ArrayBasedImplementation.cpp"
//#include "LinkedListBasedImplementation.cpp"
using namespace std;
template<class T>
bool exist(MyList<T> &l,T k)//Time Complexity O(n)
{
    for(int i=0; i<l.ListSize(); i++)
    {
        if(l.data[i]==k)
        {
            return true;
        }


    }
    return false;
}
/*template<class T>
bool exist(MyList<T> &l,T k)//Time Complexity O(n)
{
    Node<T> * current_node=l.head;
    while(current_node!=NULL)
    {
        if(k==current_node->data)
        {
            return true;
        }
        current_node=current_node->next;
    }
    return false;
}*/
template<class T>
class LRUCache
{
public:
    MyList<T> Key,Value;
    int capacity;

    LRUCache(int c)
    {
        capacity=c;

    }
    T get(T key)//Time Complexity O(n)
    {
        if(exist(Key,key))
        {
            int i =Key.Find(key);
            Key.setToPos(i);
            Value.setToPos(i);
            int v = Value.getValue();

            Key.Erase();
            Value.Erase();
            Key.pushBack(key);
            Value.pushBack(v);
            return v;
        }
        else
        {
            return -1;
        }

    }
    void put(T key,T v)//Time Complexity O(n)
    {
        if(exist(Key,key))
        {
            int i =Key.Find(key);
            Key.setToPos(i);
            Value.setToPos(i);
            Key.Erase();
            Value.Erase();
        }
        else if(Key.ListSize()==capacity)
        {
            Key.setToBegin();
            Key.Erase();
            Value.setToBegin();
            Value.Erase();
        }
        Key.pushBack(key);
        Value.pushBack(v);
    }

};
int main()
{
    ifstream fin("lru_input.txt");
    ofstream fout("lru_output.txt");

    if(!fin)
    {
        cout<<"File cannot be opened";
        exit(1);
    }
    if(!fout)
    {
        cout<<"File cannot be opened";
        exit(1);
    }
    string s;
    int C,Q;
    getline(fin,s);
    istringstream sso1(s);
    sso1>>C;
    if(C<=0)
    {
        exit(0);
    }
    LRUCache<int> lru(C);
    getline(fin,s);
    istringstream sso2(s);
    sso2>>Q;
    int O[Q],X[Q],Y[Q];
    for(int i=0; i<Q; i++)
    {
        getline(fin,s);
        istringstream sso3(s);
        sso3>>O[i];
        if(O[i]==1)
        {
            sso3>>X[i];
            fout<<lru.get(X[i])<<endl;
        }
        else if(O[i]==2)
        {
            sso3>>X[i];
            sso3>>Y[i];
            lru.put(X[i],Y[i]);
        }
        else
        {
            cout<<"Operation not available"<<endl;
        }

    }
    fin.close();
    fout.close();


}
