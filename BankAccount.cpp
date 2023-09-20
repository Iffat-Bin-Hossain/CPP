#include<iostream>
using namespace std;
int main(){
long long int n;
long long int result;
cin>>n;
if(n>0){
    result=n;
}
else{
long long int p=n/10;
int r=n%10;
long long int t=n/100;
long long int q=(t*10)+r;
if(p>q){
    result=p;
}
else{
    result=q;
}
}
cout<<result;
}