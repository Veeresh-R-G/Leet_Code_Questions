class Solution {

private:
    int timer = 1;

private:

    void dfs(int node , int par , vector<bool>& vis , vector<int> adj[],vector<int>& time , vector<int>& lowest , vector<vector<int>>& ans)
    {
        vis[node] = true;
        time[node] = lowest[node] = timer;
        timer++;

        for(auto child : adj[node])
        {
            if(child != par)
            {
                if(!vis[child])
                {
                    dfs(child , node , vis , adj , time , lowest , ans);

                    lowest[node] = min(lowest[node] , lowest[child]);

                    //can node <---> it be a bridge?
                    
                    if(lowest[child] > time[node])
                    {
                        ans.push_back({node , child});
                    }
                    

                }
                else
                {
                    lowest[node] = min(lowest[node] , lowest[child]);
                }
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        

        vector<int> adj[n];

        for(auto it : connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> time(n , 0);
        vector<int> lowest(n , 0);

        vector<bool> vis(n , false);

        vector<vector<int>> bridge_edges;

        dfs(0 , -1 , vis , adj , time , lowest , bridge_edges);

        return bridge_edges;


    }
};