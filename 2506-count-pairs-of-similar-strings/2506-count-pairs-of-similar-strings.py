from math import comb
class Solution:
    def similarPairs(self, words: List[str]) -> int:
        
        d = dict()
        n = len(words)
        
        for i in range (n):
            tempList = "".join(sorted(list(set(words[i]))))
            # print(tempList)
            if(tempList not in d.keys()):
                d[tempList] = [i]
            else:
                d[tempList].append(i)
            
        
        ans = 0
        
        for key in d:
            if(len(d[key]) >= 2):
                ans = ans + comb(len(d[key]) , 2)
        
        
        return ans
                
            
        
        