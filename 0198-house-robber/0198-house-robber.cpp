class Solution {
public:
    
    int f(vector<int>&nums , int n , int ind , vector<int>& dp)
    {
        if (ind >= n)
        {
            return 0;
        }
        if(dp[ind] != -1) return dp[ind];
        int pick = nums[ind] + f(nums , n , ind + 2 , dp);
        int notPick = f(nums , n , ind + 1 ,dp);
        
        return dp[ind] = max(pick , notPick);
    }
    
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        /*
            Only changing state --> ind
        */
        vector<int> dp(n + 1 , -1);
        return f(nums , n , 0 , dp);
    }
};