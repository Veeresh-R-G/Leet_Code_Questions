class Solution {

private:
    int MOD = 1e9 + 7;
    vector<vector<int>> dp;

    int helper(int n, int k, int target){

        //Base case of 1 die only
        if(n == 1){
            return target <= k ? 1 : 0;
        }

        
        //if there is some target left but no die left
        //we have some dices but target is already reached
        if((target > 0 && n == 0) || (target <= 0 && n > 0)){
            return 0;
        }

        if(dp[n][target] != -1){
            return dp[n][target];
        }

        int ways = 0;
        for(int face = 1; face <= k && face < target ; face++){
            ways = ((ways % MOD) + (helper(n - 1,k, target - face) % MOD)) % MOD;
        }

        return dp[n][target] = ways % MOD;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        
        dp.resize(n + 1, vector<int>(target + 2 , -1));
        return helper(n, k, target) % MOD;
    }
};