class Solution {

private:
    int solve(vector<int>&nums , int l , int r , bool p1){
        if(l == r){
            return nums[l];
        }

        if(l > r){
            return 0;
        }

        if(p1){
            int takeFirst = nums[l] + solve(nums , l + 1 , r , false);
            int takeLast = nums[r] + solve(nums , l , r - 1, false);
            return max(takeFirst, takeLast);
        }
        
        int takeFirst =  solve(nums , l + 1, r , true);
        int takeLast =solve(nums , l , r - 1,  true);
        return min(takeFirst , takeLast);

    }
public:
    bool predictTheWinner(vector<int>& nums) {
    
        bool p1 = true;

        int l = 0;
        int r = nums.size() - 1;
        int sum = 0;

        for(auto it : nums){
            sum += it;
        }


        int ans = solve(nums , l , r , p1);

        int score2 = sum - ans;


        if(ans >= score2){
            return true;
        }
        // cout << ans << " ---- " << sum << endl;
        return false;
    }
};