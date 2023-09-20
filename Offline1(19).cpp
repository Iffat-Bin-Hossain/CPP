#include<iostream>
#include<cmath>
using namespace std;
class Point
{
// x and y coordinate
    int x, y;
public:
//Add necessary constructor(s) to initialize x and y
    Point(int a=0,int b=0)
    {
        x=a;
        y=b;
    }
//Add your set and get functions for x and y

    void Setxy(int a,int b)
    {
        x=a;
        y=b;
    }
    int Getx()
    {
        return x;
    }
    int Gety()
    {
        return y;
    }
    void print()
    {
        cout << "Coordinate: "<< x <<", " <<y <<endl;
    }
    //friend class Circle;
};
class Circle
{
    Point p;
    int radius;
public:
// Add necessary constructor(s) to initialize p and radius
    Circle(int a=0, int b=0, int c=0)
    {
        p.Setxy(a,b);
        radius=c;
    }
// Overload “upload” functions
    void update(int ia,int ib)//increment of a,b,c
    {
        p.Setxy(p.Getx()+ia,p.Gety()+ib);
    }
    void update(int ic)//increment of a,b,c
    {
        radius+=ic;
    }
    void update(int ia,int ib,int ic)//increment of a,b,c
    {
        p.Setxy(p.Getx()+ia,p.Gety()+ib);
        radius+=ic;
    }
    void print()
    {
        cout << "Center ";
        p.print();
        cout << "Radius: " << radius << endl;
    }
};
class Line
{
    Point p1,p2;
public:
    Line(int a1=0,int b1=0,int a2=0,int b2=0)
    {
        p1.Setxy(a1,b1);
        p2.Setxy(a2,b2);

    }
    void print()
    {
        double L=sqrt(pow((p1.Getx()-p2.Getx()),2)+pow((p1.Gety()-p2.Gety()),2));
        cout << "Length: " << L <<" unit"<< endl;
    }


};
int main()
{
    Point p(5,5);
    Circle c(2, 3, 5);
    cout << endl << "Point Display" <<endl;
    p.print();
    cout << endl << "Circle Display" <<endl;
    c.print();
    cout << endl;

//First update
    cout << "First Update" << endl;
// call “update” function of Circle class to increase the center’s x coordinate by 5 and y coordinate by 5;
    c.update(5,5);
    c.print();
    cout <<endl;
//Second update
    cout << "Second Update" << endl;
// call “update” function of Circle class to increase the radius by 6;
    c.update(6);
    c.print();
    cout << endl;
//Third update
    cout << "Third Update" << endl;
// call “update” function of Circle class to increase the center’s x coordinate by 2 and y coordinate by 2 and the radius by 2;
    c.update(2,2,2);
    c.print();
    cout << endl;
    cout<< "Line Display" <<endl;
    Line L(0,0,3,5);
    L.print();
    return 0;
}


