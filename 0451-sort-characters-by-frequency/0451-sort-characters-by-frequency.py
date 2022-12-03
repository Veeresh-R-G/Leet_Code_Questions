class Solution:
    def frequencySort(self, s: str) -> str:
        
        d =dict()
        
        for i in s:
            if i not in d.keys():
                d[i] = 1
            else:
                d[i] += 1
                
                
        d = dict(sorted(d.items(), key=lambda item: item[1] , reverse= True))
        
        ans = ""
        
        for i in d.keys():
            temp = i * d[i]
            ans = ans + temp
        
        return ans