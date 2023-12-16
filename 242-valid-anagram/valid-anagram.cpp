class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size() != t.size()){
            return false;
        }
        vector<int> s1(26, 0);
        vector<int> t1(26, 0);

        for(auto it: s) s1[it - 'a']++;

        for(auto it: t) t1[it - 'a']++;

        return s1 == t1;
        
    }
};