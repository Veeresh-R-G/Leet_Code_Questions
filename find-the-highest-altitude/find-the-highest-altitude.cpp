class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alti = 0;
        int ans = 0;
        int n = gain.size();

        for(auto it : gain)
        {
            alti = alti + it;
            ans = max(ans , alti);
        }

        return ans;
    }
};