class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int s = 0;
        int lSum = 0;
        
        for(auto it : nums)
        {
            s += it;
        }
        
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(lSum == s - nums[i] - lSum) return i;
            lSum += nums[i];
        }
        
        return -1;
    }
};