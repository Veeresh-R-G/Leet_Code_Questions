class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int one = 0;
        int two = 0;

        for(auto it : nums)
        {
            one = (one ^ it) & (~two);
            two = (two ^ it) & (~one);
        }
        
        return one;
        
    }
};