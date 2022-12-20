class Solution {
public:
    
    
    bool dfs(vector<int> graph[] , int curr , int dest , vector<bool>& vis)
    {
        if(curr == dest)
        {
            return true;
        }
        
        vis[curr] = true;
        for(auto child : graph[curr])
        {
            if(!vis[child])
            {
                if(dfs(graph , child , dest , vis))
                {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        
        vector<int> graph[n];
        
        for(auto it : edges)
        {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        
        //Now adjacency list is ready
        vector<bool> vis(n , false);
        return dfs(graph , source , destination , vis);
        
    }
};