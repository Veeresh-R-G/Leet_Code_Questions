class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        
        unordered_set<int> temp;
        int ans = 0;
        for(auto it: nums){
            temp.insert(it);
        }

        for(int st : nums){
            int currLen = 0;
            long long currNum = st;

            while(temp.find((int) currNum) != temp.end()){
                currLen++;
                ans = max(ans, currLen);
                if(currNum * currNum > 1e5){
                    break;
                }
                currNum *= currNum;
            }

            
        }

        return ans < 2 ? -1 : ans;
    }
};