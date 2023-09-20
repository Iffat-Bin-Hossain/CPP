#include<bits/stdc++.h>
using namespace std;
int minCoin(int coin[],int size,int n){
    if(n==0){
        return 0;
    }
    for(int i=0;i<size;i++){
        if(n>=coin[i]){
            return min(1+minCoin(coin,size,n-coin[i]),minCoin(coin,size,n));
        }
    }
}