#include<iostream>
#include<cstring>
using namespace std;
class Profile
{
    char* Name;
    int Age;
    double CGPA;
public:
    Profile()
    {
        cout<<"Default Constructor"<<endl;
        Name=new char[8];
        strcpy(Name,"Nabil");
        Age=25;
        CGPA=3.50;
    }
    Profile(const char *Name,int Age,double CGPA)
    {
        cout<<"Parameterized Constructor"<<endl;
        this->Name=new char[strlen(Name)+1];
        strcpy(this->Name,Name);
        this->Age=Age;
        this->CGPA=CGPA;
    }
    ~Profile()
    {
        cout<<"Freeing "<<Name<<endl;
        delete[] Name;

    }

    Profile &operator+(Profile &P)
    {

        strcat(Name," ");
        strcat(Name,P.Name);
        Age+=P.Age;
        CGPA+=P.CGPA;
        return *this;
    }
    Profile operator=(Profile &b)
    {
        strcpy(Name,b.Name);
        Age=b.Age;
        CGPA=b.CGPA;

        return *this;
    }




    Print()
    {
        cout<<"Name:"<<Name<<endl;
        cout<<"Age:"<<Age<<endl;
        cout<<"CGPA:"<<CGPA<<endl;
    }


};
int main()

{
    Profile p1;
    p1.Print();
    Profile p2("Iffat Bin Hossain",26,3.88);
    p2.Print();

    Profile p3=p2+p1;
    p3.Print();
    Profile p4=p1;
    p4.Print();


}
