#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
class Vector
{
    char *name;
    int x,y,z;
public:
    Vector(const char *n)
    {
        //cout<<"Single Parameterized Constructor"<<endl;
        int l = strlen(n);
        name = new char[l+1];
        strcpy(name,n);
        x=0;
        y=0;
        z=0;
    }
    Vector(const char *n, int a, int b, int c)
    {
        //cout<<"Multiple Parameterized Constructor"<<endl;
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
        //cout<<"Freeing"<<endl;
        delete []name;
    }
    void print()
    {
        if(y>0 && z>0)
        {
            cout<<name<<":"<<x<<"x+"<<y<<"y+"<<z<<"z"<<endl;
        }
        else if(y>0 && z<0)
        {
            cout<<name<<":"<<x<<"x+"<<y<<"y"<<z<<"z"<<endl;
        }
        else if(y<0 && z<0)
        {
            cout<<name<<":"<<x<<"x"<<y<<"y"<<z<<"z"<<endl;
        }
        else
        {
            cout<<name<<":"<<x<<"x"<<y<<"y+"<<z<<"z"<<endl;
        }
    }
    Vector operator^(Vector &v)
    {
        Vector T("Result1");
        T.setX(y*v.z-z*v.y);
        T.setY(z*v.x-x*v.z);
        T.setZ(x*v.y-y*v.x);
        return T;
    }
    Vector operator=(Vector v)
    {
        name=new char[strlen(v.name)+1];
        strcpy(name,v.name);
        x=v.x;
        y=v.y;
        z=v.z;
        return *this;

    }
   bool operator==(Vector v)
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
    friend Vector operator*(int n,Vector &v);
    Vector operator*(Vector &v)
    {
        Vector T("Result1");
        T.x=x*v.x;
        T.y=y*v.y;
        T.z=z*v.z;
        return T;
    }

};

Vector operator*(int n,Vector &v)
{
    Vector T(v.getName());
    T.setX(v.getX()*n);
    T.setY(v.getY()*n);
    T.setZ(v.getZ()*n);
    return T;
}
int main()
{
    Vector v1("v1", 1,2,3), v2("v2", 4, 5, -6),v3("Result1"),v4("Result2",-27,18,-3);
    v1.print();///Print the components of vector v1
    v2.print();///Print the components of vector v2
    v3=v1^v2;///Calculate the cross product of vector v1 and vector v2 (Consider ^ as cross product for this assignment)
    v3.print();///Print the modified components of vector v3(Name: Result1)
    if(v3==v4)///Check for equality; if two vectors contain equal component values (x, y, z), then they are equal.
        cout<<"Vectors are equal"<<endl;
    else
        cout<<"Vectors are not equal"<<endl;
    v1= v1*2;///Multiply each component of vector v1 with the given value
    v1.print();///Print the modified components of vector v1
    v2=2*v2;///Multiply each component of vector v2 with the given value
    v2.print();///Print the modified components of vector v2
    v3=v1*v2;///Multiply each component of vector v1 with the corresponding component of vector v2.
    v3.print();///Print the modified components of vector v3(Name: Result1)
    if(v3==v4)///Check for equality; if two vectors contain equal component values (x, y, z), then they are equal.
        cout<<"Vectors are equal"<<endl;
    else
        cout<<"Vectors are not equal"<<endl;
    return 0;
}
