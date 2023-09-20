#include<iostream>
using namespace std;
int main(){
long long int t,i;
int n,a,b;
cin>>t;
for(i=0;i<t;i++){

    cin>>n>>a>>b;
    int flag=0;
    if(n==1){

        if(a+b==2){
            flag=1;
        }
    }
    else{
        if((n-2)==(a+b)){
            flag=1;
        }
    }
    if(flag==1) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

}
