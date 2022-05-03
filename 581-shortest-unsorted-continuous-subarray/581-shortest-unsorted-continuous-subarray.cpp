class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
            
        if(nums.size() == 0 || nums.size() == 1)
        {
            return 0;
        }
        
        /*
        
            time = O(n)
            Space = O(n)
        */
        vector<int> temp = nums;
        
        sort(temp.begin() , temp.end());
        
        int n = temp.size() ;
        
        int start = 0;
        
        while(start < n)
        {
            if(temp[start] == nums[start])
            {
                start++;
            }
            else{
                break;
            }
            
        }
        
        int end = n - 1;
        while(end >= 0)
        {
            if(temp[end] == nums[end])
            {
                end--;
            }
            else
            {
                break;
            }
        }
        
        if(start == n - 1 || end == -1)
        {
            return 0;
        }
        
        return end - start + 1;
    }
        
};