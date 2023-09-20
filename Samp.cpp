#include<iostream>

#include<cstring>
using namespace std;
class Samp
{
    char *s;
public:
    Samp()
    {
        cout<<"Constructing...."<<endl;
        s='\0';
    }
    ~Samp()
    {
        if(s)
        {
            free(s);
            cout<<"Freeing...."<<endl;
        }
    }
    void Set(char * str)
    {
        int len=strlen(str);
        s=(char *)malloc(len+1);
        strcpy(s,str);

    }
    void show(){

    cout<<s<<endl;
}
};
Samp input(){
char S[80];
Samp smp;
cout<<"Enter a string:  ";
cin>>S;
smp.Set(S);
return smp;
}

int main()
{
 Samp ob;
 ob=input();
 ob.show();
}
