class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int N = nums.size();
        vector<int> v;

        v.push_back(nums[0]);
        
        for(int i = 1; i < N; i++){
            
            if(v[v.size() - 1] < nums[i]){
                v.push_back(nums[i]);
            }
            else{
                int ind = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
                v[ind] = nums[i];
            }
        }

        return v.size();
    }
};