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
            
            zeros = 0;
            while(i < nums.size() && nums[i++] == 0)
            {
                zeros++;
            }
            
            ans += (zeros * (zeros + 1)) / 2;
            
        }
        
        
        
        return ans;
        
    }
};