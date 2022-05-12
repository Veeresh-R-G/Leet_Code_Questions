class Solution {
public:
    
    vector<int> temp;
    vector<vector<int>> ans;
    
    unordered_map <int , int> myMap;
    
    
    void solve(int ind , int n)
    {
        if(temp.size() == n)
        {
            ans.push_back(temp);
        }
        
        
        for(auto x : myMap)
        {
            if(x.second == 0)
            {
                continue;
            }
            
            temp.push_back(x.first);
            myMap[x.first]--;
            
            solve(ind + 1 , n);
            
            myMap[x.first]++;
            temp.pop_back();
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        int n = nums.size();
        for(auto it: nums)
        {
            myMap[it]++;
        }
        
        
        int index = 0;
        
        solve(index , n);
        
        return ans;
    }
};