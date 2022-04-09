class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        d = dict()
        
        for i in range(len(nums)):
            if(nums[i] not in d.keys()):
                d[nums[i]] =1
            else:
                d[nums[i]] += 1;
            
        d = dict(sorted(d.items(), key=lambda item: item[1],reverse = True))
        
        # print(d)
        l = list(d.keys())[:k]
        # print(l)
        return l
        
        