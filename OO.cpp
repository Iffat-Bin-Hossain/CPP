#include<iostream>
using namespace std;
class Coord
{
    int x,y;
public:
    Coord(int i=0,int j=0)
    {
        cout<<"Constructing Coord"<<endl;
        x=i;
        y=j;
    }
    void print()
    {
        cout<<"Coord("<<x<<","<<y<<")"<<endl;
    }
Coord operator+(Coord &ob)
{
    Coord T;
    T.x=x+ob.x;
    T.y=y+ob.y;
    return T;
}
Coord operator-(Coord &ob)
{
    Coord T;
    T.x=ob.x-x;
    T.y=ob.y-y;
    return T;
}

};
int main()
{
    Coord c1(3,4),c2(2,5),c3,c4;
    c1.print();
    c2.print();
    c3=c1+c2;
    c4=c1-c2;
    c3.print();
    c4.print();

}
