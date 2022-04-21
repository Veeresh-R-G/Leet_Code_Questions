#include <bits/stdc++.h>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
     
        vector<int> v;
        int s = nums.size();
        for(int i = 0 ; i < s ; i++)
        {
            
            for(int j = i + 1 ; j < s ; j++)
            {
                if(nums[i] + nums[j] == target)
                {
                    v.push_back(i);
                    v.push_back(j);
                    return v;
                    
                }
            }
        }
      
        return {};
    }
};