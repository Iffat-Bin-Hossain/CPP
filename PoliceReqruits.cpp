#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n;
    cin>>n;
    long long int A[n];
    for(long long int i=0; i<n; i++){
        cin>>A[i];
    }
    long long int freeCount=0;
    long long int untreatCount=0;
    for(long long int i=0; i<n; i++){
        if(A[i]>0){
            freeCount+=A[i];
        }
        else{
            if(freeCount>0){
                freeCount--;
            }
            else{
                untreatCount++;
            }
        }
    }
    cout<<untreatCount<<endl;

}