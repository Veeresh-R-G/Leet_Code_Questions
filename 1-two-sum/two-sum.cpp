class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int , int> mp;
        vector<int> ans;
        int i = 0;
        for(auto it : nums){
            int diff = target - it;

            if(mp.find(diff) != mp.end()){
                ans = {i , mp[diff]};
                break;
            }
            
            mp[it] = i;
            i++;
        }

        return ans;
    }
};