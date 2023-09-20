#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string str;
        cin>>str;
        vector<string>melody;
        string firstMelody=str.substr(0,2);
        melody.push_back(firstMelody);
        for(int i=1;i<n-1;i++){
            string currentMelody=str.substr(i,2);
            int flag=0;
            for(int j=0;j<melody.size();j++){
                if(currentMelody==melody[j]){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                melody.push_back(currentMelody);
            }
        }
        cout<<melody.size()<<endl;

    }
}