class Solution {
public:
    
    int f(int ind , vector<int>& cost , vector<int>&dp , int n)
    {
        if(ind >= n) 
        {
            return 0;
        }
        
        if(dp[ind] != -1) return dp[ind];
        
        int one = cost[ind] + f(ind + 1, cost , dp , n);
        int two = cost[ind] + f(ind + 2, cost , dp , n);
        
        return dp[ind] = min(one , two);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        
        int n = cost.size();
        vector<int> dp(n + 1 , -1);
        int startFrom_Zero = f(0 ,cost , dp , n);
        
        vector<int> dp2(n + 1 , -1);
        int startFrom_One = f(1 ,cost , dp2 , n);
        
        return min(startFrom_Zero , startFrom_One);
    }
};