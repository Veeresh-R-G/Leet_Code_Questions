class Solution {
public:
    int solve(vector<vector<int>>& grid , int row , int col,vector<vector<int>>& dp)
    {
        //Base Case 
        if(row == grid.size() - 1)
        {
            return grid[row][col];
        }
        if(row >= grid.size())
        {
            return 0;
        }
        if(dp[row][col] != -1)
        {
            return dp[row][col];
        }
        int down = grid[row][col] + solve(grid , row + 1 , col,dp);
        int leftDiag =grid[row][col] + solve(grid , row + 1 , col + 1 , dp);
        
        return dp[row][col] = min(down , leftDiag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        
        
        int N = triangle.size();
        vector<vector<int>> dp(N , vector<int>(N , -1));
        return solve(triangle , 0 , 0 , dp);
    }
};