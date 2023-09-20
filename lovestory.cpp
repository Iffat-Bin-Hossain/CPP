#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        string str="codeforces";
        int c=0;
        for(int j=0; j<10; j++){
            if(str[j]!=s[j]){
                c++;
            }
    }
    cout<<c<<endl;
    }
}