class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:

        d = {}

        for i in nums:
            if i not in d:
                d[i] = 1
            else:
                d[i]+=1
        
        l = sorted(d.items() , key = lambda x : x[1] , reverse = True)

        ans = []
        for i in range(k):
            ans.append(l[i][0])
        return ans