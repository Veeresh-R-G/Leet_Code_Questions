class Solution {
public:
    
    
    int solve(vector<vector<int>>& mat , int n , int m , int s1 , int s2 , vector<vector<int>>& dp)
    {
        if(s1 == n && s2 == m && mat[s1][s2] != 1)
        {
            return 1;
        }
        
        if(s1 > n || s2 > m || mat[s1][s2] == 1)
        {
            return 0;
        }
        
        if(dp[s1][s2] != -1)
        {
            return dp[s1][s2];
        }
        int down = solve(mat , n , m , s1 + 1 , s2 , dp);
        int right = solve(mat , n , m , s1 , s2 + 1 , dp);
        
        return dp[s1][s2] = down + right;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        
        /*
            
            Obstacle --> 1 
            Space --> 0
            
        */
        
        // vector<vector<int>> dp(row , vector<int>(cols,-1));
        int row = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> dp(row , vector<int>(cols,-1));
        return solve(mat , row - 1, cols - 1 , 0 , 0 , dp);
  }
};