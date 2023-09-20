#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
class Samp
{
    int x,y;
    char *p;
public:
    Samp()
    {
        cout<<"Default Constructor"<<endl;
        x=0;
        y=0;
        p=new char[7];
        strcpy(p,"Origin");
    }
    Samp(int x,int y,const char *p)
    {
        cout<<"Parameterized Constructor"<<endl;
        this->x=x;
        this->y=y;
        this->p=new char[strlen(p)+1];
        strcpy(this->p,p);
    }
    Samp(const Samp& S)
    {
        cout<<"Copy Constructor"<<endl;
        x=2*S.x;
        y=2*S.y;
        p=new char[7];
        strcpy(p,"Focus");
    }
    ~Samp()
    {
        cout<<"Destructing "<<p<<"("<<x<<","<<y<<")"<<endl;
        delete[] p;

    }
    void print()
    {
        cout<<"Printing"<<endl;
        cout<<p<<"("<<x<<","<<y<<")"<<endl;
    }

friend Samp Image(Samp real);


};
Samp Image(Samp real)//Image of a point with resoect to x=y line
    {
        Samp img(real.y,real.x,"Image");

        return img;

    }

int main()
{
    Samp S1;
    S1.print();
    Samp S2(3,4,"Centre");
    S2.print();
    Samp S3(S2);
    S3.print();

    Samp S4=Image(S2);
    S4.print();
    Samp S5=Image(S3);
    S5.print();
}
