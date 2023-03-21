class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        
        long long ans = 0;
        
        long long i = 0;
        long long  zeros = 0;
        
        /*
        
            1 --> 1
            2 --> 1 + 1 + 2  = 3
            3 --> 1 + 1 + 1 + 2 + 2 + 3 
        
        */
        while(i < nums.size())
        {
            
            if(nums[i] == 0) zeros++;
            else zeros = 0;
            
            ans += zeros;
            i++;
        }
        
        
        
        return ans;
        
    }
};