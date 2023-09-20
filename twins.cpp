#include<iostream>
using namespace std;
int main(){
int n,A[105];
cin>>n;
for(int i=0;i<n;i++){

  cin>>A[i];
}
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
       if(A[i]>A[j]){

        int T=A[j];
        A[j]=A[i];
        A[i]=T;
       }

    }
}
int C=1;
while(1){
    int S1=0;
    int S2=0;
    for(int i=0;i<C;i++){
        S1+=A[i];
    }
    for(int i=C;i<n;i++){
        S2+=A[i];
    }
    if(S1>S2){
        break;
    }
    C++;
}
cout<<C;
}
