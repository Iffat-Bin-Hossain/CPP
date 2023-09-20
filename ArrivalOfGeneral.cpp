#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
int A[n];
for(int i=0;i<n;i++){
    cin>>A[i];
}
int Min=A[0];
int minindex=0;
int maxindex=0;
int Max=A[0];
for(int i=1;i<n;i++){
    if(A[i]<=Min){
        Min=A[i];
        minindex=i;
    }
    if(A[i]>Max){
        Max=A[i];
        maxindex=i;
    }
}
int ans;
if(maxindex<minindex){
    ans=maxindex+n-1-minindex;
}
else{
    ans=maxindex+n-2-minindex;
}
cout<<ans<<endl;

}