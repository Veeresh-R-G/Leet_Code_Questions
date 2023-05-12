class Solution {
public:
    
    long long f(vector<vector<int>>& questions , int ind ,int N,vector<long long>& dp)
    {
        if(ind >= N)
        {
            return 0;
        }
        
        if(dp[ind] != -1) return dp[ind];
        
        long long pick = questions[ind][0] + f(questions , ind + questions[ind][1] + 1 , N,dp);
        long long notPick = f(questions,ind + 1 , N,dp);
        
        return dp[ind] = max(pick , notPick);
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
        
        int N = questions.size();
        vector<long long> dp(N + 1 , -1);
        return f(questions , 0 , N , dp);
    }
};