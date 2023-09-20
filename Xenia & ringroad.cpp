#include<iostream>
#include<vector>
using namespace std;
int main(){
long long int n,m,x,i,Sum=0;
vector<long long int> A;
cin>>n >>m;
for(i=0;i<m;i++){
 cin>>x;
 A.push_back(x);
}
Sum+=A.at(0)-1;
for(i=1;i<m;i++)
{
   if(A.at(i)<A.at(i-1)) {
    Sum+=(n-A.at(i-1))+A.at(i);
   }
   else{
    Sum+=A.at(i)-A.at(i-1);
   }


}

cout<<Sum;

}
