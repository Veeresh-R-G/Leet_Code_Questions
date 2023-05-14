class Solution {
public:
    int backtrack(vector<int>& nums, int mask, int pairsPicked, vector<int>& dp) {
  
        if (2 * pairsPicked == nums.size()) {
            return 0;
        }

        
        if (dp[mask] != -1) {
            return dp[mask];
        }

        int maxScore = 0;

 
        for (int firstIndex = 0; firstIndex < nums.size(); ++firstIndex) {
            for (int secondIndex = firstIndex + 1; secondIndex < nums.size(); ++secondIndex) {
    
    
                if (((mask >> firstIndex) & 1) == 1 or ((mask >> secondIndex) & 1) == 1) {
                    continue;
                }

                
                int newMask = mask | (1 << firstIndex) | ((1 << secondIndex));

               
                int currScore = (pairsPicked + 1) * __gcd(nums[firstIndex], nums[secondIndex]);
                int remainingScore = backtrack(nums, newMask, pairsPicked + 1, dp);

                // Store the maximum score.
                maxScore = max(maxScore, currScore + remainingScore);
                
            }
        }

       
        dp[mask] = maxScore;
        return maxScore;
    }

    int maxScore(vector<int>& nums) {
        int dpSize = 1 << nums.size(); 
        vector<int> dp(dpSize, -1);
        return backtrack(nums, 0, 0, dp);
    }
};