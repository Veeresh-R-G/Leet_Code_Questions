class Solution {
public:
    /*
        concept is about 3D Dp
        
        and saving the third parameter as [sum % k] 
    */
    int MOD = 1e9 + 7;
    
    int f(vector<vector<int>>& grid, int k , int row , int col , int rowLim , int colLim,
         int total , vector<vector<vector<int>>>& dp)
    {
        
        if(row >= rowLim || col >= colLim)
        {
            return 0;
        }
        if(row == rowLim - 1 && col == colLim - 1)
        {
            return (grid[row][col] + total) % k == 0;
        }
        
        
        if(dp[row][col][total % k] != -1) return dp[row][col][total % k];
        
        // total += grid[row][col];
        
        int right = f(grid , k , row  , col + 1 , rowLim , colLim ,total + grid[row][col] , dp) % MOD;
        int down = f(grid , k , row + 1 , col , rowLim , colLim , total + grid[row][col]  , dp) % MOD;
        
        return dp[row][col][total % k] = ((right % MOD) + (down % MOD)) % MOD;
        
        
    }
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
                
        
        int m = grid.size();
        int n = grid[0].size();
        int total = 0;
        
        vector<vector<vector<int>>> dp(m + 1 , vector<vector<int>>(n + 1 , vector<int>(k , -1)));
        
        return f(grid , k , 0 , 0 , m , n , total , dp); 
    }
};