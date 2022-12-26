class Solution {
public:
    
    
    bool f(vector<int>& nums , int ind , int n , vector<int>& dp)
    {
        if(ind == n - 1)
        {
            return true;
        }
        if(ind != n - 1 && nums[ind] == 0)
        {
            return false;
        }
        if(ind >= n)
        {
            return false;
        }
        
        if(dp[ind] != -1) return dp[ind];
        
        for(int i = 1 ; i <= nums[ind] ; i++)
        {
            if(f(nums , ind + i , n , dp))
            {
                return dp[ind] = true;
            }
            
        }
        
        return dp[ind] = false;
    }
    
    
    bool canJump(vector<int>& nums) {
        
        
        
        int ind = 0;
        int n = nums.size();
        
        vector<int> dp(n + 1 , -1);
        return f(nums , ind , n , dp);
        
    }
};