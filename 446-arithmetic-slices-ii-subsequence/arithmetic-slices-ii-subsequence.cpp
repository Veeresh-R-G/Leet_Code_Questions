class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {

        //Dp matrix
        //index x difference

        //hashmap better than matrix because the difference is not 
        //following a certain pattern can be anything

        //so at a particular index, there can be more than one
        //Common differences


        int ans = 0;
        int N = nums.size();

        //index, diff -> # Of Elements
        // unordered_map<pair<int , int>, int> dp;

        //[{diff: # of elements},{},{}]
        unordered_map<long long, long long> dp[N + 1];
        

        for(int i = 0; i < N; i++){
            for(int j = 0; j < i; j++){

                long long diff = static_cast<long long>(nums[i]) - nums[j];
                if(diff > INT_MAX || diff < INT_MIN){
                    continue;
                }

                diff = static_cast<int>(diff);

                dp[i][diff] += 1;
                if(dp[j].count(diff)){
                    dp[i][diff] += (dp[j][diff]);
                    ans += (dp[j][diff]);
                }
                
            }
        }

        return ans;
    }
};