class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        
        int n = nums.size();
        int cnt = 0;
        long long sum = 0;

        for(auto &ele: nums){
            sum += ele;
        }

        long long currSum = 0;
        for(int i = 0;i < n - 1; i++){
            currSum += nums[i];
            long long diff = sum - currSum;
            if(currSum >= diff){
                cnt++;
            }
        }

        return cnt;
    }
};