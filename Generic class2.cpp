#include<iostream>
using namespace std;
template<class T1,class T2>
class Myclass
{
    T1 i;
    T2 j;
public:
    Myclass(T1 x,T2 y)
    {
        i=x;
        j=y;
    }
    void show()
    {
        cout<<"i:"<<i<<" ""j:"<<j<<endl;
    }


};
int main()
{
    Myclass<int,char>ob1(12,'N');
    Myclass<char,char *>ob2('L',"Iffat Bin Hossain");
    ob1.show();
    ob2.show();
}
