class Solution {
public:
    
    void solve(vector<vector<int>>&ans , vector<int> nums , vector<int> out ,map<int , bool> &MAP ,int K ,int ind)
    {
        if(out.size() == K )
        {
            ans.push_back(out);
            return;
        }
        
        for(int i = ind ; i < nums.size() ; i++)
        {
            
            if(MAP[nums[i]] == false)
            {
                out.push_back(nums[i]);
                MAP[nums[i]] = true;
                
                solve(ans , nums ,out , MAP , K , i + 1);
                
                out.pop_back();
                MAP[nums[i]] = false;
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
     
        vector<int> nums = {};
        map<int,bool> myMap;
        vector<vector<int>> ans;
        for(int i = 1 ; i <= n ; i++)
        {
            nums.push_back(i);
            myMap.insert({i , false});
        }
        vector<int> out;
        
        solve(ans , nums , out , myMap , k , 0);
        
        return ans;
        
    }
};