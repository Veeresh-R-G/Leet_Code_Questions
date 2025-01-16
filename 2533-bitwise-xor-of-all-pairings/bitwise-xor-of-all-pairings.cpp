class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        

        int ans = 0;
        int n = nums1.size();
        int m = nums2.size();

        if(n % 2 == 1 && m % 2 == 1){
            for(auto &ele: nums1){
                ans = ans ^ ele;
            }

            for(auto &ele: nums2){
                ans = ans ^ ele;
            }

            return ans;
        }

        if(n % 2 == 1 && m % 2 == 0){
            for(auto &ele : nums2){
                ans = ans ^ ele;
            }

            return ans;
        }

        if(n % 2 == 0 && m % 2 == 1){
            for(auto &ele : nums1){
                ans = ans ^ ele;
            }

            return ans;
        }

        return 0;
        
    }
};