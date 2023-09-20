#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int A[n];
    vector<int> Odd,Even;
    for(int i=0;i<n;i++){
        cin>>A[i];
        if(A[i]%2==0){
            Even.push_back(A[i]);
        }
        else{
            Odd.push_back(A[i]);
        }
    }
    int e=Even.size();
    int o=Odd.size();
    int x;
    if(e==1){
        x=Even[0];    
    }
    else{
        x=Odd[0];
    }
    int ans;
    for(int i=0;i<n;i++){
        if(A[i]==x){
            ans=i;
            break;
        }
    }
    cout<<ans+1<<endl;
}