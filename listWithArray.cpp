#include<iostream>
#include<typeinfo>
using namespace std;
template <class T>class Arraylist
{
    int Capacity,Size;
    T *data;
public:
    Arraylist(int c)
    {
        cout<<"Initializing Arraylist..."<<endl;
        Capacity=c;
        Size=0;
        data=(T *)malloc(Capacity*sizeof(T));
    }
    bool isEmpty()
    {
        return Size==0;
    }
    void Append(T d)
    {
       /* if(Size==Capacity)
        {
            Capacity++;
            data=(T*)realloc(data,Capacity);

        }*/
        data[Size++]=d;

    }
    void Insert(T d,int index)//index=-preceding index of inserted data
    {
        if(index>Size)
        {
            cout<<"Arraylist out of index"<<endl;
        }
        else
        {
           /* if(Size==Capacity)
            {
                Capacity++;
                data=(T*)realloc(data,Capacity);

            }*/
            for(int i=Size; i>index; i--)
            {
                data[i]=data[i-1];
            }
            data[index]=d;
            Size++;

        }
    }
    T Remove(int index)
    {
        if(isEmpty())
        {
            cout<<"Empty Arraylist"<<endl;
            if(typeid(T)==typeid(string))
            {
                return (T)"";
            }
            return NULL;
        }
        else if(index>Size)
        {
            cout<<"Arraylist out of index"<<endl;
            if(typeid(T)==typeid(string))
            {
                return (T)"";
            }
            return NULL;
        }
        else
        {
            T x=data[index];
            for(int i=index; i<Size; i++)
            {
                data[i]=data[i+1];
            }
            Size--;
            return x;
        }

    }
    void printArrayList()
    {
        if(isEmpty())
        {
            cout<<"Empty Arraylist"<<endl;
        }
        else
        {
            cout<<"Printing Arraylist..."<<endl;
            for(int i=0; i<Size; i++)
            {
                cout<<data[i]<<endl;

            }

        }

    }
    void clearList()
    {
        if(isEmpty())
        {
            cout<<"Empty Arraylist"<<endl;
        }
        else
        {

            for(int i=0; i<Size; i++)
            {
                Remove(i);
            }
            //cout<<"Arraylist Cleared!!!"<<endl;

        }


    }

};
int main()
{
    Arraylist<int> A1(5);
    A1.printArrayList();
    A1.Append(1);

    A1.Append(3);
    A1.Insert(4,3);
    A1.Insert(2,1);
    A1.Insert(4,3);
    A1.Append(5);
    A1.Append(6);
    A1.printArrayList();
    cout<<"Removing:"<<A1.Remove(2)<<endl;
    cout<<"Removing:"<<A1.Remove(3)<<endl;
    A1.printArrayList();
    A1.clearList();
cout<<"Removing:"<<A1.Remove(3)<<endl;




}
