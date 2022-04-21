class Solution {
public:
    bool isPalin(string s , int start , int end)
    {
        int so = start;
        int e = end;
        
        while(so <= e)
        {
            if(s[so] == s[e])
            {
                so++;
                e--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        
        if(s.length() == 0 || s.length() == 1){
            return true;
        }
        else
        {
            int n = s.length();
            
            int st = 0;
            int e = n - 1;
            
            while(st <= e){
                
                if(s[st] == s[e]){
                    st++;
                    e--;
                }
                else{
                    
                    return isPalin(s , st + 1 , e) || isPalin(s , st , e - 1);
                }
            }
            
            
        }
        
        return true;
        
    }
};