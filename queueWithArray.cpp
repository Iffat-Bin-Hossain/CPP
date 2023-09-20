#include<iostream>
using namespace std;
class Queue
{
    int Size,Front,Rear;
    int *data;
public:
    Queue(int S)
    {
        cout<<"Initializing Queue...."<<endl;
        Size=S;
        data=(int *)malloc(Size*sizeof(int));
        Front=Rear=0;
    }
    bool isEmpty()
    {
        if(Front==Rear)
        {
            return true;
        }
        return false;
    }
    bool isFull()
    {
        if(Rear==Size)
        {
            return true;
        }
        return false;
    }
    void Enqueue(int d){
        if(isFull()){
            cout<<"Queue Overflow"<<endl;
        }
        else{
            data[Rear++]=d;
        }

    }
    int Dequeue(){
    if(isEmpty()){
     cout<<"Queue Empty"<<endl;
     return NULL;
    }
    else{

        return data[Front++];
    }
    }
    void printQueue(){
    if(isEmpty()){
    cout<<"Queue Empty"<<endl;
    }
    else{
        cout<<"Printing Queue...."<<endl;
        for(int i=Front;i<Rear;i++){
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
            for( i=Rear-1; i>j; i-- && j++)
            {

                int T=data[i];
                data[i]=data[j];
                data[j]=T;

            }
        }
    }
    void clearQueue(){
        if(isEmpty())
        {
            cout<<"Queue Empty"<<endl;

        }
        else
        {
            int x=Rear;
            for(int i=0; i<x; i++)
            {
                Dequeue();
            }
            cout<<"Queue Cleared...."<<endl;

        }


    }
    ~Queue(){
    cout<<"Freeing...."<<endl;
    free(data);
    }

};
int main()
{
Queue Q1(5);
cout<<"Retrieving :"<<Q1.Dequeue()<<endl;
Q1.Enqueue(1);
Q1.printQueue();
Q1.Enqueue(2);
Q1.Enqueue(3);
Q1.Enqueue(4);
Q1.Enqueue(5);
Q1.Enqueue(6);
Q1.printQueue();
Q1.reverseQueue();
//Q1.clearQueue();
Q1.printQueue();
cout<<"Retrieving :"<<Q1.Dequeue()<<endl;
Q1.printQueue();
Q1.reverseQueue();
Q1.printQueue();
cout<<"Retrieving :"<<Q1.Dequeue()<<endl;
Q1.printQueue();
Q1.reverseQueue();
Q1.printQueue();
cout<<"Retrieving :"<<Q1.Dequeue()<<endl;
Q1.printQueue();
cout<<"Retrieving :"<<Q1.Dequeue()<<endl;
cout<<"Retrieving :"<<Q1.Dequeue()<<endl;
cout<<"Retrieving :"<<Q1.Dequeue()<<endl;
Q1.printQueue();
Q1.Enqueue(2);
Q1.Enqueue(3);
Q1.Enqueue(4);
Q1.Enqueue(5);
Q1.Enqueue(6);
Q1.printQueue();
}
