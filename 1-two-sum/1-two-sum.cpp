#include <bits/stdc++.h>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        
        //Optimised Approach is usage of hashMap
        unordered_map<int, int> myMap;
        
        int temp;
        vector<int> ans;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            int curr = nums[i];
            temp = target - curr;
            
            if(myMap.find(temp) == myMap.end()){
                myMap[curr] = i;
            }
            else
            {
                ans.push_back(i);
                ans.push_back(myMap[temp]);
                break;
            }
        }
        
        return ans;
    }
};