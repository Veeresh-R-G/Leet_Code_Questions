class Solution {
public:
    
    int f(string word1 , string word2 , int i , int j , vector<vector<int>>& dp)
    {
        //Word2 still left so put that mnay insertions
        if(i == 0 && j > 0) return j;
        
        if(i == 0 && j == 0) return 0;
        
        //Word1 has some extra characters to delete that many from word1
        if(i > 0 && j == 0) return i;
        
        if(dp[i - 1][j - 1] != -1)
        {
            return dp[i - 1][j - 1];
        }
        if(word1[i - 1] == word2[j - 1])
        {
            return dp[i - 1][j - 1] = f(word1 , word2 , i - 1 , j - 1 , dp);
        }
        int insert = 1 + f(word1 , word2 , i , j - 1 , dp);
        int del = 1 + f(word1 , word2 , i - 1 , j , dp);
        int rep = 1 + f(word1 , word2 , i - 1 , j - 1 , dp);
        
        return dp[i - 1][j - 1] = min(insert , min(del , rep));
    }
    
    int minDistance(string word1, string word2) {
        
        int N = word1.size() ,M = word2.size();
        int ind1 = N , ind2 = M;
        vector<vector<int>> dp(N + 1 , vector<int>(M + 1 , -1));
        return f(word1 , word2 , ind1 , ind2 , dp);
    }
};