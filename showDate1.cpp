#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
class Date{

int Day,Year;
char *Month;

public:
Date(char *S);
Date(int d,char *m,int y);
void showDate();
};


Date::Date(char *S)
{
    Month=(char *)malloc(10*sizeof(char));
    sscanf(S,"%d %s %d",&Day,Month,&Year);
}


Date::Date(int d,char *m,int y)
{
    Day=d;
    Year=y;
    Month=(char *)malloc((strlen(m)+1)*sizeof(char));
    strcpy(Month,m);

}


void Date::showDate()
{
    cout<<"Day:"<<Day<<" Month:"<<Month<<" Year:"<<Year<<endl;
}


int main()
{
Date sd("25 August 2022");
Date id(13,"July",2013);
sd.showDate();
id.showDate();
}

