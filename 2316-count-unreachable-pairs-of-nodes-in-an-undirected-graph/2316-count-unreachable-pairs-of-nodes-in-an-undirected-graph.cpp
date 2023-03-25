class Solution {
public:
    vector<vector<int>> compos;
    
    
    void dfs(int node , vector<int>adj[] , vector<bool>& vis , vector<int>& temp)
    {
        if(vis[node]) return;
        
        vis[node] = true;
        temp.push_back(node);
        
        for(auto child : adj[node])
        {
            if(vis[child] == false)
            {
                dfs(child , adj , vis , temp);
            }
        }
        
        
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        
        vector<bool>vis(n , false);
        vector<int>adj[n];
        
        //Graah
        for(auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        long long ans = 0;
        long long size_of_compo = 0;
        long long remaining_nodes = n;
        
        for(int i = 0 ; i < n ; i++)
        {
            vector<int> temp;
            if(vis[i] == false)
            {
                
                dfs(i , adj , vis , temp);
                size_of_compo = temp.size() * 1ll;
                ans += size_of_compo * (remaining_nodes - size_of_compo);
                remaining_nodes -= size_of_compo;
            }
            
            
        }
        
       
        
        return ans;
        
        
        
    }
};