#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0; i<n; i++){
            cin>>A[i];
        }
        vector<int> B;
        for(int i=0; i<n; i++){
            for(int j=i+1;j<n; j++){
                B.push_back(abs(A[i] - A[j]));
            }
        }
        int Min=B[0];
        for(int i=1; i<B.size(); i++){
            Min=min(Min,B[i]);
        }
        cout<<Min<<endl;
    }
}