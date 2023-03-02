class Solution {
public:
    bool isAnagram(string s, string t) {
        
        vector<int> cnt1(26 , 0) , cnt2(26 , 0);

        for(auto it : s)
        {
            cnt1[it - 'a']++;
        }
        
        for(auto it : t)
        {
            cnt2[it - 'a']++;
        }
        
        for(int i = 0 ; i < 26 ; i++)
        {
            if(cnt1[i] != cnt2[i]) return false;
        }
        
        return true;
    }
};