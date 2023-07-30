class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
         int i = 0;
    int j = 1;
    set<vector<int>> s;
    vector<vector<int>> ans;
    sort(nums.begin() , nums.end());
    while(i < nums.size()){
        j = i + 1;

        while(j < nums.size()){
            long long k = j + 1;
            long long l = nums.size() - 1;

            while(k < l){
                long long temp = nums[i]*1ll + nums[j]*1ll + nums[k]*1ll + nums[l]*1ll;

                if(temp == target){
                    s.insert({nums[i] , nums[j] , nums[k] , nums[l] });
                    k++;
                    l--;
                }
                else if(temp < target){
                    k++;
                }
                else{
                    l--;
                }
            }
            j++;
        }
        i++;
    }

    for(auto it : s){
        ans.push_back(it);
    }

    

    return ans;
    }
};