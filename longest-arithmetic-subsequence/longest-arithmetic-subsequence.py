class Solution:
    def longestArithSeqLength(self, nums: List[int]) -> int:
        dp = {}
        ans = -100
        for i in range(len(nums)):
            for j in range(i):
                diff = nums[i] - nums[j]

                dp[(i , diff)] = 1 + dp.get((j , diff) , 1)
                ans = max(ans ,dp[(i , diff)] )
            
        return ans
            

        