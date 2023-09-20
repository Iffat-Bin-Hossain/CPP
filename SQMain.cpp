#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
//#include "StackImplementationwithArray.h"
#include "StackImplementationwithLinkedList.h"
//#include "QueueImplementationwithArray.h"
#include "QueueImplementationwithLinkedList.h"
using namespace std;
ofstream fout;
/*template<class T>
void print(Stack<T> &s)
{
    fout<<"<";
    int x=s.Length();
    for(int i=0; i<x; i++)
    {
        if(i==x-1)
        {
            fout<<"|"<<s.data[i];
        }
        else
        {
            fout<<s.data[i]<<" ";
        }

    }
    fout<<">"<<endl;
}*/
template<class T>
void print(Stack<T> &s)
{
    fout<<"<";
    Node<T>* current_node=s.head;
    while(current_node!=NULL)
    {
        if(current_node==s.head)
        {
            fout<<"|"<<current_node->data<<" ";
        }
        else if(current_node->next==NULL){
         fout<<current_node->data ;
        }
        else
        {
            fout<<current_node->data<<" ";
        }
        current_node=current_node->next;

    }
    fout<<">"<<endl;
}
/*template<class T>
void print(Queue<T> &q)
{
    fout<<"<";
    if(q.Front!=-1 && q.Rear!=-1)
    {
        if(q.Rear>=q.Front)
        {
            for(int i=q.Front; i<=q.Rear; i++)
            {
                if(i==q.Front)
                {
                    fout<<"|"<<q.data[i]<<" ";
                }
                else if(i==q.Rear)
                {
                    fout<<q.data[i];
                }

                else
                {
                    fout<<q.data[i]<<" ";
                }
            }
        }
        else
        {
            int i;
            for(i=q.Front; i<q.capacity; i++)
            {
                fout<<q.data[i]<<" ";
            }
            i=0;
            for(i=0; i<=q.Rear; i++)
            {
                if(i==q.Front)
                {
                    fout<<"|"<<q.data[i]<<" ";
                }
                else if(i==q.Rear)
                {
                    fout<<q.data[i];
                }
                else
                {
                    fout<<q.data[i]<<" ";
                }
            }

        }
    }
    fout<<">"<<endl;
}*/
template<class T>
void print(Queue<T> &q)
{
    Node<T>* current_node=q.head;
    fout<<"<";
    while(current_node!=NULL)
    {
        if(current_node==q.head)
        {
           fout<<"|"<<current_node->data<<" ";
        }
        else if(current_node->next==NULL)
        {
            fout<<current_node->data;
        }
        else
        {
            fout<<current_node->data<<" ";
        }
        current_node=current_node->next;
    }
    fout<<">"<<endl;
}
int main()
{
    ifstream fin;
    fin.open("sq_input.txt");
    fout.open("sq_output.txt");
    string str;

    if(!fin)
    {
        cout<<"IFile cannot be opened";
        exit(1);
    }
    if(!fout)
    {
        cout<<"File cannot be opened";
        exit(1);
    }
    getline(fin,str);
    int K,X,M,Y,N;
    istringstream sso1(str);
    sso1>>K;
    sso1>>X;
    //Queue<int> q(X);
    //Queue<int> q;
    int Q[K];
    getline(fin,str);
    istringstream sso2(str);
    for(int i=0; i<K; i++)
    {
        sso2>>N;
        Q[i]=N;
    }
    Queue<int> q(Q,K);
    //Queue<int> q(Q,K);
    getline(fin,str);
    istringstream sso3(str);
    sso3>>M;
    sso3>>Y;
    //Stack<int> s(Y);
    //Stack<int> s;
    int S[K];
    getline(fin,str);
    istringstream sso4(str);
    for(int i=0; i<M; i++)
    {
        sso4>>N;
        S[i]=N;
    }
    Stack<int> s(S,M);
    //Stack<int> s(S,M);
    int Nop;
    getline(fin,str);
    istringstream sso5(str);
    sso5>>Nop;
    int F[Nop],P[Nop];
    print(q);
    print(s);
    for(int i=0; i<Nop; i++)
    {
        getline(fin,str);
        istringstream sso6(str);
        sso6>>F[i];
        sso6>>P[i];
        if(F[i]>12 || F[i]<1)
        {
            cout<<"No Available Operation" <<endl;
        }
        else if(F[i]==1)
        {
            q.Clear();
            print(q);
            fout<<-1<<endl;
        }
        else if(F[i]==2)
        {

            q.Enqueue(P[i]);
            print(q);
            fout<<-1<<endl;
        }
        else if(F[i]==3)
        {
            int x=q.Dequeue();
            print(q);
            fout<<x<<endl;
        }
        else if(F[i]==4)
        {
            print(q);
            fout<<q.Length()<<endl;
        }
        else if(F[i]==5)
        {
            print(q);
            fout<<q.frontValue()<<endl;

        }
        else if(F[i]==6)
        {
            print(q);
            fout<<q.rearValue()<<endl;


        }
        else if(F[i]==7)
        {
            int x=q.leaveQueue();
            print(q);
            fout<<q.leaveQueue()<<endl;


        }
        else if(F[i]==8)
        {
            s.Clear();
            print(s);
            fout<<-1<<endl;

        }
        else if(F[i]==9)
        {
            s.push(P[i]);
            print(s);
            fout<<-1<<endl;


        }
        else if(F[i]==10)
        {
            int x=s.pop();
            print(s);
            fout<<x<<endl;


        }
        else if(F[i]==11)
        {
            int x=s.Length();
            print(s);
            fout<<x<<endl;

        }
        else
        {
            print(s);
            fout<<s.topValue()<<endl;

        }

    }

}
