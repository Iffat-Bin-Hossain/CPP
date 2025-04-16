#include <bits\stdc++.h>
using namespace std;
void solve(string s,int open,int close,vector<string> &ans){
    if(open==0 && close==0){
        ans.push_back(s);
        return;
    }
    else if(open==close){
        solve(s+"(",open-1,close,ans);
    }
    else if(open==0){
        for(int i=0;i<close;i++){
            s=s+")";
        }
        ans.push_back(s);
        return;
    }
    else if(open<close){
        solve(s+"(",open-1,close,ans);
        solve(s+")",open,close-1,ans);
    }
    else{
        //nothing
    }
}
vector<string> generateParenthesis(int n)
{
    vector<string> ans;
    solve("",n,n,ans);
    return ans;
}
int main()
{
    int n;
    cin >> n;
    auto validParenthesis = generateParenthesis(n);
    for(auto i=validParenthesis.begin(); i!=validParenthesis.end(); i++){
        cout<<*i<<" ";
    }
    cout<<endl;
}