#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string A[n];
    for(int i=0; i<n; i++){
        cin>>A[i];
    }
    int B[n]={0};
    for(int i=0; i<n; i++){
       for(int j=i+1;j<n; j++){
        if(A[i]==A[j]){
            B[i]++;
        }
       }
    }
    int maxindex=0;
    int Max=B[0];
    for(int i=1; i<n; i++){
        if(B[i]>Max)
        {
            Max=B[i];
            maxindex=i;
        }
    }
    cout<<A[maxindex]<<endl;
}