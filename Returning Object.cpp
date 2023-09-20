#include <iostream>
#include<cstring>
using namespace std;
class samp{
char *s;
public:
 samp(){s='\0';}
 ~samp(){if(s) free(s);
 cout<<"Freeing"<<endl;}
 void show()
 {
     cout<<s<<endl;
 }
void set(char *str){
s=(char *)malloc(strlen(str)+1);
strcpy(s,str);
}

};

samp *input(){
char s[80];
samp *str= (samp *)malloc(sizeof(samp));
cout<<"Enter a string: ";
cin>>s;
str->set(s);
return str;


}
int main()
{
    samp *ob;
    ob=input();
    ob->show();

}
