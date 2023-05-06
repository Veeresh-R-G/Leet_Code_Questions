class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        
        int ans = 0;
        int MOD = 1e9 + 7;
        int N = nums.size();
        int l = 0;
        int r = N - 1;
        
        
        sort(nums.begin() , nums.end());
        //precomputation 
        vector<int> v = {1};
        for(int i = 1 ; i <= N ;i++)
        {
            v.push_back((v.back() << 1) % MOD);
        }
        
        while(l <= r)
        {
            if(nums[l] + nums[r] > target)
            {
                r--;
            }
            else
            {
                ans = (ans % MOD + v[r - l] % MOD) % MOD;
                l++;
            }
        }
        
        return ans;
    }
};