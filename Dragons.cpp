#include<bits/stdc++.h>
using namespace std;
int main(){
int s,n;
cin>>s>>n;
int x[n],y[n];
for(int i=0;i<n;i++)
{
    cin>>x[i]>>y[i];
}
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        if(x[i]>x[j]){
            swap(x[i],x[j]);
            swap(y[i],y[j]);
        }
    }
}
int flag=1;
for(int i=0;i<n;i++){
    if(s>x[i]){
        s+=y[i];
    }
    else{
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