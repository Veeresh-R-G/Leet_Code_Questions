class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> ump;
        for (int num : nums) {
            ump[num]++;
        }
        int ans = 0;
        for (auto it: ump) {
            if (it.second == 1) {
                return -1;
            }
            ans += ceil((double)(it.second) / 3);
        }
        return ans;
    }
};