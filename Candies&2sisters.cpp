#include<iostream>
#include<vector>
using namespace std;
int main(){
long int t;
vector<long long int>n;
long long int i,x;
cin>>t;
for(i=0;i<t;i++){
 cin>>x;
 n.push_back(x);

}
for(i=0;i<t;i++)
{
  if(n.at(i)%2==0)
        cout<<(n.at(i)/2)-1<<endl;
  else
    cout<<((n.at(i)+1)/2)-1<<endl;

}

}
