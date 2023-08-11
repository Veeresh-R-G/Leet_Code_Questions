class Solution {

private:
    int solve(int amt , vector<int>& coins , int ind , vector<vector<int>>& dp){

        if(ind < 0){
            return 0;
        }

        if(ind == 0){
            return amt % coins[ind] == 0 ? 1 : 0;
        }

        if (dp[amt][ind] != -1){
            return dp[amt][ind];
        }
        int pick = amt >= coins[ind] ? solve(amt - coins[ind] , coins , ind,dp) : 0;
        int notPick = solve(amt , coins , ind - 1,dp);

        return dp[amt][ind] = pick + notPick;
    }
public:
    int change(int amount, vector<int>& coins) {

        int n = coins.size() - 1;

        vector<vector<int>> dp(amount + 1 , vector<int>(coins.size() , -1));
        
        int ind = n;
        return solve(amount , coins , ind , dp);
    }
};