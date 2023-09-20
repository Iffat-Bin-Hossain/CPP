#include<iostream>
using namespace std;
int main()

{
 int t;
 cin>>t;
 while(t--){
    int n;
    cin>>n;
    int A[n];
    for(int i=0; i<n; i++){
        cin>>A[i];
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(A[i]>A[j]){
                swap(A[i],A[j]);
            }
        }
    }
    int count=1;
    for(int i=1; i<n; i++){
        if(A[i]!=A[i-1]){
            count++;
        }
    }
    cout<<count<<endl;

 }
}
