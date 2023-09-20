#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n;
    cin>>n;
    long long count=0;
    for(long long i=0; i<n; i++){
        string str;
        cin>>str;
        if(str[0]=='I'){
            count+=20;
        }
        else if(str[0]=='C'){
            count+=6;
        }
        else if(str[0]=='D'){
            count+=12;
        }
        else if(str[0]=='T'){
            count+=4;
        }
        else if(str[0]=='O'){
            count+=8;
        }
    }
    cout<<count<<endl;
}