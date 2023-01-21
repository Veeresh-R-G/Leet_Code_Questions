class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        
        '''
            This is Invalid bcoz IP length can never be above 12
        '''
        if(len(s) > 12):
            return []
        
        
        res = []
        
        def f(ind , currIp , dots):
            if(dots > 4):
                return
            
            if(dots == 4 and ind == len(s)):
                res.append(currIp[:len(currIp) - 1])
                return
            
            
            '''
                s[ind : i + 1] --> Value check
                
                ind == i --> Single digit (0 , 1 , 2, 3, .. 9)
                
                s[ind] != "0" ---> For multiple digits but 
                                   starting digit should not be 0(no trailing 0)
                
            '''
            for i in range(ind , min(ind + 3 , len(s))):
                if int(s[ind : i + 1]) <= 255 and (ind == i or s[ind] != "0"):
                    f(i + 1 , currIp + s[ind : i + 1] + "." , dots + 1)
            
        
        f(0 , "" , 0)
        
        return res