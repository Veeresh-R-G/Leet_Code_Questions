class Solution {
public:
    
    int f(vector<int>& nums , int target , int ind , vector<vector<int>>& dp)
    {
        if(ind >= nums.size())
        {
            return 0;
        }
        
        if(dp[target][ind] != -1) return dp[target][ind];
        
        int pick = target >= nums[ind] ? 1 + f(nums , target - nums[ind] , ind + 1 , dp) : 0;
        int notPick = f(nums , target , ind + 1 ,dp);
        
        return dp[target][ind]= max(pick , notPick);
        
        
        
    }
    
    int tabulate(int target , int n , vector<int>& nums)
    {
        //Dp inialisation
        vector<vector<int>> dp(target + 1 , vector<int>(nums.size() + 1 , 0));
        
        /*
        
            Now Base Conditions from Recursion See
            That already done cause we have filled our table already with 0's
        */
        
        //Now looping constructs
        for(int T = 0 ; T <= target ; T++)
        {
            
            for(int ind = 0 ; ind < nums.size() ; ind++)
            {
                
                int pick = T >= nums[ind] ? 1 + dp[T - nums[ind]][ind + 1]  : 0;
                int notPick = dp[T][ind + 1];
        
                dp[T][ind]= max(pick , notPick);
            }
        }
        
        
        
        return dp[target][n - 1];
    }
    
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        
        int n = nums.size();
        int m = queries.size();
        
        sort(nums.begin() , nums.end());
        
        vector<int> ans(m , 0);
        
       
//         for (int i = 0 ;  i < m ; i++)
//         {
            
//             int target = queries[i];
            
//             if(nums[0] > target) continue;
            
//             //if target is greater than or equal to the smallest element in  nums
            
//             // vector<vector<int>> dp(target + 1 , vector<int>(n , -1));
            
//             int count = tabulate(target , n , nums);
            
            
//             ans[i] = count;
//         }
       
        
        for(int i = 0 ; i < m ; i++)
        {
            int target = queries[i];
            int ind = 0;
            
            while(target > 0 && ind < n)
            {
                target = target - nums[ind];
                ind += 1;
            }
            
            ans[i] = target < 0 ? ind - 1 : ind;
        }
    
        return ans;
       
        
        
    }
};