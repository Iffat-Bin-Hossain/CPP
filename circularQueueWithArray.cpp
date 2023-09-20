#include<iostream>
using namespace std;
class CircularQueue
{
    int Size,Front,Rear;
    int *data;
public:
    CircularQueue(int S)
    {
        cout<<"Initializing Circular Queue...."<<endl;
        Size=S;
        data=(int *)malloc(Size*sizeof(int));
        Front=Rear=-1;
    }
    bool isEmpty()
    {
        if(Front==-1 && Rear==-1)
        {
            return true;
        }
        return false;
    }
    bool isFull()
    {
        if(((Rear+1)%Size)==Front)
        {
            return true;
        }
        return false;
    }
    void Enqueue(int d)
    {
        if(isFull())
        {
            cout<<"Queue Overflow"<<endl;
        }
        else if(isEmpty()){
            Front=Rear=0;
            data[Rear]=d;
        }
        else
        {
            Rear=(Rear+1)%Size;
            data[Rear]=d;

        }

    }
    int Dequeue()
    {
        if(isEmpty())
        {
            cout<<"Queue Empty"<<endl;
            return NULL;
        }
        else if(Front==Rear)
        {
            cout<<"Queue Empty"<<endl;
            Front=Rear=-1;
            return NULL;
        }
        else
        {
            int x=Front;
            Front=(Front+1)%Size;
            return data[x];
        }
    }
    void printQueue(){
    if(isEmpty()){
    cout<<"Queue Empty"<<endl;
    }
    else{
        cout<<"Printing Queue...."<<endl;
        for(int i=Front;i<=Rear;i++){
            cout<<data[i]<<" ";

        }
        cout<<endl;
    }
    }
     void reverseQueue(){
    int i,j;
        if(isEmpty())
        {
            cout<<"Queue Empty"<<endl;
        }
        else
        {
            cout<<"Reversing Queue....."<<endl;
            j=Front;
            for( i=Rear; i>j; i-- && j++)
            {

                int T=data[i];
                data[i]=data[j];
                data[j]=T;

            }
        }
    }


};
int main()
{
CircularQueue CQ1(5);
cout<<"Retrieving :"<<CQ1.Dequeue()<<endl;
CQ1.Enqueue(1);
CQ1.printQueue();
CQ1.Enqueue(2);
CQ1.Enqueue(3);
CQ1.Enqueue(4);
CQ1.Enqueue(5);
CQ1.Enqueue(6);
CQ1.printQueue();
CQ1.reverseQueue();
//Q1.clearQueue();
CQ1.printQueue();
cout<<"Retrieving :"<<CQ1.Dequeue()<<endl;
CQ1.printQueue();
CQ1.reverseQueue();
CQ1.printQueue();
cout<<"Retrieving :"<<CQ1.Dequeue()<<endl;
CQ1.printQueue();
CQ1.reverseQueue();
CQ1.printQueue();
cout<<"Retrieving :"<<CQ1.Dequeue()<<endl;
CQ1.printQueue();
cout<<"Retrieving :"<<CQ1.Dequeue()<<endl;
cout<<"Retrieving :"<<CQ1.Dequeue()<<endl;
cout<<"Retrieving :"<<CQ1.Dequeue()<<endl;
CQ1.printQueue();
CQ1.Enqueue(2);
CQ1.Enqueue(3);
CQ1.Enqueue(4);
CQ1.Enqueue(5);
CQ1.Enqueue(6);
CQ1.printQueue();
}
