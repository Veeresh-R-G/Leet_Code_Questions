class Solution {    
public:    
    void dfs(vector<int>& compo , int src , int& miniChar , vector<bool>& vis,
            vector<vector<int>>& graph )
    {
        
        vis[src] = true;
        compo.push_back(src);
        
        miniChar = min(miniChar , src);
        for(int i = 0 ; i < 26 ; i++)
        {
            if(graph[src][i] == 1 && vis[i] == false)
            {
                dfs(compo , i , miniChar , vis , graph);
            }
        }
    }
    
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        
        
        int N = s1.size();
        vector<vector<int>>graph (26 , vector<int>(26 , 0));
        vector<bool>vis (26 , false);
        for(int i = 0 ; i < N ; i++)
        {
            graph[s1[i] - 'a'][s2[i] - 'a'] = 1;
            graph[s2[i] - 'a'][s1[i] - 'a'] = 1;
        }
        
        vector<int> mapping(26 , -1);
        
        for(int i = 0 ; i < 26 ; i++)
        {
            mapping[i] = i;
        }
        
        
        
        
        for(int i = 0 ; i < 26 ; i++)
        {
            if(vis[i] == false)
            {
                
                vector<int> component;
                int mini = 100;
                
                dfs(component , i , mini , vis , graph);
                
                for(auto ele : component)
                {
                    mapping[ele] = mini;
                }
            }
        }
        
        
        string ans = "";
        
        for(auto it : baseStr)
        {
            ans = ans + char ('a' + mapping[it - 'a']);
        }
        
        
        
        return ans;
    }
};