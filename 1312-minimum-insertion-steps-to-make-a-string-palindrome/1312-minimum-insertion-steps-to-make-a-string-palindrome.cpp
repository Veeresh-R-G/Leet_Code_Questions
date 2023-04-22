class Solution {
public:
    int minInsertions(string s) {
        
        
        //Longest palindrome question variant
        //OP
        
        string t = "";
        for(auto it : s)
        {
            t = it + t;
        }
        int N = s.size();
        
        
        vector<vector<int>> dp(N + 1 , vector<int>(N + 1 , 0));
        for(int i = 0 ; i <= N ; i++)
        {
            for(int j = 0 ; j <= N ; j++)
            {
                if(i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                
                else if(s[i - 1] == t[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
                }
            }
            
            
        }
        
        return N - dp[N][N];
    }
    
};