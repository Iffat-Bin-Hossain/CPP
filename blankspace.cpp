#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        int n;
        cin>>n;
        int A[n];
        for(int j=0; j<n; j++){
            cin>>A[j];
    }
    int Ans=0;
    for(int k=0; k<n; k++){
        int Max=0;
        if(A[k]==0){
            for(int l=k; l<n; l++)
            {
                if(A[l]==0){
                    Ans=max(Ans,++Max);
                }
                else{
                    break;
                }
            }
        }
    }
    cout<<Ans<<endl;
}
}