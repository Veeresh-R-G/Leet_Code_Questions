class Solution {
public:
    
    bool solve(vector<int>& nums , int ind , int target ,vector<vector<int>> &dp)
    {
       
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
        
        if(nums.size() == 1)
        {
            return false;
        }
        int N = nums.size();
        int sum = 0;
        for(auto ele : nums) sum += ele;
        
        if(sum % 2 == 1)
        {
            return false;
        }
        
        /*
        This is for MemoiZation
        
        vector<vector<int>> dp(N , vector<int>((sum / 2) + 2 , -1));
        */
        
        //Tabulation
        
        vector<vector<int>> dp(N , vector<int>((sum / 2) + 1 , 0));
        
        //Base Case - 1
        for(int ind = 0 ; ind < N ; ind++)
        {
            dp[ind][0] = true;
        }
        
        //Base Case - 2
        if(nums[0] <= (sum / 2))
        dp[0][nums[0]] = true;
        
        
        for(int ind = 1 ; ind < N ; ind++)
        {
            for(int target = 1 ; target <= (sum / 2) ; target++)
            {
                
                bool pick = nums[ind] <= target ? dp[ind - 1][target - nums[ind]] :false;
        
        bool notPick = dp[ind - 1][target];
                
                dp[ind][target] = pick || notPick;
            }
        }
        
        return dp[N - 1][sum / 2];
        // return solve(nums , N - 1 , (sum / 2) , dp); 
    }
};