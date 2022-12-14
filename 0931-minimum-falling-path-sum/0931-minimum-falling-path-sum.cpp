class Solution {
public:
    
    
    int f(vector<vector<int>>& matrix , int row , int col , int rowLim , int colLim ,vector<vector<int>>& dp)
    {
        if(col >= colLim || col < 0)
        {
            return 1e7;
        }
        
        if(row == rowLim - 1)
        {
            return matrix[row][col];
        }
        if(dp[row][col] != -1) return dp[row][col];
        int down = f(matrix , row + 1 , col , rowLim , colLim , dp);
        int left = f(matrix , row + 1 , col - 1 , rowLim , colLim , dp);
        int right = f(matrix , row + 1 , col + 1 , rowLim , colLim , dp);
     
        return dp[row][col] = matrix[row][col] + min(down , min(left , right));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        
        
        int rowLim = matrix.size() , colLim = matrix[0].size();
        int row = 0;
        int col = 0;
        int ans = INT_MAX;
        
        vector<vector<int>> dp(rowLim , vector<int>(colLim , -1));
        for(int j = 0 ; j < colLim ; j++)
        {
            ans = min(ans , f(matrix , 0 , j , rowLim , colLim , dp));
        }
        
        return ans;
    }
};