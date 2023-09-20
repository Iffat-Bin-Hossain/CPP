#include<iostream>
#include<cstring>
#include<conio.h>
using namespace std;
int main()
{
    char S1[100]="Iffat Bin Hossain";
    char S2[100],S3[100]=" Nabil",S4[100];
    int L=strlen(S1);
    cout<<L<<endl;
    strcpy(S2,S1);
    cout<<S2<<endl;
    strcat(S1,S3);
    cout<<S1<<endl;
    strupr(S1);
    cout<<S1<<endl;
    strlwr(S1);
    cout<<S1<<endl;
    int R=strcmp(S1,S2);
    if(R==0)
    {
        cout<<"Strings are equal";
    }
    else
        {
        cout<<"Strings are  not equal";
        }
        getch();
}
