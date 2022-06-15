class Solution {
public:
    
    void solve(vector<vector<int>>&ans , vector<int> nums , vector<int> out ,map<int , bool> &MAP)
    {
        if(out.size() == nums.size())
        {
            ans.push_back(out);
            return;
        }
        
        for(int i = 0 ; i < nums.size() ; i++)
        {
            
            if(MAP[nums[i]] == false)
            {
                out.push_back(nums[i]);
                MAP[nums[i]] = true;
                
                solve(ans , nums ,out , MAP);
                
                out.pop_back();
                MAP[nums[i]] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> out;
        
        map<int,bool> myMap;
        for(auto it : nums)
        {
            myMap.insert({it , false});
        }
        
        solve(ans , nums , out , myMap);
        
        return ans;
    }
};