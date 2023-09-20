#include<iostream>
using namespace std;
class One{
public:
    void add()
    {
        cout<<"Adding Two Integer"<<endl;
    }
};
class Two{
public:
    void add()
    {
        cout<<"Adding Two Floating Point"<<endl;
    }
};
int main()
{
    One o;
    Two t;
    o.add();
    t.add();
}
