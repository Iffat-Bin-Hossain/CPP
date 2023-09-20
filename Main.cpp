#include<iostream>
#include<fstream>
#include<cstring>
#include<sstream>
//#include "LinkedListBasedImplementation.cpp"
#include "ArrayBasedImplementation.cpp"
using namespace std;
ofstream fout;
template<class T>
void Print(MyList<T> &l1)//Time complexity O(n)
    {
        fout<<"<";
        for(int i=0; i<l1.ListSize(); i++)
        {
            if(i==l1.CurrPos() && i==l1.ListSize()-1)
            {
                fout<<"|"<<l1.data[i];
            }
            else if(i==l1.CurrPos()){
              fout<<"|"<<l1.data[i]<<" ";
            }
            else if(i!=l1.ListSize()-1)
            {
               fout<<l1.data[i]<<" ";
            }
            else
            {
                fout<<l1.data[i];
            }
        }
        fout<<">"<<endl;
}
/*template<class T>
void Print(MyList<T> &l1)//Time complexity O(n)
{
    Node<T>* current_node=l1.head;
    int i=0;
    fout<<"<";
    while(current_node!=NULL)
    {
        if(i==l1.CurrPos() && i==l1.ListSize()-1)
        {
            fout<<"|"<<current_node->data;
        }

        else if(i==l1.CurrPos())
        {
            fout<<"|"<<current_node->data<<" ";
        }
        else if(i!=l1.ListSize()-1)
        {
            fout<<current_node->data<<" ";
        }
        else
        {
            fout<<current_node->data;
        }
        current_node=current_node->next;
        i++;
    }
    fout<<">"<<endl;
}*/
int main()
{
    ifstream fin;
    fin.open("list_input.txt");
    fout.open("list_output.txt");
    string s;
    MyList<int> l1;
    for(int i=1; i<5; i++)
    {
        l1.pushBack(i);
    }
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


    getline(fin,s);
    int K,X,Q,N;
    istringstream sso1(s);
    sso1>>K;
    sso1>>X;
    int A[K];
    getline(fin,s);
    istringstream sso2(s);
    for(int i=0; i<K; i++)
    {
        sso2>>N;
        A[i]=N;
    }
    getline(fin,s);
    istringstream sso3(s);
    sso3>>Q;
    Print(l1);
    int F[Q],P[Q];
    for(int i=0; i<Q; i++)
    {
        getline(fin,s);
        istringstream sso4(s);
        sso4>>F[i];
        sso4>>P[i];
        if(F[i]>13 || F[i]<1)
        {
            cout<<"Not enough function" <<endl;
        }
        else if(F[i]==1)
        {
            Print(l1);
            fout<<l1.ListSize()<<endl;

        }
        else  if(F[i]==2)
        {
            l1.push(P[i]);
            Print(l1);
            fout<<-1<<endl;

        }
        else  if(F[i]==3)
        {
            l1.pushBack(P[i]);
            Print(l1);
            fout<<-1<<endl;

        }
        else  if(F[i]==4)
        {
            int temp=l1.Erase();
            Print(l1);
            fout<<temp<<endl;


        }
        else  if(F[i]==5)
        {
            l1.setToBegin();
            Print(l1);
            fout<<-1<<endl;

        }
        else  if(F[i]==6)
        {
            l1.setToEnd();
            Print(l1);
            fout<<-1<<endl;

        }
        else  if(F[i]==7)
        {
            l1.prev();
            Print(l1);
            fout<<-1<<endl;

        }
        else  if(F[i]==8)
        {
            l1.next();
            Print(l1);
            fout<<-1<<endl;

        }
        else  if(F[i]==9)
        {
            Print(l1);
            fout<<l1.CurrPos()<<endl;

        }
        else  if(F[i]==10)
        {
            l1.setToPos(P[i]);
            Print(l1);
            fout<<-1<<endl;

        }
        else  if(F[i]==11)
        {
            Print(l1);
            fout<<l1.getValue()<<endl;

        }
        else  if(F[i]==12)
        {
            Print(l1);
            fout<<l1.Find(P[i])<<endl;
        }
        else
        {
            l1.Clear();
            Print(l1);
            fout<<-1<<endl;
        }

    }
    fin.close();
    fout.close();
}
