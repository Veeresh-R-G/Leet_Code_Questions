class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        map<int ,int> mp;
        vector<vector<int>> ans;

        set<vector<int>> s;
        sort(nums.begin() , nums.end());
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            int j = i + 1;
            int k = n - 1;

            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];

                if(sum == 0){
                    s.insert({nums[i] , nums[j] , nums[k]});
                    j++;
                    k--;
                }
                else if(sum > 0){
                    k--;
                }
                else{
                    j++;
                }
            }
        }

        for(auto dups : s){
            ans.push_back(dups);
        }
        return ans;
    }
};