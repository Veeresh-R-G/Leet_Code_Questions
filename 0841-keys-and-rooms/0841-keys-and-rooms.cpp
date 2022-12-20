class Solution {
public:
    
    void dfs(vector<int> g[] , int curr , vector<bool>& vis)
    {
        
        vis[curr] = true;
        
        for(auto child : g[curr])
        {
            if(vis[child]) continue;
            
            
            dfs(g , child , vis);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
     
        int N = rooms.size();
        vector<int> g[N];
        
        vector<bool> vis(N , false);
        for(int room = 0 ; room < N ; room++)
        {

            for(int keys  = 0 ; keys < rooms[room].size() ; keys++)
            {
                // cout << rooms[room][keys] << " ";
                // cout << keys << " ";
                g[room].push_back(rooms[room][keys]);
            }
        }
        
        
        // InCase we have disconnected components
        
//         for(int room = 0; room < N ; room++)
//         {
//             if(!vis[room])
//             {
//                 dfs(g , room , vis);
//             }
            
//         }
        
        dfs(g , 0 , vis);
        
        
        for(auto it : vis)
        {
            if(it == false)
            {
                return false;
            }
        }
        
        return true;
    }
};