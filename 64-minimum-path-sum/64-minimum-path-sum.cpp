class Solution {
public:
    int solve(vector<vector<int>>& grid , int row , int col, vector<vector<int>>& dp )
    {
        if(row == 0 && col == 0)
        {
            return grid[row][col];
        }
        
        
        if(row < 0 || col < 0)
        {
            return 1e7; 
        }
        if(dp[row][col] != -1) return dp[row][col];
        int up = grid[row][col] + solve(grid , row - 1 , col , dp);
        int left = grid[row][col] + solve(grid , row , col - 1 ,dp);
        
        return dp[row][col] = min(up , left);
            
    }
    
    
    int minPathSum(vector<vector<int>>& grid) {
        
        int N = grid.size();
        int M = grid[0].size();
        
        
        vector<vector<int>> dp(N , vector<int> (M , -1));
        return solve(grid , N - 1 , M - 1 , dp);
        
    }
};