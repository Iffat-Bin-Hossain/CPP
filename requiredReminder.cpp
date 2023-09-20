#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
    int x,y,n;
    cin>>x>>y>>n;
    int temp=n;
    while(temp%x!=y){
        temp--;
    }
    cout<<temp<<endl;
    }
}
