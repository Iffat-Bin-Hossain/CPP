#include<iostream>
using namespace std;
template<class X>X Add(X a,X b)
{
    return a*b;
}
int main()
{
    int i=10,j=20;
    float p=6.5,q=8.3;
    bool b1=true,b2=false;
    string s1="Iffat Bin Hossain",s2=" Nabil";
    cout<<Add(i,j)<<endl;
    cout<<Add(p,q)<<endl;
    //cout<<Add(s1,s2)<<endl;
    cout<<Add(b1,b2)<<endl;
return 0;
}
