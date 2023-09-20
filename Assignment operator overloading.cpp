#include<iostream>
#include<cstring>
using namespace std;
class strtype{
char *p;
int len;
public:
strtype(const char *s)
{
    len=strlen(s)+1;
    p=(char *)malloc(len);
    strcpy(p,s);
}
~strtype()
{
    free(p);
    cout<<"freeing"<<endl;
}
strtype &operator=(strtype &ob)
{
    len=strlen(ob.p)+1;
    p=(char*)malloc(len);
    strcpy(p,ob.p);
    return *this;
}
char *get()
{
    return p;
}
};
int main()
{
    strtype s1("Iffat Bin Hossain"),s2("Nabab Hossain");
    cout<<s1.get()<<endl<<s2.get()<<endl;
    s1=s2;
    cout<<s1.get()<<endl<<s2.get()<<endl;
}
