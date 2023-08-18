class Solution {
public:
    int maximumGap(vector<int>& nums) {
        
        int n = nums.size();
        if(n < 2){
            return 0;
        }
        if(n == 2){
            return abs(nums[0] - nums[1]);
        }

        vector<int> temp = nums;
        sort(nums.begin() , nums.end());

        int maxi = INT_MIN;
        for(int i = 0 ; i < n - 1 ; i++){
            maxi = max(maxi , nums[i + 1] - nums[i]);
        }

        return maxi;



    }
};