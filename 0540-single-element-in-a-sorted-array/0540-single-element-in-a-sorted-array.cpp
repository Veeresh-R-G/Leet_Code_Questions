class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int N = nums.size();
        nums.push_back(-1);
        int s = 0;
        int e = N - 1;
        
        for (int i = 0 ; i < N ; i = i + 2)
        {
            if(nums[i] != nums[i + 1])
            {
                return nums[i];
            }
        }
        
        
        return 0;
        
    }
};