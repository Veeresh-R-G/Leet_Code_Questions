class Solution {

private:
    int MOD = 1e9 + 7;
    
    int solve(vector<int>& locations, int ind , int finish, int fuel,vector<vector<int>>& dp)
    {
        if(ind >= locations.size() || fuel < 0)
        {
            return 0;
        }

        if(dp[ind][fuel] != -1)
        {
            return dp[ind][fuel];
        }
        int ans = ind == finish ? 1 : 0;
        for(int i = 0 ;i < locations.size() ; i++)
        {
            if(i != ind)
            {
                ans = (ans % MOD + (solve(locations , i, finish , fuel - abs(locations[i] - locations[ind]) , dp)) % MOD) % MOD;
            }
        }

        return dp[ind][fuel] = ans;


    }
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        
        // All possible routes --> try out all the paths --> Recursion --> DP \U0001f680

        //states -> Fuel / ind
        int N = locations.size();

        vector<vector<int>> dp(N , vector<int>(fuel + 1 , -1));
        int ans = solve(locations , start , finish , fuel , dp) % MOD;
        return  ans % MOD;

        
    }
};