class Solution {

private:
    bool isVowel(char c)
    {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
public:
    string reverseVowels(string s) {
        
        int l = 0;
        int r = s.size() - 1;


        while(l < r)
        {
            //left most vowel
            while(l < s.size() && !isVowel(s[l]) )
            {
                l++;
            }

            while(r >= 0 && !isVowel(s[r]))
            {
                r--;
            }

            if(l < r)
            {
                swap(s[l++] , s[r--]);
            }
        }

        return s;

    }
};