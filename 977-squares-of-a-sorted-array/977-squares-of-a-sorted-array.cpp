class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        vector<int> ans;
        
        for(int i = nums.size() - 1 ; i >= 0 ; i--)
        {
            ans.push_back(nums[i] * nums[i]);
        }
        
         sort(ans.begin(), ans.end());
        return ans;
    }
};