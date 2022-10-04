class Solution {
public:
     int solve(vector<int>& prices ,vector<vector<vector<int>>> &dp , int ind , int buy , int trans)
    {
        if (ind >= prices.size() || trans <= 0) return 0;
        
        if(dp[ind][buy][trans] != -1) return dp[ind][buy][trans];
        if(buy)
        {
            int BUY = -prices[ind] + solve(prices , dp , ind + 1 , 0 , trans);
            int NBUY = solve(prices , dp , ind + 1 , 1 , trans);
            
            return dp[ind][buy][trans] = max(BUY , NBUY);
        }
        
        return dp[ind][buy][trans] = max(+prices[ind] + solve(prices , dp , ind + 1, 1 , trans - 1) ,
                                 solve(prices , dp , ind + 1, 0 , trans));
    }
    int maxProfit(vector<int>& prices) {
        
        int trans = 2;
         int n = prices.size();
         // vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2 , vector<int>(3 , -1)));
        return solve(prices , dp , 0 , 1 , trans);
        
    }
};