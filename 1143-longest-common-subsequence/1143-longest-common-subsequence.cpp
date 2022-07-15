class Solution {
public:
    
    int f(string s , string t , int i , int j, vector<vector<int>>& dp)
    {
        if(i == 0 || j == 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i - 1] == t[j - 1])
        {
            return dp[i][j] = 1 + f(s , t , i - 1 , j - 1 , dp);
        }
        
        return dp[i][j] = max(f(s , t , i - 1 , j , dp) , f(s , t , i , j - 1 , dp));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
            
        if(text1 == "" || text2 == "")
        {
            return 0;
        }
        
        int n = text1.length();
        int m = text2.length();
        
        vector<vector<int>> dp(n + 1 , vector<int>(m + 1 , 0));
        
        for(int i = 1 ; i <= n ;i++)
        {
            for(int j = 1 ; j <= m ;j++)
            {
                if(i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                
                if(text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                
                else
                {
                    dp[i][j] = max(dp[i -1][j] , dp[i][j - 1]);
                }
            }
        }
        
        return dp[n][m];
        return f(text1 , text2 , n , m ,dp);
    }
};