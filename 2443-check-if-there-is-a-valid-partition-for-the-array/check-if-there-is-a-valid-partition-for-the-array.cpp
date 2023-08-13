class Solution {

private:

    vector<int>dp;

    bool solve(vector<int>& nums , int ind){
        int n = nums.size();
        if(ind >= n){
            return true;
        }

        if(dp[ind] != -1){
            return dp[ind];
        }
        //Consecutive matches
        if(ind + 1 < n){
            if(nums[ind] == nums[ind + 1]){
                if(solve(nums , ind + 2)){
                    return dp[ind] = true;
                }
                
               
            }

            if(ind + 2 < n && nums[ind] == nums[ind + 1] &&  nums[ind + 1] == nums[ind + 2]){
                if(solve(nums , ind + 3)){
                    return dp[ind] = true;
                }
            }
        }


        //Increasing sequence
        if(ind + 1 < n && ind + 2 < n && (nums[ind + 1] - nums[ind] == 1) && (nums[ind + 2] - nums[ind + 1] == 1)){
            
            if(solve(nums , ind + 3)){
                return dp[ind] = true;
            }
        }

        return dp[ind] = false;
    }
public:
    bool validPartition(vector<int>& nums) {
        
        dp.resize(nums.size() + 1 , -1);

        return solve(nums , 0);
    }
};