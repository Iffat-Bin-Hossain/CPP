#include<iostream>
using namespace std;
#define SIZE 10
template<class T>class Stack
{
    T StckArray[SIZE];
    int TOS;
public:
    void init()
    {
        TOS=0;
    }
    void stackPrint()
    {
        for(int i=0; i<TOS; i++)
        {
            cout<<StckArray[i];
        }
        cout<<endl;
    }
    void push(T ob);
    T pop();
};
template<class T>
void Stack<T>::push(T ob)
{
    if(TOS==SIZE)
    {
        cout<<"This Stack is Full"<<endl;
        return;
    }
    StckArray[TOS]=ob;
    TOS++;
}
template<class T>
T Stack<T>::pop()
{
    if(TOS==0)
    {
        cout<<"This Stack is Empty"<<endl;
        return 0;
    }
    TOS--;
    return StckArray[TOS];
}
int main()
{
    Stack<char> s1,s2;
    int i;
    s1.init();
    s2.init();
    s1.push('a');
    s1.push('f');
    s1.push('z');
    s1.push('a');
    s1.push('l');
    s2.push('n');
    s2.push('a');
    s2.push('b');
    s2.push('i');
    s2.push('l');

    s1.stackPrint();
    s2.stackPrint();

    for(i=0;i<2;i++)
    {
        cout<<s1.pop()<<endl;
    }
    for(i=0;i<2;i++)
    {
        cout<<s2.pop()<<endl;
    }
    s1.stackPrint();
    s2.stackPrint();
    Stack<int>s3;
    s3.init();
    s3.push(1);
    s3.push(5);
    s3.push(7);
    s3.push(4);
    s3.push(80);
    s3.stackPrint();
    for(i=0;i<2;i++)
    {
        cout<<s3.pop()<<endl;
    }
    s3.stackPrint();
    return 0;
}
