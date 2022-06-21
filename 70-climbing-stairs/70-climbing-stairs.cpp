class Solution {
public:
    
    /*
    
        Ok this is a DP problem
        
    */
    
    //recursive
    int ways(int n)
    {
        if(n == 1) return 1;
        if(n == 0) return 1;
        
        int one = ways(n -1);
        int two = ways(n - 2);
        
        return one + two;
        
    }
    
    
    //Memoization
    int ways_memo(int n , vector<int>& dp)
    {
        if(n == 0) return 1;
        if(n == 1) return 1;
        
        if(dp[n] != -1)
        {
            return dp[n];
        }
        
        else
        {
            return dp[n] = ways_memo(n - 1 , dp) + ways_memo(n - 2 , dp);
        }
    }
    
    int climbStairs(int n) {
    
        vector<int> dp(n + 1 , -1);
        return ways_memo(n , dp);
        // return ways(n);
        
    }
};