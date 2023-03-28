class Solution {
public:
    
    
    int f(int row , int col , int rowLim , int colLim ,vector<vector<int>>& grid,
         vector<vector<int>>& dp)
    {
        
        if(row == rowLim - 1 && col == colLim - 1)
        {
            return grid[row][col];
        }
        if(row >= rowLim || col >= colLim)
        {
            return 1e7;
        }
        
        
        if(dp[row][col] != -1) 
        {
            return dp[row][col];
        }
        
        
        
        int down = grid[row][col] + f(row + 1,  col , rowLim , colLim , grid , dp);
        int right = grid[row][col] + f(row , col + 1 , rowLim , colLim , grid , dp);
        
        return dp[row][col] = min(down , right);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m + 1 , vector<int>(n + 1 , -1));
        return f(0 , 0 , m , n , grid , dp);
    }
};