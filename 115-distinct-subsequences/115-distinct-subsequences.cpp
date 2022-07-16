
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
        
        /*
            Double is used to handle overflow issues 
        */
        vector<vector<double>> dp(s.length() + 1 , vector<double>(t.length() + 1   , -1));
        int n = s.length();
        int m = t.length();
        
        vector<double> prev( m + 1 , 0) , curr( m + 1 , 0);
        // for(int i = 0 ; i <= n ; i++) dp[i][0] = 1;
        // for(int j = 1 ; j <= m ; j++) prev[j] = 0;
           prev[0] = curr[0]= 1;
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1; j<=m ; j++)
            {
                if(s[i - 1] == t[j - 1]) curr[j] = prev[j - 1] + prev[j];
                
                else curr[j] = prev[j];
            }
            
            prev = curr;
        }
        
        return (int)prev[m];
        // return f(s , t , s.length()  , t.size(), dp);
        
    }
};