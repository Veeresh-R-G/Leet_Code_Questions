class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        
        /*
        
        Time Complexity : O(n)
        Space Complexity : O(1) 
        Constant !!!!
        
        */
        if(nums.size() <= 1)
        {
            return nums;
        }
        int s = 0;
        int e = nums.size() - 1;
        
        int temp;
        while(s < e)
        {
            int beg = nums[s];
            int end = nums[e];
            
            if(beg % 2 != 0 && end % 2 == 0)
            {
                temp = nums[s];
                nums[s] = nums[e];
                nums[e] = temp;
                s++;
                e--;
            }
            else if(beg % 2 == 0)
            {
                s++;
            }
            else
            {
                e--;
            }
            
        }
        
        return nums;
    }
};