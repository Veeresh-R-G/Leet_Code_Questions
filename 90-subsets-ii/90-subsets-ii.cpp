class Solution {
public:
    /*
    
        
        
    */
    
    set<vector<int>> mySet;
    
    
    
    void solve(vector<int> inp , vector<int>& out , int ind)
    {
        if(ind >= inp.size())
        {
            vector<int> t = out;
            sort(t.begin() , t.end());
            mySet.insert(t);
            return;
        }
        
        out.push_back(inp[ind]);
        solve(inp , out , ind + 1);
        
        out.pop_back();
        solve(inp , out ,ind + 1);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        
        vector<int> out = {};
        
        solve(nums , out , 0);
        vector<vector<int>> ans;
        
         set<int, greater<int> >::iterator itr;
         for (auto itr = mySet.begin(); itr != mySet.end(); itr++) 
         {
             vector<int> temp = *(itr);
            ans.push_back(temp);      
         }
        
        return ans;
    }
};