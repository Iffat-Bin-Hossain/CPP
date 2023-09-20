#include<iostream>
#include<cstring>
using namespace std;

class Vector
{
    char *name;
    int x,y,z;
public:
    Vector(char *n)
    {
        int l = strlen(n);
        name = new char[l+1];
        strcpy(name,n);
        x=0;
        y=0;
        z=0;
    }
    Vector(char *n, int a, int b, int c)
    {
        int l = strlen(n);
        name = new char[l+1];
        strcpy(name,n);
        x=a;
        y=b;
        z=c;
    }
    Vector(const Vector &v)
    {
        int l = strlen(v.name);
        name = new char[l+1];
        strcpy(name,v.name);
        x=v.x;
        y=v.y;
        z=v.z;
    }

    int setX(int a)
    {
        x=a;
    }

    int setY(int b)
    {
        y=b;
    }
    int setZ(int c)
    {
        z=c;
    }

    void setName(char *n)
    {
        int l = strlen(n);
        name = new char[l+1];
        strcpy(name,n);
    }

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }

    int getZ()
    {
        return z;
    }

    char *getName()
    {
        return name;
    }

    ~Vector()
    {
        delete []name;
    }
    Vector operator^(Vector &v)
    {
        Vector Temporary(" ");
        Temporary.x=y*v.z-z*v.y;        ///| i       j       k |
        Temporary.y=z*v.x-x*v.z;        ///| x       y       z |=(y*v.z-z*v.y)i + (z*v.x-x*v.z)j + (x*v.y-y*v.x)k
        Temporary.z=x*v.y-y*v.x;        ///|v.x     v.y     v.z|
        return Temporary;
    }
    Vector operator=(Vector v)
    {
        ///As the name of left side object of = operator is defined while creation, So it is unnecessary to assigning it further.
        x=v.x;
        y=v.y;
        z=v.z;
        return *this;

    }
    bool operator==(Vector &v)
    {
        return x==v.x && y==v.y && z==v.z;
    }
    Vector operator*(int n)
    {
        x*=n;
        y*=n;
        z*=n;
        return *this;
    }
    Vector operator*(Vector &v)
    {
        Vector Temporary(" ");
        Temporary.x=x*v.x;
        Temporary.y=y*v.y;
        Temporary.z=z*v.z;
        return Temporary;
    }
    friend Vector operator*(int n,Vector &v);
    friend ostream &operator<<(ostream &output,Vector &V );
};

Vector operator*(int n,Vector &v)
{
    Vector Temporary(v.getName());
    Temporary.setX(v.getX()*n);
    Temporary.setY(v.getY()*n);
    Temporary.setZ(v.getZ()*n);
    return Temporary;
}

ostream &operator<<(ostream &output,Vector &V )
{
    if(V.y>=0 && V.z>=0)
    {
        output<<V.name<<":"<<V.x<<"x+"<<V.y<<"y+"<<V.z<<"z"<<endl;
    }
    else if(V.y>=0 && V.z<0)
    {
        output<<V.name<<":"<<V.x<<"x+"<<V.y<<"y"<<V.z<<"z"<<endl;
    }
    else if(V.y<0 && V.z<0)
    {
        output<<V.name<<":"<<V.x<<"x"<<V.y<<"y"<<V.z<<"z"<<endl;
    }
    else
    {
        output<<V.name<<":"<<V.x<<"x"<<V.y<<"y+"<<V.z<<"z"<<endl;
    }
    return output;
}

int main()
{
    Vector v1("v1", 1,2,3), v2("v2", 4, 5, -6), v3("Result1"),v4("Result2",-27,18,-3);

    cout << v1;     ///Print the components of vector v1
    cout << v2;     ///Print the components of vector v2


    v3=v1^v2;       ///Calculate the cross product of vector v1 and vector v2 (Consider ^ as cross product for this assignment)
    cout << v3;     ///Print the modified components of vector v3 (Name: Result1)

    if(v3==v4)      ///Check for equality; if two vectors contain equal component values (x, y, z), then they are equal
        cout<<"Vectors are equal"<<endl;
    else
        cout<<"Vectors are not equal"<<endl;

    v1= v1*2;       ///Multiply each component of vector v1 with the given value
    cout << v1;     ///Print the modified components of vector v1

    v2=2*v2;        ///Multiply each component of vector v2 with the given value
    cout << v2;     ///Print the modified components of vector v2

    v3=v1*v2;       ///Multiply each component of vector v1 with the corresponding component of vector v2
    cout << v3;     ///Print the modified components of vector v3 (Name: Result1)

    if(v3==v4)      ///Check for equality; if two vectors contain equal component values (x, y, z), then they are equal
        cout<<"Vectors are equal"<<endl;
    else
        cout<<"Vectors are not equal"<<endl;

    return 0;
}

/* Output:
v1: 1x+2y+3z
v2: 4x+5y-6z
Result1: -27x+18y-3z
Vectors are equal
v1: 2x+4y+6z
v2: 8x+10y-12z
Result1: 16x+40y-72z
Vectors are not equal
*/
