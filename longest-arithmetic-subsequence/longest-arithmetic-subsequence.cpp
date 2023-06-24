class Solution {

private:
    // ind -- diff --> no of elements
    map<pair<int , int> , int> mp;
    int f(int ind , int diff , vector<int>& nums)
    {
        if(ind < 0)
        {
            return 0;
        }
        
        if(mp.find({ind , diff}) != mp.end())
        {
            return mp[{ind , diff}];
        }
        
        int ans = 0;
        
        for(int j = ind - 1 ; j >= 0 ; j--)
        {
            if(nums[ind] - nums[j] == diff)
            {
                ans = max(ans , 1 + f(j , nums[ind] - nums[j] ,nums));
            }
        }
        
        return mp[{ind , diff}] = ans;
    }
public:
    int longestArithSeqLength(vector<int>& nums) {
        
        int n = nums.size();
        if(n <= 2)
        {
            return n;
        }
        
        
        int ans = 0;
        //Two states -> Ind and Diff
        //dp[i][diff] -> represents till the ith index how many elements are there in the AP with CD=diff
        
        unordered_map<int , int> dp[n + 1];
        
        for(int i = 1 ; i < n ; i++)
        {
            for(int j = 0; j < i ; j++)
            {
                int diff = nums[i] - nums[j];
                int cnt = 1;

                if(dp[j].count(diff))
                {
                    cnt = dp[j][diff];
                }
                
                dp[i][diff] = 1 + cnt;
                ans = max(ans , dp[i][diff]);
            }
        }
        
        return ans;
    }
};