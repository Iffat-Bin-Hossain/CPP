#include<iostream>
#include<cstring>
using namespace std;
class strtype{
char *str;
int len;
public:
    strtype(char *s)
    {

        len=strlen(s);
        str=new char[len+1];
        strcpy(str,s);

    }
    operator char*()
    {
        return str;
    }

};
int main()
{
    strtype s("Iffat Bin Hossain");
    char *p,s2[80];
    p=s;
    cout<<"Here is the string:"<<p<<endl;
    strcpy(s2,s);
    cout<<s2<<endl;
    strcpy(s2,p);
    cout<<s2<<endl;
}
