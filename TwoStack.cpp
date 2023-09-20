#include <iostream>
using namespace std;
class TwoStack
{
    int *twoStack;
    int TOS1, TOS2;
    int size1, size2;

public:
    TwoStack(int size1, int size2)
    {
        twoStack = new int[size1 + size2];
        this->size1 = size1;
        this->size2 = size2;
        TOS1 = 0;
        TOS2 = size1 + size2 - 1;
    }
    void Push1(int d)
    {
        if (TOS1 == size1)
        {
            int n = size1 + size2 - TOS2-1;//size of stack2
            int j = size1 + size2 - 1;
            size1 *= 2;
            int *temp_twoStack = twoStack;
            twoStack = new int[size1 + size2];
            for(int i=0;i<size1+size2;i++){
                twoStack[i]=0;
            }
            for (int i = 0; i < TOS1; i++)
            {
                twoStack[i] = temp_twoStack[i];
            }
            int k = size1 + size2 - 1;
            for (int i = 0; i < n; i++)
            {
                twoStack[k--] = temp_twoStack[j--];
            }
            delete temp_twoStack;
            TOS2 = size1 + size2 - n - 1;
        }
        twoStack[TOS1++] = d;
    }
    void Push2(int d)
    {
        if (TOS2 == size1 - 1)
        {
            int n = size2;
            int j = size1 + size2 - 1;
            size2 *= 2;
            int *temp_twoStack = twoStack;
            twoStack = new int[size1 + size2];
            for(int i=0;i<size1+size2;i++){
                twoStack[i]=0;
            }
            for (int i = 0; i < TOS1; i++)
            {
                twoStack[i] = temp_twoStack[i];
            }

            int k = size1 + size2 - 1;
            for (int i = 0; i < n; i++)
            {
                twoStack[k--] = temp_twoStack[j--];
            }
            delete temp_twoStack;
            TOS2 = size1 + size2 - n - 1;
        }
        twoStack[TOS2--] = d;
    }
    void printStack1()
    {
        for (int i = TOS1 - 1; i >= 0; i--)
        {
            cout << twoStack[i] << " ";
        }
        cout << endl;
    }
    void printStack2()
    {
        for (int i = TOS2 + 1; i < size1 + size2; i++)
        {
            cout << twoStack[i] << " ";
        }
        cout << endl;
    }
    void printTwoStack(){
        for (int i = 0; i < size1 + size2; i++)
        {
            cout << twoStack[i] << " ";
        }
        cout << endl;
    }
    int pop1()
    {
        if (TOS1 == 0)
        {
            cout << "Nothing in stack1" << endl;
            return NULL;
        }
        return twoStack[--TOS1];
    }
    int pop2()
    {
        if (TOS2 == size1 + size2 - 1)
        {
            cout << "Nothing in stack2" << endl;
            return NULL;
        }
        return twoStack[++TOS2];
    }
};
int main()
{
    TwoStack t(2, 2);
    t.Push1(5);
    t.Push1(4);
    t.Push1(3);
    t.Push1(2);
    t.Push1(1);
    t.Push2(11);
    t.Push2(10);
    t.Push2(9);
    t.Push2(8);
    t.Push2(7);
    t.Push2(6);
    t.printStack1();
    t.printStack2();
    t.printTwoStack();
    for (int i = 0; i < 5; i++)
    {
        cout << t.pop1() << " " << t.pop2() << endl;
        t.printStack1();
        t.printStack2();
    }
}