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
