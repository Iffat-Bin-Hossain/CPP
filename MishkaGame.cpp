#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin >>n;
int m[n],c[n];
int mSum=0,cSum=0;
for(int i=0;i<n;i++){
    cin>>m[i]>>c[i];
    if(m[i]>c[i])
        mSum++;
    else if(m[i]<c[i])
        cSum++;
}
if(mSum>cSum){
    cout<<"Mishka";
}
else if(mSum<cSum){
    cout<<"Chris";
}
else{
    cout<<"Friendship is magic!^^";
}

}