class Solution {
public:
    
    vector<vector<int>> ans = {};
    
    void solve(vector<int> nums,vector<int>& output , int ind)
    {
        if(ind >= nums.size())
        {
            ans.push_back(output);
            return;
        }
        
        output.push_back(nums[ind]);
        
        solve(nums , output , ind + 1);
        
        output.pop_back();
        
        solve(nums , output , ind + 1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> output;
        
        int index = 0;
        
        solve(nums , output , index);
        return ans;
    }
};