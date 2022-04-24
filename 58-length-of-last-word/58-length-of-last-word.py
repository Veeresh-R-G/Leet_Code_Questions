class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s = s.lstrip()
        s = s.rstrip()
        print(s)
        l = s.split(" ")
        
        return len(l[len(l) - 1]);