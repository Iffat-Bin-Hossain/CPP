#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        int l=str[0]+str[1]+str[2]-144;
        int r=str[3]+str[4]+str[5]-144;
        if(l==r){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}