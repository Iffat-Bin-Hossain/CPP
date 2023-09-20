#include<iostream>
using namespace std;
class point{
int x,y;
public:
    point(int a,int b)
    {
        x=a;
        y=b;
    }
    void print()
    {
        cout<<x<<"\t"<<y<<endl;
    }
};
int main()
{
   point x(3,4);
   x.print();
   point x(8,9);
   x.print();

}
