class Solution:
    def longestPalindrome(self, s: str) -> str:

        n = len(s)
        res = ""
        resLen = 0
        for i in range(n):

            #Odd length Palindromes check
            l , r = i , i
            while(l >= 0 and r < n and s[l] == s[r]):
                if (r - l + 1) > resLen:
                    res = s[l : r + 1]
                    resLen = r - l + 1
                l -= 1
                r += 1


            #Even Length Palindromes check
            l , r = i , i + 1
            while(l >= 0 and r < n and s[l] == s[r]):
                if (r - l + 1) > resLen:
                    res = s[l : r + 1]
                    resLen = r - l + 1
                l -= 1
                r += 1
            
        return res