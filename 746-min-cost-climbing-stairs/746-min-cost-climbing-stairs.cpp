class Solution {
public:
    
    int solve(vector<int>& cost , int ind , vector<int>& dp)
    {
        if(ind == cost.size() - 1)
        {
            return cost[ind];
        }
        
        if(ind >= cost.size())
        {
            return 0;
        }
        
        if(dp[ind] != -1)            
        {
            return dp[ind];
        }
        else
        {
            int currCost = cost[ind];
            
            return dp[ind] = currCost + min(solve(cost , ind + 1 , dp) , solve(cost , ind + 2 , dp));
        }
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        vector<int>dp1(n + 1, -1);
        vector<int>dp2(n + 1, -1);
        return min(solve(cost , 0 , dp1) , solve(cost , 1 ,dp2));
    }
};