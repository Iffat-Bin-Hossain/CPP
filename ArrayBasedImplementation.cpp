#include<iostream>
#include<typeinfo>
using namespace std;
template<class T>
class MyList
{
public:
    int capacity,Size,currPos;
    T *data;

    MyList()
    {
        capacity=4;
        Size=0;
        currPos=0;
        data=new T[capacity];
    }
    MyList(const MyList<T> &l)
    {
        this->capacity=l.capacity;
        this->Size=l.Size;
        this->data=new T[this->capacity];
        for(int i=0; i<this->Size; i++)
        {
            this->data[i]=l.data[i];
        }
    }
    int ListSize()//Time Complexity O(1)
    {
        return Size;
    }
    void push(T d)//Time Complexity O(n)
    {
        T *temp_data;

        if(Size==capacity)
        {
            capacity*=2;
            temp_data=new T[capacity];
            for(int i=0; i<Size; i++)
                temp_data[i]=data[i];
            delete data;
            data=new T[capacity];
            for(int i=0; i<Size; i++)
            {
                data[i]=temp_data[i];
            }
            delete temp_data;
        }
        for(int i=Size; i>currPos; i--)
        {
            data[i]=data[i-1];
        }
        data[currPos]=d;
        Size++;


    }
    void pushBack(T d)//Time Complexity O(1)
    {
        T*temp_data;
        int i;
        if(Size==capacity)
        {
            capacity*=2;
            temp_data=new T[capacity];
            for(int i=0; i<Size; i++)
                temp_data[i]=data[i];
            delete data;
            data=new T[capacity];
            for(i=0; i<Size; i++)
            {
                data[i]=temp_data[i];
            }
            delete temp_data;
        }
        data[Size++]=d;

    }
    T Erase()//Time Complexity O(n)
    {
        T *temp_data;
        if(Size==0)
        {
            cout<<"Empty Arraylist"<<endl;
            if(typeid(T)==typeid(string))
            {
                return (T)"";
            }
            return NULL;
        }
        else
        {
            T x=data[currPos];
            for(int i=currPos; i<Size; i++)
            {
                data[i]=data[i+1];
            }
            if(currPos==Size-1 && currPos>0)
            {
                currPos--;
            }

            Size--;
            if(Size<=capacity/2)
            {
                capacity/=2;
                temp_data=new T[Size];
                for(int i=0; i<Size; i++)
                {
                    temp_data[i]=data[i];

                }
                delete data;

            data=new T[capacity];
            for(int i=0; i<Size; i++)
                data[i]=temp_data[i];
            delete temp_data;
            }
            return x;
        }


    }
    void setToBegin()//Time Complexity O(1)
    {
        currPos=0;
    }
    void setToEnd()//Time Complexity O(1)
    {
        currPos=Size-1;
    }
    void prev()//Time Complexity O(1)
    {
        if(currPos==0)
        {
            return;
        }
        currPos--;
    }
    void next()//Time Complexity O(1)
    {
        if(currPos==Size-1)
        {
            return;
        }
        currPos++;

    }
    int CurrPos()//Time Complexity O(1)
    {
        return currPos;
    }
    void setToPos(int pos)//Time Complexity O(1)
    {
        if(pos<0 || pos>=Size)
        {
            return;
        }
        currPos=pos;

    }
    T getValue()//Time Complexity O(1)
    {
        if(Size==0)
        {
            cout<<"Empty Arraylist"<<endl;
            if(typeid(T)==typeid(string))
            {
                return (T)"";
            }
            return NULL;

        }
        return data[currPos];
    }
    int Find(T d)//Time Complexity O(n)
    {

        for(int i=0; i<Size; i++)
        {
            if(d==data[i])
            {
                return i;
            }

        }
        return -1;
    }
    void Clear()//Time Complexity O(n)
    {
        for(int i=Size-1; i>=0; i--)
        {
            setToPos(i);
            Erase();
        }
    }
    ~MyList()
    {
        delete[] data;
    }

};

