#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int t,i,j;
    cin>>t;
    string s;
    for(i=0; i<t; i++)
    {
        cin>>s;
        int l=s.size();
        for( j=2; j<l; j+=2)
        {
            s[j]=-1;
        }
        string str="";
        for(j=0; j<l; j++)
        {
            if(s[j]!=-1)
            {
                str+=s[j];//(string)s[j]
            }
        }
        cout<<str<<endl;
    }
}
