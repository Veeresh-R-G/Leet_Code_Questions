class Solution {
public:
    
    int f(vector<int>& nums1, vector<int>& nums2 ,int ind1 , int ind2, vector<vector<int>>& dp)
    {
        if(ind1 == 0 || ind2 == 0)
        {
            return 0;
        }
        
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        
        if(nums1[ind1 - 1] == nums2[ind2 - 1])
        {
            return dp[ind1][ind2] = 1 + f(nums1 , nums2 , ind1 - 1 , ind2 - 1,dp);
        }
        
        return dp[ind1][ind2] = max(f(nums1 , nums2 , ind1 - 1 , ind2,dp) , f(nums1 , nums2 , ind1 , ind2 - 1,dp));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        
       
        int N = nums1.size();
        int M = nums2.size();
        
        vector<vector<int>> dp(N + 1 , vector<int>(M + 1 , -1));
        
        return f(nums1 , nums2 , N , M , dp);
    }
};