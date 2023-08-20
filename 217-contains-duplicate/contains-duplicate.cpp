class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        map<int , int> mp;

        for(auto it : nums){
            
            if(mp.find(it) != mp.end()){
                return true;
            }
            else{
                mp[it]++;
            }
        }

        return false;
    }
};