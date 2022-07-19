class Solution {
public:
    
    
    
    //Recursion
    int solve(string& s , string& t , int i , int j,vector<vector<int>>& dp)
    {
        //Base-Cases
        if(i == 0 && j == 0) return 0;
        
        if(i == 0 && j > 0) return j ; //Insertions
        
        if(j == 0 && i > 0) return i ; // Deletions
        
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i - 1] == t[j - 1])
        {
            return dp[i][j] =solve(s, t , i - 1 , j - 1 , dp);
        }
        
        int insert = 1 + solve(s , t , i , j - 1 , dp);
        int delete_ = 1 + solve(s , t , i - 1 , j , dp);
        int replace = 1 + solve(s , t , i - 1, j - 1 , dp);
        
        return dp[i][j] = min(insert , min(delete_ , replace));
    }
    
    int minDistance(string word1, string word2) {
            
        
        int n = word1.size();
        int m = word2.size();
        
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1 , -1));
        
        
        //Tabulation
        vector<vector<int>> dp2( n + 1 , vector<int>(m + 1 , 0));
        
        dp2[0][0] = 0;
        //Base Cases
        for(int i = 0 ; i<=n ; i++)  dp2[i][0] = i;
        
        
        for(int i = 0 ; i <=m ; i++) dp2[0][i] = i;
        
        
        for(int i = 1; i <= n ; i++)
        {
            for(int j = 1 ; j <= m ; j++)
            {
                if(word1[i - 1] == word2[j - 1])
                {
                    dp2[i][j] = dp2[i - 1][j - 1];
                }
        
                else
                {
                     int insert = 1 + dp2[i][ j - 1];
                    int delete_ = 1 + dp2[i - 1][ j ];
                    int replace = 1 + dp2[i - 1][j - 1];

                    dp2[i][j] = min(insert , min(delete_ , replace));
                }
               
            }
        }
        
        return dp2[n][m];
        // return solve(word1 , word2 , n ,  m , dp);
    }
};