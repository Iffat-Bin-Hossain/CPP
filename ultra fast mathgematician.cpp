#include<iostream>
#include<cstring>
using namespace std;
int main(){
char S1[105],S2[105],S3[105];
cin>>S1;
cin>>S2;
for(int i=0;i<strlen(S1);i++){
    if(S1[i]==S2[i]){
        S3[i]='0';
    }
    else{
        S3[i]='1';
    }


}
S3[strlen(S1)]='\0';
cout<<S3;

}
