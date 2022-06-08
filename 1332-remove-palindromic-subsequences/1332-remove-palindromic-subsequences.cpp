class Solution {
public:
    /*
    
        This is the most craziest question that I have seen
        Op man!!
        
        Reading question is very Important
        Its subsequence loo....
        sariyaage vodbeku\U0001f635\U0001f609 !!
        
    */
    bool Ispalin(string s)
    {
        int st = 0;
        int e = s.length() -1;
        
        while(st < e)
        {
            if(s[st++] != s[e--])
            {
                return false;
            }
        }
        
        return true;
    }
    
    int removePalindromeSub(string s) {
        
        
        bool palin = Ispalin(s);
        if(palin)
        {
            return 1;
        }
        
        return 2;
    }
};