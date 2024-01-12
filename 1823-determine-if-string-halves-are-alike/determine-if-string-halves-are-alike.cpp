class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        int c1 = 0;
        int c2 = 0;
        
        int mid = (n / 2);
        
        // Single Loop
        for(int i = 0 ; i < (n / 2) ; i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
              s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                c1++;
            }
            
            if(s[i + mid ] == 'a' || s[i + mid] == 'e' || s[i + mid] == 'i' || s[i + mid] == 'o' || s[i + mid] == 'u' ||
              s[i + mid] == 'A' || s[i + mid] == 'E' || s[i + mid] == 'I' || s[i + mid] == 'O' || s[i + mid] == 'U')
            {
                c2++;
            }
        }
        
        return c1 == c2;
    }
};