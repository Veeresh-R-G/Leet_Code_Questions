class Solution {
public:
    
    int solve(vector<int>&cost , int ind , int N , vector<int>& dp)
    {
        if(ind == N - 1)
        {
            return cost[ind];
        }
        if(dp[ind] != -1)
        {
            return dp[ind];
        }
        if(ind >= N )
        {
            return 0;
        }
        
        int one = cost[ind] + solve(cost , ind + 1 , N, dp);
        int two = cost[ind] + solve(cost , ind + 2 , N, dp);
        
        return dp[ind] = min(one , two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        
        
        int n = cost.size();
        
        vector<int> dp(n + 1 , -1);
        int zero = solve(cost , 0 , n , dp);
        int one = solve(cost , 1 , n, dp);
        
        return min(zero , one);
        
    }
};