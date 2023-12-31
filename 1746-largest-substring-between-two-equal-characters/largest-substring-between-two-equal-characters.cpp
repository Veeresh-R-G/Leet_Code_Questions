class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        
        int N = s.size();
        int ans = -1;

        if(N <= 1){
            return ans;
        }

        unordered_map<char, pair<int, int>> mp;

        for(int i = 0;i < N; i++){
            if(mp.find(s[i]) == mp.end()){
                mp[s[i]] = {i, -1};
            }
            else{
                mp[s[i]].second = i;
            }
        }

        for(auto it: mp){
            ans = max(ans, it.second.second - it.second.first - 1);
        }

        return ans;


    }
};