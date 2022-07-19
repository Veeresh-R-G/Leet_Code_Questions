class Solution {
public:
    
    int f(int i , int j , vector<vector<int>>& dp)
    {
        if(i == j) return 1;
        
        if(i == 0 || j == 0) return 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        else return dp[i][j] = f(i - 1 , j - 1 , dp) + f(i - 1 , j , dp);
            
    }
    
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans = {};
        vector<vector<int>> dp(numRows , vector<int>(numRows , -1));
        for(int i = 0 ;i < numRows ; i++)
        {
            vector<int> curr(i + 1 , 0);
            for(int j = 0 ; j <= i ; j++)
            {
                curr[j] = f(i , j , dp);
            }
            ans.push_back(curr);
        }
        
        
        return ans;
        
    }
};