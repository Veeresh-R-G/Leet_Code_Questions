
class Solution {
public:
    
    int f(string& s, string& t , int n , int m ,vector<vector<int>>& dp)
    {
        if(m == 0) return 1;
        
        if(n == 0) return 0;
        
        if(dp[n][m] != -1) return dp[n][m];
        
        if(s[n - 1] == t[m - 1])
        {
            return dp[n][m] = f(s  ,t , n - 1 , m - 1 , dp) + f(s , t , n - 1 , m , dp);
        }
        
        return dp[n][m] = f(s , t , n - 1 , m , dp);
    }
    
    int numDistinct(string s, string t) {
        
        vector<vector<int>> dp(s.length() + 1 , vector<int>(t.length() + 1   , -1));
        int n = s.length();
        int m = t.length();
        

        return f(s , t , s.length()  , t.size(), dp);
        
    }
};