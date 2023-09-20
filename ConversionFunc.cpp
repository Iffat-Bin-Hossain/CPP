#include<iostream>
using namespace std;
class Coord
{
    int x,y;
public:
    Coord(int i,int j)
    {
        x=i;
        y=j;
    }
    operator int()
    {
        return x*y;
    }

};
int main()
{
    Coord C1(2,3),C2(5,6);
    int i;
    i=100+C1;
    cout<<i<<endl;
    i=C2;
    cout<<i<<endl;
    i=C1+20;
    cout<<i<<endl;
}
