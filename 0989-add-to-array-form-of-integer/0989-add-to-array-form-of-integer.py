class Solution:
    def addToArrayForm(self, num: List[int], k: int) -> List[int]:
        
        temp = 0
        for i in num:
            temp = temp * 10 + int(i) 
        
        temp = temp + k
        
        temp = str(temp)
       
        ans = []
        
        for i in range(len(temp)):
            
            ans.append(int(temp[i]))
        
        return ans