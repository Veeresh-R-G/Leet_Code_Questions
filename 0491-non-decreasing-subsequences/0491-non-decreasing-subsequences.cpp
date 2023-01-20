class Solution {
public:
\
    void f(vector<int>& nums , int N ,set<vector<int>>& ans , int st , vector<int>& temp)
    {
        if(st >= N)
        {
            if(temp.size() >= 2)
            {
                ans.insert(temp);
            }
            return;
        }
        
        
        
        if(temp.empty() == true || nums[st] >= temp.back())
        {
            temp.push_back(nums[st]);
            f( nums , N ,ans , st + 1 , temp);
            temp.pop_back();
        }
        
        f(nums , N , ans , st + 1 , temp);
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        
        set<vector<int>> ans;
        vector<int> temp;
        int N = nums.size();
        f(nums , N , ans , 0 , temp);
        
        return vector(ans.begin() , ans.end());
    }
};