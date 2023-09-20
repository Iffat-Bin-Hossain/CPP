#include<bits/stdc++.h>
using namespace std;
int main(){
long long int A[4];
for(int i=0;i<4;i++){
    cin>>A[i];
}
int count=1;
for(int i=0;i<4;i++){
    for(int j=i+1;j<4;j++){
        if(A[i]>A[j]){
            swap(A[i],A[j]);
        }
    }
}
for(int i=1;i<4;i++){
    if(A[i]!=A[i-1]){
        count++;
    }
}
cout<<4-count<<endl;




}