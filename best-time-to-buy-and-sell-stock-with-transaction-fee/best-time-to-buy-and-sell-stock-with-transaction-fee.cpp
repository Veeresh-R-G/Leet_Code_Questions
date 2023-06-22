class Solution {
public:

    int f(vector<int>&prices , int fee , int ind , int N , bool buy,vector<vector<int>>& dp)
    {
        if(ind >= N)
        {
            //Do nthg if index goes out of range
            return 0;
        }


        if(dp[ind][buy] != -1)
        {
            return dp[ind][buy];
        }

        int pick , notPick;
        if(buy)
        {
            //Yet to buy a stock
            pick = -prices[ind] + f(prices , fee , ind + 1 , N , !buy , dp);
            notPick = f(prices , fee , ind + 1 , N , buy,dp);
        }
        else
        {
            //already bought and want to sell
            pick = +prices[ind] - fee + f(prices , fee ,ind + 1 , N , !buy,dp);
            notPick = f(prices , fee , ind + 1 , N , buy,dp);
        }

        return dp[ind][buy] = max(pick , notPick);
    }

    int maxProfit(vector<int>& prices, int fee) {
        
        int N = prices.size();
        int ind = 0;
        bool buy = true;
        //States --> Ind and Buy value
        //sp --> N * 2 states

        vector<vector<int>> dp(N , vector<int>(2 , -1));
        return f(prices , fee ,ind , N, buy , dp);
    }
};