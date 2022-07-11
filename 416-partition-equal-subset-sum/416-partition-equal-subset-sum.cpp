class Solution {
public:
    
    bool solve(vector<int>& nums , int ind , int target ,vector<vector<int>> &dp)
    {
        if(target < 0) return false;
        if(target == 0)
        {
            return true;
        }
        if(ind == 0)
        {
            return nums[0] == target;
        }
        if(dp[ind][target] != -1)
        {
            return dp[ind][target];
        }
        
        bool pick = nums[ind] <= target ? solve(nums , ind - 1 , target - nums[ind] , dp) :false;
        
        bool notPick = solve(nums , ind - 1 , target , dp);
        
        return dp[ind][target] =  pick || notPick;
    }
    
    bool canPartition(vector<int>& nums) {
        
        int N = nums.size();
        int sum = 0;
        for(auto ele : nums) sum += ele;
        
        if(sum % 2 == 1)
        {
            return false;
        }
        
        vector<vector<int>> dp(N , vector<int>((sum / 2) + 2 , -1));
        return solve(nums , N - 1 , (sum / 2) , dp); 
    }
};