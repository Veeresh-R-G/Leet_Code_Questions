//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        
        vector<bool> vis(V , false);
        
        queue<pair<int , int>> q;
        
        
        // node <--> parent
        
        
        for(int i = 0 ; i < V ; i++)
        {
            if(vis[i] == false)
            {   q.push({i , -1});
                while(q.empty() == false)
                {
                    auto top = q.front();
                    int node = top.first;
                    int par = top.second;
                    
                    if(vis[node]) return true;
                    vis[node] = true;
                    q.pop();
                    
                    for(auto it : adj[node])
                    {
                        if(it != par && vis[it] == false)
                        {
                            q.push({it , node});
                        }
                    }
                }
            }
        }
        
        return false;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends