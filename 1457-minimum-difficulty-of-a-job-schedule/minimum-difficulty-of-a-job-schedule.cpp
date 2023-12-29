class Solution {

private:

    vector<vector<int>> dp;
    int helper(vector<int>& temp, int d, int i){
        if(d == 1){
            int ans = 0;
            for(int j = i; j < temp.size(); j++){
                ans = max(ans, temp[j]);
            }

            return ans;
        }

        if(dp[i][d] != -1){
            return dp[i][d];
        }
        int ans = INT_MAX;
        int maxi = 0;

        for(int j = i; j <= temp.size() - d; j++){

            maxi = max(maxi, temp[j]);
            ans = min(ans, maxi + helper(temp, d - 1, j + 1));
        }

        return dp[i][d] = ans;


    }
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        
        int n = jobDifficulty.size();
        dp.resize(n, vector<int>(d + 1, -1));

        if(n / d == 0){
            return -1;
        }

        return helper(jobDifficulty, d, 0);


    }
};