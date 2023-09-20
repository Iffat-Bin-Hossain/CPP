#include<iostream>
#include<typeinfo>
using namespace std;
template <class T>
class Stack
{
    int TOS;
    int capacity;
    T *data;
public:
    Stack(int c)
    {
        capacity=c;
        data=new T[c];
        TOS=0;
    }
    Stack(T A[],int c,int s=0)
    {
        if(s<c)
        {
            this->capacity=c;
            this->TOS=s;
            this->data=new T[c];
            for(int i=0; i<s; i++)
            {
                this->data[i]=A[i];

            }

        }
        else
        {
            cout<<"Array exceeds initial capacity"<<endl;
            exit(1);
        }

    }
    void push(T d)//Time Complexity O(1)
    {
        T *temp_data;

        if(TOS==capacity)
        {
            capacity*=2;
            temp_data=data;
            data=new T[capacity];
            for(int i=0; i<TOS; i++)
            {
                data[i]=temp_data[i];
            }
            delete temp_data;
        }
        data[TOS++]=d;
    }
    T pop()
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
        return data[--TOS];
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
        //delete[] data;
        //data=new T[4];

    }
    int Length()
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
        return data[TOS-1];
    }
    ~Stack()
    {
        delete[] data;
    }

};
