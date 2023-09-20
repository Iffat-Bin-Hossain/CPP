#include<iostream>
using namespace std;
int main(){
int a,b,c,A[7];
cin>>a>>b>>c;
A[0]=a+b+c;
A[1]=a+b*c;
A[2]=a*b+c;
A[3]=a*b*c;
A[4]=(a+b)*c;
A[5]=a*(b+c);
int Max=A[0];
for(int i=0;i<6;i++){
    if(A[i]>Max){
        Max=A[i];
    }
}
cout<<Max;
}
