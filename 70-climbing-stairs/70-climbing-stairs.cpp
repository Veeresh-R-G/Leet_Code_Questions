class Solution {
public:
    
    int f(int n , vector<int>& dp)
    {
        if(n == 0) 
        {
            return 1;
        }
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = f(n -1 , dp) + f(n - 2 , dp); 
    }
    int climbStairs(int n) {
        
        vector<int> dp( n + 1 , 0);
        
        dp[0] = 1;
        
        for(int i = 1 ; i <= n ; i++)
        {
            int one = i >= 1 ? dp[i - 1] :0;
            
            int two = i >= 2 ? dp[i - 2] :0;
            
            dp[i] = one + two;
        }
        
        return dp[n];
        // return f(n , dp);
    }
};