#include<iostream>
#include<typeinfo>
using namespace std;
template <class T>
class Stack
{
    int TOS;
    int Size;
    T *data;
public:
    Stack(int s)
    {
        cout<<"Initializing Stack...."<<endl;
        Size=s;
        data=(T *)malloc(Size*sizeof(T));
        TOS=0;
    }
    bool isFull()
    {
        if(TOS==Size)
        {
            return true;
        }
        return false;

    }
    bool isEmpty()
    {
        if(TOS==0)
        {
            return true;
        }
        return false;
    }
    void push(T d)
    {
        if(isFull())
        {
            cout<<"Stack Overflow"<<endl;

        }
        else
        {
            data[TOS++]=d;
        }

    }
    T pop()
    {
        if(isEmpty())
        {
            cout<<"Stack Empty"<<endl;
            if(typeid(T)==typeid(string)){
               return (T)"";
            }
            return NULL;

        }
        return data[--TOS];
    }
    void printStack()
    {
        if(isEmpty())
        {
            cout<<"Stack Empty"<<endl;
        }
        else
        {
            cout<<"Printing Stack....."<<endl;
            for(int i=TOS-1; i>=0; i--)
            {
                cout<<data[i]<<endl;


            }
        }

    }
    void reverseStack()
    {
        int i,j;
        if(isEmpty())
        {
            cout<<"Stack Empty"<<endl;
        }
        else
        {
            cout<<"Reversing Stack....."<<endl;
            j=0;
            for( i=(TOS-1); i>j; i-- && j++)
            {

                T temp=data[i];
                data[i]=data[j];
                data[j]=temp;

            }
        }
    }
    void clearStack()
    {
        if(isEmpty())
        {
            cout<<"Stack Empty"<<endl;

        }
        else
        {
            int x=TOS;
            for(int i=0; i<x; i++)
            {
                pop();
            }
            cout<<"Stack Cleared...."<<endl;

        }


    }



    ~Stack()
    {
        cout<<"Freeing...."<<endl;
        free(data);
    }

};
int main()
{

    Stack<int> S1(6);
    Stack<string> S2(3);
    S1.printStack();
    S1.push(1);
    S1.reverseStack();
    S1.printStack();
    S1.push(2);
    S1.push(3);
    S1.push(4);
    S1.push(5);
    S1.push(6);
    S1.printStack();
    S1.reverseStack();
    S1.clearStack();
    S1.printStack();
cout<<"Retrieving :"<<S1.pop()<<endl;
    S1.reverseStack();
    S1.printStack();
    cout<<"Retrieving :"<<S1.pop()<<endl;
    cout<<"Retrieving :"<<S1.pop()<<endl;
    S1.reverseStack();
    S1.printStack();
    cout<<"Retrieving :"<<S1.pop()<<endl;
    cout<<"Retrieving :"<<S1.pop()<<endl;
    cout<<"Retrieving :"<<S1.pop()<<endl;

    S1.printStack();
    S2.printStack();
    S2.push("Apple");
    S2.push("Ball");
    S2.push("Cat");
    S2.push("Dog");
    S2.printStack();
    S2.reverseStack();
    S2.printStack();
    cout<<"Retrieving :"<<S2.pop()<<endl;
    S2.reverseStack();
    S2.printStack();
    S2.clearStack();
    cout<<"Retrieving :"<<S2.pop()<<endl;


}
