class Solution:
    def minDeletions(self, s: str) -> int:
        
        d = collections.defaultdict(int)

        for i in s:
            d[i] += 1
        

        s = set()
        cnt = 0
        for key,value in d.items():

            while value > 0 and value in s :
                value -= 1
                cnt += 1

            s.add(value)

        
        return cnt
        

            
