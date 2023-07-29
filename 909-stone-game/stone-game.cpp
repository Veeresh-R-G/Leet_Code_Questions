class Solution {

private:

    int solve(vector<int>&piles , int l , int r ,vector<vector<int>>& dp){
        if(l == r){
            return piles[l];
        }

        if(l > r){
            return 0;
        }
        
        if(dp[l][r] != -1){
            return dp[l][r];
        }

        int first = piles[l] + min(solve(piles, l + 2 , r,dp) , solve(piles , l + 1 , r - 1,dp));
        int last = piles[r] + min(solve(piles, l + 1 , r - 1,dp) , solve(piles, l , r - 2,dp));

        return dp[l][r] = max(first , last);

    }
public:
    bool stoneGame(vector<int>& piles) {
        
        int sum = 0;

        for(auto it : piles){
            sum += it;
        }

        sum = sum / 2;

        int l = 0;
        int r = piles.size() - 1;
        vector<vector<int>> dp(piles.size() , vector<int>(piles.size() , -1));
        int alice = solve(piles , l , r , dp);
        
        cout << alice << endl;
        if(alice >= sum){
            return true;
        }
        
        return false;
    }
};