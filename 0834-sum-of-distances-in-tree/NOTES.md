​My TLE SOLUTION : 

```
vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        int N = n;
        vector<int> g[N];
        
        vector<int> ans;
        
        
        for(auto edge : edges)
        {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        
        vector<int> ANS;
        for(int i = 0 ; i < N ; i++)
        {
            vector<bool> vis(N ,false);
            vector<int> level(N , 0);
            int ans = 0;
            
            dfs(g , i , vis , level);
            
            for(auto levels : level)
            {
                ans += levels;
            }
            ANS.push_back(ans);
        }
        
        
        return ANS;
            
    }

```
