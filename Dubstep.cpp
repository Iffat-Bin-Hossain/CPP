#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int main()
{
    string s1;
    vector<char>s2;
    int i,j;
    cin>>s1;
    int l=s1.size();
    for( i=0; i<l; i++)
    {
        if(s1[i]=='W' && s1[i+1]=='U' && s1[i+2]=='B')
        {
            s1[i]='x';
            s1[i+1]='x';
            s1[i+2]='x';
        }
    }
    j=0;
    for(i=0; i<l; i++)
    {
        if(s1[i]!='x' && s1[i+1]=='x')
        {
         s2.push_back(s1[i]);
         s2.push_back(' ');
         j+=2;
        }
        else if(s1[i]!='x'){
          s2.push_back(s1[i]);
          j++;
        }
    }
for(i=0;i<j;i++){
    cout<<s2.at(i);
}

}
