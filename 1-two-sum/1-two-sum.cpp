#include <bits/stdc++.h>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
         /*
            BRUTE FORCE : 
            Time complexity : O(n*n)
            Space Complexity : O(n)
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
            
        */
        
        
        //Optimised Approach is usage of hashMap
        /*
        
        Time complexity : O(n)
        Space Complexity : O(n)
        
        */
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