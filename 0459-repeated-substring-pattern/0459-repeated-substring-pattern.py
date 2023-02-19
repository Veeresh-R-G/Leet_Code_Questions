class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        
        temp = s[1:] + s[:-1]
        
        return s in temp