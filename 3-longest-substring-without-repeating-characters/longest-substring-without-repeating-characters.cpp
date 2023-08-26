class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        

        int j = 0 ;

        map<char , int> mp;
        int ans = INT_MIN;
        for(int i = 0 ; i < s.size() ; i++){

            if(mp.find(s[i]) != mp.end()){
                
                while(mp.find(s[i]) != mp.end()){
                    mp.erase(s[j]);
                    j++;
                }
            }
            
            mp[s[i]]++;
            ans = max(ans , i - j + 1);
            
        }

        return ans == INT_MIN ? 0 : ans;
    }
};