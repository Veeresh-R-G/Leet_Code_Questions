//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void dfs(int node , vector<int> g[] , vector<bool>& vis)
  {
      vis[node] = true;
      
      for(auto it : g[node])
      {
          if(vis[it] == false)
          {
              dfs(it , g , vis);
          }
      }
  }
  
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
    
        int ans = 0;
        
        vector<int> graph[V];
        
        for(int i = 0 ; i < V ; i++)
        {
            for(int j = 0 ; j < V ; j++)
            {
                if(adj[i][j] == 1 && i != j)
                {
                    graph[i].push_back(j);
                }
            }
        }
        
        vector<bool> vis(V , false);
        
        for(int i = 0 ; i < V ; i++)
        {
            if(vis[i] == false)
            {
                ans++;
                dfs(i , graph, vis);
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