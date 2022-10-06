class Solution {
public:
    
    int f(vector<vector<int>>& triangle , int ind , int col , int rows,vector<vector<int>>& dp)
    {
        if(ind >= rows) return 0;
        
        
        if(dp[ind][col] != -1) return dp[ind][col];
        int down = triangle[ind][col] + f(triangle , ind + 1 , col , rows , dp);
        int right = triangle[ind][col] + f(triangle , ind + 1 , col + 1 , rows , dp);
        
        return dp[ind][col] = min(down , right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        /*
            Changing params --> ind && col
        */
        vector<vector<int>> dp(n + 1 , vector<int>(n + 1 , -1));
        return f(triangle , 0 , 0 ,n , dp);
    }
};