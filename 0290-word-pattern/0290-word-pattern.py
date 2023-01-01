class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        
        
        d = dict()
        
        words = s.split(" ")
        if(len(pattern) != len(words)):
            return False
        
        for i in range(len(pattern)):
            if pattern[i] in d:
                value = d[pattern[i]]
                if(value != words[i]):
                    return False
                else:
                    continue
            
            else:
                if(words[i] in d.values()):
                    return False
                d[pattern[i]] = words[i]
        
        
        return True
                
                