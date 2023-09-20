#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int R=m*n;
    int i=0;
    while(R!=0){
        R=(m*n)-(m+n-1);
        m--;
        n--;
        i++;
    }
    if(i%2==0){
        cout<<"Malvika"<<endl;
    }
    else{
        cout<<"Akshat"<<endl;
    }
    
}