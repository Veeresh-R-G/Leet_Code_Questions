class Solution {


private:

    void dfs(vector<int> adj[] , int src , vector<bool>& vis)
    {
        if(vis[src]) return;

        vis[src] = true;

        for(auto it : adj[src])
        {
            if(vis[it] == false)
            {
                dfs(adj , it , vis);
            }
            continue;
        }
    }

public:

    int countProvinces(int n , vector<int> adj[])
    {
        vector<bool> vis(n , false);
        
        int ans = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(vis[i] == false)
            {
                ans++;

                dfs(adj , i , vis);
            }
        }

        return ans;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();

        vector<int> adj[n];

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < isConnected[i].size() ; j++)
            {
                if(isConnected[i][j])
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }


        return countProvinces(n ,adj);


    }
};