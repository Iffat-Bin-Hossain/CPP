#include <iostream>
using namespace std;
int main(){
string S;
cin>>S;
int i,temp;
bool H,E,L1,L2,O;
H=E=L1=L2=O=false;
for(i=0;i<S.size();i++){
 if(S[i]=='h'){
    temp=i;
    H=true;
    break;
 }
}
 for(i=temp+1;i<S.size();i++){
 if(S[i]=='e'){
    temp=i;
    E=true;
    break;
 } }
 for(i=temp+1;i<S.size();i++){
 if(S[i]=='l'){
    temp=i;
    L1=true;
    break;
 }}
 for(i=temp+1;i<S.size();i++){
 if(S[i]=='l'){
    temp=i;
    L2=true;
    break;
 } }
 for(i=temp+1;i<S.size();i++){
 if(S[i]=='o'){
    temp=i;
    O=true;
    break;
 } }
if(H && E && L1 && L2 && O){
    cout<<"YES";}
else{
    cout<<"NO";
}
}
