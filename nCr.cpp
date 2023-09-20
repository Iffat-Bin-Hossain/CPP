#include<iostream>
using namespace std;
int nCr(int n,int r){
    if(n==r){
        return 1;
    }
    if(r==1){
        return n;
    }
    return nCr(n-1,r)+nCr(n-1,r-1); 
}
int main(){
    int n,r;
    cin>>n>>r;
    cout<<nCr(n,r);
}