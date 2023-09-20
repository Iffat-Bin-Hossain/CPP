#include<bits/stdc++.h>
using namespace std;
int main(){
    int A[3];
    cin>>A[0]>>A[1]>>A[2];
    for(int i=0; i<3; i++){
        for(int j=i+1; j<3; j++){
            if(A[j]<A[i])
            {
                swap(A[j],A[i]);
            }
        }
    }
    cout<<A[2]-A[0]<<endl;
    
}