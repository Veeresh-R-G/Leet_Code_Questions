class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<pair<int , int>> adj[n + 1];
        
        
        //Adj List
        // node --> Neighbour , weight
        for(int i = 0 ; i < roads.size() ; i++)
        {
            adj[roads[i][0]].push_back({roads[i][1] , roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0] , roads[i][2]});
        }
        
        vector<bool>vis (n + 1 , false);
        
        queue<int> q;
        
        q.push(1);
        vis[1] = true;
        long long answer = INT_MAX;
        
        
        while(q.empty() == false)
        {
            
            auto f = q.front();
            q.pop();
            
            for(auto ele : adj[f])
            {
                answer = min(1ll*ele.second , answer);
                if(vis[ele.first] == false)
                {
                    vis[ele.first] = true;
                    q.push(ele.first);
                }
            }
        }
        
        return answer;
        
    }
};