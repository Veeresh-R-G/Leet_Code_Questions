class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        

        int currSum = 0;
        int ans = INT_MAX;
        int left = 0;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            int right = i;
            currSum += nums[right];

            while(currSum >= target)
            {
                ans = min(ans, right - left + 1);
                currSum -= nums[left];
                left++;
            }

        }

        return ans == INT_MAX ? 0 : ans;
    }
};