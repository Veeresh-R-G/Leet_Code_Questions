class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        int N = n;
        vector<int> g[N + 1];
        vector<bool> vis(N + 1 , false);
        vector<int> color(N + 1, -1);
        
        /*
            My colors : 10 and 20
        */
        // Graph 
        for(auto it : dislikes)
        {
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        
        queue<int> q;
        
        
        
        
        for(int node = 1 ; node <= N ; node++)
        {
            if(vis[node]) continue;
            
            q.push(node);
            vis[node] = true;
            color[node] = 10;
            while(!q.empty())
            {
                int curr = q.front();
                q.pop();

                int curr_color = color[curr];

                for(auto child : g[curr])
                {
                    if(!vis[child])
                    {
                        if(color[child] ==-1 && curr_color == 10)
                        {
                            color[child] = 20;
                        }
                        else if(color[child] ==-1 && curr_color == 20)
                        {
                            color[child] = 10;
                        }
                        q.push(child);
                        vis[child] = true;
                    }
                    else
                    {
                        //Node is already visited so check the color here
                        if(curr_color == color[child])
                        {
                            return false;
                        }
                    }
                }
            }           
            
        }
        
        return true;
        
        
        
        
        
        
    }
};