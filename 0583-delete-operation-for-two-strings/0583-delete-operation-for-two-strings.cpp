class Solution {
public:
    
    int f(string word1 , string word2 , int i , int j ,vector<vector<int>>& dp)
    {
        //Word1 has some extra stuufs so delete maadi
        if(i > 0 && j == 0) return i;
        
        //Word2 has some extra stuffs so delete illi kuda
        if(i == 0 && j > 0) return j;
        
        //No extra stuffs in both so no extra ops required
        if(i == 0 && j == 0) return 0;
        
        if(dp[i - 1][j - 1] != -1)
        {
            return dp[i - 1][j - 1];
        }
        if(word1[i - 1] == word2[j - 1])
        {
            return dp[i - 1][j - 1] = f(word1 , word2 , i - 1 , j - 1 , dp);
        }
        
        //Delete in first word
        int firstWord = 1 + f(word1 , word2 , i - 1 , j , dp);
        
        //Delete in second word
        int secondWord = 1 + f(word1 , word2 , i , j - 1 , dp);
        
        return dp[i - 1][j - 1] = min(firstWord , secondWord);
    }
    int minDistance(string word1, string word2) {
        
        vector<vector<int>> dp(word1.size() + 1 , vector<int>(word2.size() + 1 , -1));
        return f(word1 , word2 , word1.size() , word2.size() , dp);
    }
};