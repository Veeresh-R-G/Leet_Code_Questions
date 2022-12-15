class Solution {
public:
    
    int f(vector<int>& nums , int n , int ind , int prev , vector<vector<int>>& dp)
    {
        if(ind == n)
        {
            return 0;
        }
        if(dp[ind][prev + 1] != -1) return dp[ind][prev + 1];
        int pick = prev == -1 || nums[ind] > nums[prev] ? 1 + f(nums , n , ind + 1 , ind , dp) : 0;
        int notPick = f(nums,n,ind + 1,prev , dp);
        
        return dp[ind][prev + 1] = max(pick , notPick);
    }
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n + 1 , vector<int>(n + 2 , -1));
        return f(nums , n , 0 , -1,dp);
        
    }
};