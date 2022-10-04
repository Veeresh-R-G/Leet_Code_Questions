class Solution {
public:
    
    int solve(vector<int>& prices, int fee , vector<vector<int>>& dp , int ind , int buy)
    {
        if(ind >= prices.size()) return 0;
        
        if(dp[ind][buy] != -1) return dp[ind][buy];
        if(buy)
        {
            int TAKE = -prices[ind] + solve(prices , fee , dp , ind + 1 ,0 );
            int NTAKE = solve(prices , fee , dp , ind + 1, 1);
            
            return dp[ind][buy] = max(TAKE , NTAKE);
        }
        else
        {   
            //Selling part
            int SELL = - fee + prices[ind] + solve(prices , fee , dp , ind + 1 , 1);
            int NSELL = solve(prices , fee , dp , ind + 1, 0);
                              
            return dp[ind][buy] = max(SELL , NSELL);
        }
        
        
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        
        
        int n = prices.size();
        vector<vector<int>> dp(n + 1 , vector<int>(2 , -1));
        int buy = 1;
        return solve(prices , fee , dp , 0 , buy);
    }
};