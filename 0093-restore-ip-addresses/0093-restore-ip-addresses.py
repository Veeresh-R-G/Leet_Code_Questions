class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        
        if(len(s) > 12):
            return []
        
        
        res = []
        
        def f(ind , currIp , dots):
            if(dots > 4):
                return
            
            if(dots == 4 and ind == len(s)):
                res.append(currIp[:len(currIp) - 1])
                return
            
            
            for i in range(ind , min(ind + 3 , len(s))):
                if int(s[ind : i + 1]) <= 255 and (ind == i or s[ind] != "0"):
                    f(i + 1 , currIp + s[ind : i + 1] + "." , dots + 1)
            
        
        f(0 , "" , 0)
        
        return res