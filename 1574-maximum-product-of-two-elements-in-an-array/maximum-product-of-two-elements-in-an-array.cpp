class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int maxi = INT_MIN;
        int maxii = INT_MIN;
        int ind = 0;
        int N = nums.size();
        for(auto i = 0 ; i < N ; i++){
            if(maxi < nums[i]){
                ind = i;
                maxi = nums[i];
            }
            maxi = max(maxi, nums[i]);
        }

        for(auto i = 0 ; i < N ; i++){
            if(i != ind){
                maxii = max(maxii , nums[i]);
            }
        }


        return (maxi - 1) * (maxii - 1);
    }
};