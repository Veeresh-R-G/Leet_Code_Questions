class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
         
        t = s[1:] + s[:-1]

        return s in t