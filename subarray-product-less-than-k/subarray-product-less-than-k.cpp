class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        if(k < 1)
        {
            return 0;
        }
        int ans = 0;


        int left = 0 , right = 0;
        int currSum = 1;


        for(right = 0 ; right < nums.size() ; right++)
        {
            currSum *= nums[right];

            while(currSum >= k)
            {
                if(left >= nums.size()) break;
                currSum /= nums[left];
                left++;
            }
            ans += (right - left + 1);
        }


        return ans <= 0 ?  0 : ans;
    }
};