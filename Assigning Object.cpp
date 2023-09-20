#include<iostream>
using namespace std;
#define SIZE 5
class Stack
{
    char stck[SIZE];
    int tos;
public:
    Stack();
    void push(char c);
    char pop();
};
Stack::Stack()
{
    cout<<"In Constructor"<<endl;
    tos=0;
}
void Stack::push(char c)
{
    cout<<"In Push"<<endl;
    if(tos==SIZE)
    {
        cout<<"Stack is full"<<endl;
        return;
    }
    stck[tos]=c;
    tos++;
}
char Stack::pop()
{
    cout<<"In Pop"<<endl;
    if(tos==0)
    {

        cout<<"Stack is empty"<<endl;
        return 0;
    }
    //char ch=stck[tos];
    tos--;
    return stck[tos];

}
int main()
{
    Stack s1,s2;
    s1.push('x');
    s1.push('y');
    s1.push('w');
    s1.push('z');
    s2=s1;
    cout<<"Unstacking S1"<<endl;
    for(int i=0; i<5; i++)
    {
        cout<<s1.pop()<<endl;
    }
    cout<<"Unstacking S2"<<endl;
    for(int i=0; i<5; i++)
    {
        cout<<s2.pop()<<endl;
    }
}
