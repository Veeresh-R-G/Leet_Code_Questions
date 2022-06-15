class Solution {
public:
    
    
    
    void solve(int ind, vector<int> nums , vector<int>&out , vector<vector<int>>& ans)
    {
        
        ans.push_back(out);
        
        
        for(int i = ind ; i < nums.size() ; i++)
        {
            /*
                This IF statement is the main STAR AND beautty of this problem
                This is done to avoid the duplicates and also takes in unique elements
                so Nicely....OP only this is.
            */
            if(i != ind && (nums[i] == nums[i-1]))
            {
                continue;
            }
            out.push_back(nums[i]);
            solve(i + 1 , nums , out , ans);
            out.pop_back();
        }
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> out = {};
        
        sort(nums.begin() , nums.end());
        solve(0 , nums , out , ans);
        
        return ans;
    }
};