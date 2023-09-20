#include<iostream>
using namespace std;
int main(){
    while(1){
    int n,r;
    cin>>n>>r;
     int Table[n+1][r+1];
     for(int i=0;i<=n;i++){
            for(int j=0;j<=r;j++){
               Table[i][j]=-1;
        }
        }
        for(int i=0;i<=n;i++){
                Table[i][0]=1;
                Table[i][i]=1;
                if(i!=0){
                    Table[i][1]=i;
                }
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=r;j++){
               if(i>=j && Table[i][j]==-1){
                    Table[i][j]=Table[i-1][j]+Table[i-1][j-1];
               }
        }
        }
        cout<<Table[n][r];
    }
}