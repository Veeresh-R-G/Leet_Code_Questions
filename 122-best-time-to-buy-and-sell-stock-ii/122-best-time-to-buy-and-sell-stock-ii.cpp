class Solution {
public:
    
     int solve(vector<int>& prices ,vector<vector<int>>&dp , int ind , int buy)
    {
        if (ind >= prices.size()) return 0;
        
        if(dp[ind][buy] != -1) return dp[ind][buy];
        if(buy)
        {
            int BUY = -prices[ind] + solve(prices , dp , ind + 1 , 0);
            int NBUY = solve(prices , dp , ind + 1 , 1);
            
            return dp[ind][buy] = max(BUY , NBUY);
        }
        
        return dp[ind][buy] = max(+prices[ind] + solve(prices , dp , ind + 1, 1) ,
                                 solve(prices , dp , ind + 1, 0));
    }
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2 , -1));
        return solve(prices , dp , 0 , 1);
    }
};