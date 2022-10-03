class Solution {
public:
    
    int solve(vector<int>&nums , int ind , vector<int>& dp)
    {
        if(ind >= nums.size() || nums[ind] == -1)
        {
            return 0;
        }
        
        if(dp[ind] != -1) return dp[ind];
        int pick = nums[ind] + solve(nums,ind + 2,dp);
        int notPick = solve(nums , ind + 1,dp);
        
        return dp[ind] = max(pick , notPick);
    }
    int rob(vector<int>& nums) {
        
        if(nums.size() == 1) return nums[0];
        int last = nums[nums.size() - 1];
        
        vector<int> dp1(nums.size() + 1 , -1);
        nums.pop_back();            
        int temp1 = solve(nums , 0 , dp1);
        
        vector<int> dp2(nums.size() + 1 , -1);
        nums.push_back(last);
        int temp2 = solve(nums , 1 , dp2);
        
        return max(temp1 , temp2);
    }
};