class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        
        if( k == 0)
        {
            return nums1 == nums2 ? 0: -1*1ll;
        }
        
        long long ans = 0;
        
        long long sum = 0;
        int N = nums1.size();
        for(auto i  = 0 ; i < N ; i++)
        {
            int diff = nums1[i] - nums2[i];
            
            if(diff % k != 0) return -1;
            
            diff = diff / k;
            sum += diff;
            if(diff > 0)
            {
                ans += diff;
            }
        }
        
        
        return sum == 0 ? ans :-1;
    }
};