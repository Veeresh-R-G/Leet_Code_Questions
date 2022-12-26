class Solution {
public:
    
    int f(vector<int>& nums ,int ind , int n , vector<int>& dp)
    {
        if(ind >= n - 1)
        {
            return 0;
        }
        
        if(dp[ind] != -1) return dp[ind];
        
        int miniJumps = 1e9;
        
        for(int i = 1 ; i <= nums[ind] ; i++)
        {
            miniJumps = min(miniJumps , 1 + f(nums , ind + i , n , dp));
        }
        
        return dp[ind] = miniJumps;
    }
    
    int jump(vector<int>& nums) {
        
        
        int n = nums.size();
        int ind = 0;
        vector<int> dp(n + 1 , -1);
        return f(nums , ind , n ,dp);
    }
};