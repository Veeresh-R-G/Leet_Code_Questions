class Solution {
public:
    
    int recursion_(int row , int col)
    {
        if(row == 0 && col == 0)
        {
            return 1;
        }
        
        if(row < 0 || col < 0)
        {
            return 0;
        }
        
        int up = recursion_(row - 1 , col);
        int left = recursion_(row , col - 1);
        
        return up + left;
    }
    
    int memoIzation(int row , int col , vector<vector<int>>& dp)
    {
        if(row == 0 && col == 0)
        {
            return 1;
        }
        
        
        if(row < 0 || col < 0)
        {
            return 0;
        }
        
        if(dp[row][col] != -1)
        {
            return dp[row][col];
        }
        
        int up = memoIzation(row - 1 , col , dp);
        int left = memoIzation(row , col - 1 , dp);
        
        return dp[row][col] = up + left;
    }    
        
    int tabulation(int m, int n)
    {
        vector<vector<int>> dp(m , vector<int>(n , 0));
        //Base Case
        dp[0][0] = 1;
        
        for(int row = 0 ; row < m ; row++)
        {
            for(int col = 0 ; col < n ; col++)
            {
                
                if(row == 0 && col == 0)
                {
                    dp[0][0] = 1;
                    continue;
                }
                    int up = row > 0 ? dp[row - 1][col] : 0;
                    int left = col > 0 ? dp[row][col - 1] : 0;
                
                    dp[row][col] =  up + left;                
            }
        }
        
        return dp[m - 1][n - 1];
        
    }
    
    int spaceOptimisation(int m , int n)
    {
        vector<int> prev(n , 1);
        //Base Case
        prev[0] = 1;
        
        for(int row = 0 ; row < m ; row++)
        {
            vector<int> curr(n , 0);
            for(int col = 0 ; col < n ; col++)
            {
                
//                 if(row == 0 && col >= 0)
//                 {
//                     curr[col] = prev[col - 1];
//                 }
                
//                 if(col == 0 && row >= 0)
//                 {
//                     curr[col] = 1;    
//                 }
                
//                 else
//                 {
//                     curr[col] = prev[col] + curr[col - 1];
//                 }
                if(row == 0 && col == 0)
                {
                      curr[col]   = 1;
                    continue;
                }
                    int up = row > 0 ? prev[col] : 0;
                    int left = col > 0 ? curr[col - 1] : 0;
                
                    curr[col] =  up + left;    
                              
            }
            prev = curr;
        }
        
        return prev[n - 1];
    }
    int uniquePaths(int m, int n) {
        
        // int ans = recursion_(m -1 , n - 1);
        
        // vector<vector<int>> dp(m , vector<int>(n , -1));
        // int ans = memoIzation(m - 1, n - 1,dp);
        
        int ans = spaceOptimisation(m, n);
        return ans;
    }
};