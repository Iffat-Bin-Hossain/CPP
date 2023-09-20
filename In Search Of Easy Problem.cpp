#include<iostream>
using namespace std;
int main()
{
    int n,i,A[105];
    int flag=0;
    cin>>n;
    for(i=0;i<n;i++){

      cin>> A[i];
    }
    for(i=0;i<n;i++){
        if(A[i]==1){
            flag=1;
            break;
        }
    }
    if(flag==1){
        cout<<"HARD";
    }
    else{
        cout<<"EASY";
    }



}

