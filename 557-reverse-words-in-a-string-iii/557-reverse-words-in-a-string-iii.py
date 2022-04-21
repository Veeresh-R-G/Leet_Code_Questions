class Solution:
        
        
    def reverseWords(self, s: str) -> str:
        if(len(s) == 1):
            return s
        l = s.split(" ")
        
        for i in range(len(l)):
            ans = ""
            for j in l[i]:
                ans = j + ans
            l[i] = ans
            
        s = " ".join(l)
        return s
        