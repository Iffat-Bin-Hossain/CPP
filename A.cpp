#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int k=0; k<t; k++)
    {
        string S;
        int i;
        cin>>S;
        int l=S.size();
        vector<char> v;
        for(i=0; i<l; i++)
        {
            v.push_back(S[i]) ;
        }
        int j=l;
        for(i=l-1; i>=0; i--)
        {
            v.push_back(S[i]);
        }
        for(i=0; i<2*l; i++)
        {
            cout<<v.at(i);
        }
        cout<<endl;
    }

}
