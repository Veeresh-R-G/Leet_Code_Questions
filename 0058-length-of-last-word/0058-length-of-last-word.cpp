class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int N = s.size();
        int ans = 0;
        for(int i = N - 1; i >= 0 ; i--)
        {
            if(s[i] == ' ' && ans == 0) continue;
            else if(s[i] == ' ' && ans != 0) break;
            else ans++;
        }
    
        return ans;
    }
    
};