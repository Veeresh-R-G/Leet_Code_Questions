#include <bits/stdc++.h>
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        long long cnt = 0;
        
        //leftBound --> to calculate the number of subarrays till the current index
        long long minPosi = -1 , maxPosi = -1 , leftBound = -1;
        
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(nums[i] < minK || nums[i] > maxK)
            {
                leftBound = i;
            }
            
            if(nums[i] == minK)
            {
                minPosi = i;
            }
            
            if(nums[i] == maxK)
            {
                maxPosi = i;
            }
            
            cnt += max(1ll* 0 , min(maxPosi , minPosi) - leftBound);
            
        }
        
        
        
        
        return cnt;
    }
};