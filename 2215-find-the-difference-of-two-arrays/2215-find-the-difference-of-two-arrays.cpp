class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        map<int , int> nums1_map;
        map<int , int> nums2_map;
        
        vector<vector<int>> ans;
        
        
        //counters
        set<int> nums1_not_in_nums2;
        set<int> nums2_not_in_nums1;
        
        for(auto it : nums1)
        {
            nums1_map[it]++;
        }
        
        //map for first array is ready so can check here only
        for(auto it : nums2)
        {
            if(nums1_map.find(it) == nums1_map.end())
            {
                //There in nums2 but not in nums1
                nums2_not_in_nums1.insert(it);
            }
            nums2_map[it]++;
        }
        
        for(auto it : nums1)
        {
            if(nums2_map.find(it) == nums2_map.end())
            {
                //There in nums1 but not in nums2
                nums1_not_in_nums2.insert(it);
            }
        }
        
        vector<int> temp;
        for(auto it :nums1_not_in_nums2)
        {
            temp.push_back(it);
        }
        ans.push_back(temp);
        
        temp.clear();
        for(auto it :nums2_not_in_nums1)
        {
            temp.push_back(it);
        }
        ans.push_back(temp);
       
        
        return ans;
    }
};