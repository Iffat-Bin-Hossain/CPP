#include<bits/stdc++.h>
using namespace std;
int main(){
    string a,b,c;
    int A[26]={0},B[26]={0},C[26]={0};
    cin>>a>>b>>c;
    for(int i=0;i<a.size();i++){
A[a[i]-65]++;
    }
    for(int i=0;i<b.size();i++){
       B[b[i]-65]++; 
    }
    for(int i=0;i<c.size();i++){
        C[c[i]-65]++;
    }
    int flag=1;
    for(int i=0;i<26;i++){
        if(A[i]+B[i]!=C[i]){
            flag=0;
            break;
        }
    }
    if(flag==1){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

}