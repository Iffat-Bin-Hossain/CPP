#include<iostream>
using namespace std;
namespace FirstNS{
class Demo{
int i;
public:
    Demo(int x)
    {
        i=x;
    }
    void Set(int x)
    {
        i=x;
    }
    int Get()
    {
        return i;
    }

};
char str[]="Illustrsating Namespaces";
int Count;

}

namespace SecondNS{
int x,y;
}
int main()
{
    FirstNS::Demo ob(10);
    cout<<"Value of ob is: "<<ob.Get()<<endl;
    ob.Set(99);
    cout<<"Value of ob is now: "<<ob.Get()<<endl;
    cout<<FirstNS::str<<endl;
using namespace FirstNS;

    for(Count=10;Count>0;Count--)
    {
        cout<<Count<<" ";
    }
    cout<<endl;
    using namespace SecondNS;
    x=10;
    y=20;
    cout<<"(x,y)=("<<x<<","<<y<<")"<<endl;
    Demo xob(x),yob(y);
    cout<<"(xob,yob)=("<<xob.Get()<<","<<yob.Get()<<")"<<endl;
}
