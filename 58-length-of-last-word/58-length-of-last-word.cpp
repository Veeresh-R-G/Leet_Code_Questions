
class Solution {
public:
   
    int lengthOfLastWord(string s) {
        
        int s1 = s.length() - 1;
        
        
        int n = s.length();
        
        while(s1>=0 && s[s1]==' ')
        {
            s1--;
        }
        int s2 = s1;
        
        while(s2>=0 && s[s2]!=' ')
        {
            s2--;
        }
        
        return s1 - s2;
    }
};