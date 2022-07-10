class Solution {
public:
    
    int solve(vector<int>&cost , int ind , int N , vector<int>& dp)
    {
        
        //Base Case
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
        
        vector<int> dp(n + 1, 0);
        
        
        //Base Case
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        for(int i = 2; i <n ; i++)
        {
            dp[i] = min(cost[i] + dp[i - 1] , cost[i] + dp[i - 2]);
        }
        for(auto it : dp)
        {
            cout << it << " ";
        }
        return min(dp[n -1] , dp[n - 2]);
        
        
        
//         int zero = solve(cost , 0 , n , dp);
//         int one = solve(cost , 1 , n, dp);
        
//         return min(zero , one);
        
    }
};