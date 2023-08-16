class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int res =0;
        int currSum = 0;

        map<int , int> mp;
        mp[0] = 1;
        for(auto it : nums){

            currSum += it;

            if(mp.find(currSum - k) != mp.end()){
                res += mp[currSum - k];
            }
            
            //to know that we have got subarray = currSum
            mp[currSum]++;
        }

        return res;
    }
};