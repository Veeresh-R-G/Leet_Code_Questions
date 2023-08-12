class Solution {

private:
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& grid , int row , int col , int n ,int m){
        if(row < 0 || row >= n || col < 0 || col >= m || grid[row][col] == 1){
            return 0;
        }

        if(row == n - 1 && col == m - 1){
            return 1;
        }
        if(dp[row][col] != -1){
            return dp[row][col];
        }

        int down = solve(grid , row + 1 , col , n , m);
        int right = solve(grid , row , col + 1 , n , m);

        return dp[row][col] = down + right;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
       
        dp.resize(n , vector<int>( m , -1));
        return solve(grid , 0 , 0, n , m);
    }
};