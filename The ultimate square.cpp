
#include<iostream>
using namespace std;
int main(){
int t,i;
long long int n[10002];
cin>>t;
for(i=0;i<t;i++){
 cin>>n[i];
}
for(i=0;i<t;i++){
if(n[i]%2==0)
    cout<<n[i]/2<<endl;
else{
    cout<<(n[i]+1)/2<<endl;
}

}
cout<<min(1,2,543,65);
}
