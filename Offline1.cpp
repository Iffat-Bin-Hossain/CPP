#include<iostream>
#include<cstring>
using namespace std;

class Student{
char *Name;
int Id,credit;
double cgpa;

public:

Student(char *S,int id,int CH,double CG)
{
    Name=(char *)malloc(100*sizeof(char));
    strcpy(Name,S);
    Id=id;
    credit=CH;
    cgpa=CG;

}

~Student()
{
free(Name);
}

void change(char *S)
{
 strcpy(Name,S);
}

void change(int n)
{
    Id=n;
}

void addTermResult(int c,double d)
{
   cgpa=((credit*cgpa)+(c*d))/(credit+c);
   credit+=c;
}

void showInfo()
{
    cout<<"Name:"<<Name<<",Id:"<<Id<<",Credit Completed:"<<credit<<",Cgpa:"<<cgpa<<endl;
}

};

class Batch{
Student *S;
int Count=0;
public:

Batch()
{
S=(Student *)malloc(1200*sizeof(Student));
}

~Batch()
{
free(S);
}

void addStudent(Student &s)
{
S[Count]=s;
Count++;
}

void showAllStudents()
{
for(int i=0;i<Count;i++)
    {
        S[i].showInfo();
    }
}


};
int main()
{
 // Part 1
 /*A student class holds the information of the
 student name, id, credit earned so far, and
 cumulative gpa (cgpa)*/
 /*The name of a student is stored using malloc,
 which will be freed during destruction*/
    Student s1("Tamim Iqbal", 1905131, 39, 3.56);
    Student s2("Liton Das", 1905150, 39, 3.52);
    s1.showInfo();

    cout<<"Changing the name of s1"<<endl;
 /*During changing the name, you should reallocate
 memory of the new name and free the previously
 allocated memory*/
    s1.change("Tamim Iqbal Khan");
    s1.showInfo();

    cout<<"Changing the id of s2"<<endl;
    s2.change(1905149);
    s2.showInfo();

    cout<<"Adding a term result of s1"<<endl;
    /*The first argument of addTermResult is the credit
    earned in a term and second one is the gpa obtained
    in that term*/
    s1.addTermResult(19, 3.85);
    s1.showInfo();

    // Part 2
   /*Batch contains a list of students*/
   /*During construction, a Batch object allocates dynamic
   memory for 1200 students using malloc. The memory will
   be freed during destruction*/

    Batch b;
    b.addStudent(s1);
    b.addStudent(s2);

    cout<<"Printing the list of students of the batch b"<<endl;
    b.showAllStudents();

return 0;

}
