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
        
        
        vector<vector<int>> dp(N , vector<int> (M , 0));
        
        //Base Case
        dp[0][0] = grid[0][0];
        
        for(int row = 0 ; row < N ; row++)
        {
            for(int col = 0 ; col < M ; col++)
            {
                if(row == 0 && col == 0)
                {
                    continue;
                }
                int up = row >= 1 ? grid[row][col] + dp[row - 1][col] : 1e7;
                int left = col >= 1 ? grid[row][col] + dp[row][col - 1] : 1e7;
        
                dp[row][col] = min(up , left);
                
            }
        }
        
        return dp[N - 1][M - 1];
        
        
    }
};