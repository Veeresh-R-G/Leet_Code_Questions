class Solution {
public:
    
    void dfs(int node , vector<bool>& vis , vector<int> adj[])
    {
        
        if(vis[node]) return;
        vis[node] = true;
        
        for(auto child : adj[node])
        {
            if(vis[child] == false)
            {
                dfs(child , vis , adj);
            }
        }
    }
    
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size() < (n - 1)) return -1;
        
        vector<bool>vis (n , false) ;
        vector<int> adj[n];
        
        for(auto it : connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int compos = 0;
        
        for(int i = 0 ; i < n ; i++)
        {
            if(vis[i] == false)
            {
                dfs(i , vis , adj);
                compos++;
            }
        }
        
        // cout << compos << endl;
        return abs(compos - 1);
    }
};