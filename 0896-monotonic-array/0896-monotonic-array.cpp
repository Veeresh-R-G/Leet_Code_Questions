class Solution {
public:
    
    int myCompare(int a , int b)
    {
        return a > b ? 1 : -1;
    }
    bool isMonotonic(vector<int>& nums) {
        
        if(nums.size() == 1)
        {
            return true;
        }
        
        int c = nums[1] - nums[0];
        
        int store = 0;
        for(int i = 0 ; i < nums.size() - 1 ; i++)
        {
            if(nums[i] == nums[i + 1]) continue;
            
            int c = myCompare(nums[i] , nums[i + 1]);
            
            if(c != store && store != 0)
            {
                return false;
            }
            
            store = c;
            
        }
        
        return true;
        
    }
};