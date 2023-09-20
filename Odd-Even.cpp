#include<iostream>

using namespace std;

int main()
{

    long long int n,k;
    cin>>n >>k;
    if(n%2==0 && (n/2)<k){
        cout<<2*(k-(n/2));
    }
    else if(n%2!=0 && ((n+1)/2)<k){
        cout<<2*(k-((n+1)/2));
    }
    else{
        cout<<(2*k)-1;
    }

}
