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
        
    
    int uniquePaths(int m, int n) {
        
        // int ans = recursion_(m -1 , n - 1);
        vector<vector<int>> dp(m , vector<int>(n , -1));
        int ans = memoIzation(m - 1, n - 1,dp);
        return ans;
    }
};