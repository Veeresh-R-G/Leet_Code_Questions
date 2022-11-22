#include <cmath>
class Solution {
public:
    
    int helper(int n ,  vector<int>& dp)
    {
        //Base Case
        if(n == 0)
        {
            return 0;
        }
        
        if(dp[n] != -1) return dp[n];
        int nearest_Sq = sqrt(n);
        
        /*
            n = 12
            
            nearest = sqrt(12) = 3.smthg == 3
            
            
            i = 1
            1 + helper(12 - 1) ----> i = 1 to 3 
                                    
        
        */
        int mini = 1e9;
        for(int i = 1 ; i <= nearest_Sq ; i++)
        {
            int steps = 1 + helper(n - (i * i) , dp);
            mini = min(steps , mini);
        }
        
        return dp[n] = mini;
    }
    int numSquares(int n) {
        
        vector<int>dp(n + 1 , - 1);
        return helper(n , dp);
    }
};