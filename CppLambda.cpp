#include<bits/stdc++.h>
using namespace std;
int main(){
cout<<[](int x){return x+5;}(2)<<endl;
cout<<[](int x,int y){return x*y;}(2,6)<<endl;
auto Sum=[](int x,int y){return x-y;};
cout<<Sum(3,7)<<endl;
vector<int> v={2,-3,5};
cout<<all_of(v.begin(),v.end(),[](int x){return x>0;})<<endl;
cout<<any_of(v.begin(),v.end(),[](int x){return x>0;})<<endl;
auto p=find_if(v.begin(),v.end(),[](int x){return x>3;});
cout<<*p<<endl;
auto Push=[&v](int x){v.push_back(x);};
Push(20);
auto Show=[&v](){ for(auto i=v.begin();i!=v.end();i++){
    cout<<*i<<" ";
}
cout<<endl;};
Show();
auto Count=count_if(v.begin(),v.end(),[&v](int x){
    return x>0;});
cout<<Count(5)<<endl;
}