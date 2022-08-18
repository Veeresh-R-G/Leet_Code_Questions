class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n = nums.size();
       
        int threshold = n / 3;
        
        
        vector<int> ans;
        
         unordered_map<int, int> map;
        
        for(auto it : nums)
        {
            if(map.find(it) == map.end())
            {
                //Not Found Case
                map[it] = 1;
            }
            else
            {
                
                map[it] += 1;
                
            }
        }
        
         unordered_map<int , int>:: iterator itr;
        for(itr = map.begin() ; itr != map.end() ; itr++)
        {
            if(itr->second > threshold)
            {
                ans.push_back(itr->first);
            }
        }
        
        return ans;
    }
};