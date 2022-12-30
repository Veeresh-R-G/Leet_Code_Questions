class Solution {
public:
    
    
    void dfs(vector<vector<int>>& graph , int curr  , vector<bool>& vis , vector<vector<int>>& ans , vector<int>& temp)
    {

        temp.push_back(curr);
        
        if(curr == graph.size() - 1)
        {
            ans.push_back(temp);
        }
        
        else
        {
             for(auto child : graph[curr])
                {
                    dfs(graph , child , vis , ans , temp);   
                }
        }
       
        
        temp.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        
        vector<vector<int>> ans;
        vector<int> temp;
        int N = graph.size();
        vector<bool> vis(N , false);
        
        int source = 0;
        
        dfs(graph , source , vis , ans , temp);
        
        return ans;
    }
};