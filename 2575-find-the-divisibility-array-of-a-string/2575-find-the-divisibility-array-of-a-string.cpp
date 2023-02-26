class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        
        long long n = 0;
        vector<int> ans;
        for(auto it : word)
        {
            n = ((n * 10) + (it - '0')) % m;
            if(n % m == 0) ans.push_back(1);
            else ans.push_back(0);
        }
        
        return ans;
    }
};