#include<iostream>
#include<cstdio>
using namespace std;
class Date{
int Day,Year,Month;
public:
Date(char *S);
Date(int d,int m,int y);
void showDate();
};
Date::Date(char *S)
{
    sscanf(S,"%d%*c%d%*c%d",&Day,&Month,&Year);
}
Date::Date(int d,int m,int y)
{
    Day=d;
    Month=m;
    Year=y;
}
 void Date::showDate()
{
    cout<<Day<<"-"<<Month<<"-"<<Year<<endl;
}
int main()
{
Date sd("25/8/2022");
Date id(13,6,2013);
sd.showDate();
id.showDate();
}
