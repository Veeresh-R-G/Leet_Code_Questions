class Solution {


private:
   
    int f(int ind , vector<int>&rods , vector<vector<int>>&dp , int diff)
    {
        if(ind == rods.size())
        {
            return diff == 0 ? 0 : INT_MIN;
        }

        if(dp[ind][diff + 5000] != -1)
        {
            return dp[ind][diff + 5000];
        }

        int notPick = f(ind + 1 , rods,dp, diff);
        int pickInS1 = rods[ind] + f(ind + 1 , rods,dp ,diff + rods[ind]);
        //Not including again,because it will get counted twice
        int pickInS2 = f(ind + 1 , rods,dp , diff - rods[ind]);

        return dp[ind][diff + 5000] = max(notPick , max(pickInS1 , pickInS2));
    }
public:
    int tallestBillboard(vector<int>& rods) {
        
        //3 state changes : ind , s1 , s2
        vector<vector<int>>dp (21 , vector<int>(2 * 5000 + 1 , -1));
        int diff = 0;

        return f(0 ,rods,dp,diff);
    }
};