class Solution {
public:
    
    int f(vector<int>& nums , int ind , int N , vector<int>& dp)
    {
        if(ind >= N - 1)
        {
            return 0;
        }
        
        if(dp[ind] != -1)
        {
            return dp[ind];
        }
        int mini = 1e7;
        for(int i = 1 ; i <= nums[ind] ; i++)
        {
            
            mini = min(mini ,1 + f(nums , ind + i , N, dp));
        }
        
        return dp[ind] = mini;
    }
    
    int jump(vector<int>& nums) {
     
        int N = nums.size();
        int ind = 0;
        vector<int> dp(N , -1);
        return f(nums , ind , N , dp);
    }
};