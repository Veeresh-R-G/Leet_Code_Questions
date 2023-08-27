class Solution {

private:
    map<int , int> mp;
    vector<vector<int>>dp;
    bool solve(vector<int>&stones ,int ind , int prevJump){

        if(ind >= stones.size()){
            return false;
        }

        if(ind == stones.size() - 1){
            return true;
        }

        if(dp[ind][prevJump] != -1){
            return dp[ind][prevJump];
        }
        bool ans = false;
        for(int i = -1 ; i <= 1 ; i++){
            if(prevJump + i > 0 && mp.find(stones[ind] + prevJump + i) != mp.end())
              ans = ans || solve(stones , mp[stones[ind] + prevJump + i] , prevJump + i);
        }

        return dp[ind][prevJump] = ans;
    }
public:
    bool canCross(vector<int>& stones) {
        
        int ind = 0;
        int i = 0;
        for(auto it : stones){
            mp[it] = i;
            i++;

        }

        dp.resize(2001 , vector<int>(2000 , -1));
        return solve(stones , ind , 0);
    }
};