class Solution {
public:
    int strStr(string s, string patt) {
        
        int N = s.size();
        int M = patt.size();
        
        for(int i = 0 ; i <= (N - M) ; i++)
        {
            if(s.substr(i , M) == patt)
            {
                return i;
            }
        }
        
        return -1;
    }
};