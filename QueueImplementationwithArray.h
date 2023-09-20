#include<iostream>
#include<typeinfo>
using namespace std;
template<class T>
class Queue
{
    public:
    int capacity,length,Front,Rear;
    T *data;

    Queue(int c)
    {
        capacity=c;
        length=0;
        data=new T[capacity];
        Front=-1;
        Rear=-1;
    }
    Queue(T A[],int c,int l=0)
    {
        if(l<=c)
        {
            this->Front=-1;
            this->Rear=-1;
            this->capacity=c;
            this->length=l;
            this->data=new T[c];
            for(int i=0; i<l; i++)
            {
                if(i==0)
                {
                    this->Front=0;
                }
                this->Rear++;
                this->data[i]=A[i];

            }
        }
        else
        {
            cout<<"Array exceeds initial capacity"<<endl;
            exit(1);
        }

    }
    void Enqueue(T d)
    {
        T *temp_data;
        if(Front==-1 && Rear==-1)
        {
            Front=0;
            Rear=0;
            data[Rear]=d;
        }
        else if(((Rear+1)%capacity)==Front)
        {
            capacity*=2;
            temp_data=data;
            data=new T[capacity];
            for(int i=0; i<length; i++)
            {
                data[i]=temp_data[i];
            }
            delete temp_data;
            Rear=(Rear+1)%capacity;
            data[Rear]=d;

        }
        else
        {
            Rear=(Rear+1)%capacity;
            data[Rear]=d;
        }

        length++;

    }
    T Dequeue()
    {
        if(Front==-1 && Rear==-1)
        {
            cout<<"Queue Empty"<<endl;
            if(typeid(T)==typeid(string))
            {
                return (T)"";
            }
            return (T)NULL;
        }
        else if(Front==Rear)
        {
            length--;
            T x=data[Rear];
            Front=Rear=-1;
            return x;
        }
        else
        {
            length--;
            T x=data[Front];
            Front=(Front+1)%capacity;
            return x;

        }
    }
    void Clear()
    {
        if(length==0)
        {
            cout<<"Queue Empty"<<endl;
            return;

        }

        int x=length;
        for(int i=0; i<x; i++)
        {
            Dequeue();
        }
        //delete[]data;
        //data=new T[4];
    };
    int Length()
    {
        return length;
    }
    T frontValue()
    {
        if(Front<0)
        {
            cout<<"Queue Empty"<<endl;
            if(typeid(T)==typeid(string))
            {
                return (T)"";
            }
            return (T)NULL;

        }
        return data[Front];
    }
    T rearValue()
    {
        if(length==0)
        {
            cout<<"Queue Empty"<<endl;
            if(typeid(T)==typeid(string))
            {
                return (T)"";
            }
            return (T)NULL;

        }
        return data[Rear];
    }
    T leaveQueue()
    {
        if(length==0)
        {
            cout<<"Queue Empty"<<endl;
            if(typeid(T)==typeid(string))
            {
                return (T)"";
            }
            return (T)NULL;
        }

        T x=data[Rear];
        if(Rear==Front)
        {
            Rear=-1;
            Front=-1;
        }
        if(Rear==0)
        {
            Rear=capacity-1;
        }
        else
        {
            Rear--;
        }
        length--;
        return x;
    }
    ~Queue()
    {
        delete[] data;
    }

};
/*int main()
{
    int A[5];
    for(int i=0; i<5; i++)
    {
        A[i]=i;
    }
    Queue<int> q(A,10,5);
    cout<<q.Length()<<endl;
    q.Print();
    //q.Print();
    q.leaveQueue();
    q.Print();
    q.Clear();
    q.Print();
    cout<<q.Length()<<endl;
    for(int i=0; i<4; i++)
    {
        q.Enqueue((i+1)*2);
    }
    q.Print();
    cout<<q.Length()<<endl;
    cout<<q.frontValue()<<endl;
    cout<<q.rearValue()<<endl;
}*/
