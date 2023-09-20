//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> color(V, -1);
        queue<int> q;
        color.at(0) = 1;
        q.push(0);
        while (!q.empty())
        {
            int f= q.front();
            q.pop();
           for(auto it =0;it<adj[f].size();it++){
                // if(adj[f].at(it)==f){
                //     return false;
                // }

                if (color.at(adj[f][it])==-1)
                {
                    q.push(adj[f].at(it));
                    color.at(adj[f].at(it)) = 1 - color.at(f);
                }
                else if (color.at(adj[f].at(it)) == color.at(f))
                {
                    return false;
                }
                
            }
        }
        return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
    freopen("input.txt", "r", stdin);
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends