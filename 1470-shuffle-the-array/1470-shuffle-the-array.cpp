class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        int N = nums.size(); //Double size;
        vector<int> ans;
        
        
        for(int i = 0 ; i < N / 2 ; i++)
        {
            int first = nums[i];
            ans.push_back(first);
            
            int second = nums[i + (N / 2)];
            ans.push_back(second);
        }
        
        return ans;
        
    }
};