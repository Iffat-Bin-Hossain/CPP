#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int LCS(int i,int j,string s1,string s2){
if(s1[i]=='\0'|| s2[j]=='\0'){
return 0;
}
if(s1[i]==s2[j]){
    return 1+LCS(i+1,j+1,s1,s2);
}
return max(LCS(i+1,j,s1,s2),LCS(i,j+1,s1,s2));
}
int main(){
string s1,s2;
cout<<"Enter 1st string :";
cin>>s1;
cout<<"Enter 2nd string :";
cin>>s2;
int l1=s1.size();
int l2=s2.size();
int LCS[l1+1][l2+1];
for(int i=0;i<=l1;i++){
    for(int j=0;j<=l2;j++){
        if(i==0 || j==0){
            LCS[i][j]=0;
        }
        else if(s1[i-1]==s2[j-1]){
            LCS[i][j]=1+LCS[i-1][j-1];
        }
        else{
            LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
        }
    }
}
cout<<"LCS TABLE:"<<endl;
for(int i=0;i<=l1;i++){
    for(int j=0;j<=l2;j++){
        cout<<LCS[i][j]<<" ";
    }
    cout<<endl;
}
cout<<"Length of LCS:"<<LCS[l1][l2]<<endl;
//BackTracing
vector<char> lcs;
int j=l2;
int i=l1;
while(j>0 && i>0)
{

if(s1[i-1]==s2[j-1]){
    lcs.push_back(s1[i-1]);
    i--;
    j--;
}
else if(LCS[i-1][j]>LCS[i][j-1]){
        i--;  
}
else{
        j--;
    }
}
cout<<"Longest Common SubSequence :";
for(int i=lcs.size()-1;i>=0;i--){
    cout<<lcs.at(i);
}

}