//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
  
  
    void dfs(int node , vector<int> graph[] , vector<bool>& vis)
    {
        if(vis[node] == true) return;
        
        vis[node] = true;
        
        for(auto child : graph[node])
        {
            if(!vis[child])
            {
                dfs(child , graph , vis);
            }
        }
    }
    
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        
        vector<int> graph[V];
        
  
        
        for(int i = 0 ; i < V ; i++)
        {
            for(int j = 0 ; j < V ; j++)
            {
                if(i != j && adj[i][j] == 1)
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        
        // cout << "HEre" << endl;
        
        vector<bool> vis(V , false);
        int ans = 0;
        for(int i = 0 ; i < V ; i++)
        {
            if(vis[i] == false)
            {
                ans++;
                dfs(i , graph , vis);
            }
        }
        
        
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends