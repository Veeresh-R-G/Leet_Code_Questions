class Solution:
    def reverseWords(self, s: str) -> str:
        
        s = s.strip()

        l = list(reversed(s.split(" ")))
        ans = ""
        for i in l:
            if i == '':
               continue
            else:
                ans = ans + i + " "

        return ans[:len(ans)-1]
        
        