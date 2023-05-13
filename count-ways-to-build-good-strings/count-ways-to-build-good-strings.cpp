class Solution {
public:

    long long MOD = 1e9 + 7;

    long long f(int required_length , int zeros , int ones , vector<long long>& dp)
    {
        if(required_length == 0)
        {
            return 1;
        }
        if(required_length < 0)
        {
            //Invaid cases for example we have req_len = 1
            //we append 2 1's
            //so req_len = 1 - 2 = -1 (not valid)
            return 0;
        }
        
        if(dp[required_length] != -1) return dp[required_length] % MOD;


        int append_zeros = f(required_length - zeros , zeros , ones, dp) % MOD;
        int append_ones = f(required_length - ones , zeros, ones ,dp) % MOD;


        return dp[required_length] = ( append_zeros + append_ones )% MOD;


    }

    int countGoodStrings(int low, int high, int zero, int one) {
        

        int ans = 0;
        vector<long long>dp (high + 1 , -1);
        dp[0] = 1;
        for(int size = low ; size <= high ; size++)
        {
            
            ans += f(size , zero , one,dp);
            ans %= MOD;
        }
        return ans;
    }
};