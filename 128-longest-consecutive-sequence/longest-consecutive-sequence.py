class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        
        if(len(nums) == 0):
            return 0

        nums = list(set(nums))
        nums.sort()
        
        maxi = 1
        ans = 1
        prev = nums[0]
        for i in range(1 , len(nums)):
            if(nums[i] - prev == 1):
                prev = nums[i]
                maxi += 1
            
            else:
                prev = nums[i]
                ans = max(ans , maxi)
                maxi = 1
            

        return max(ans , maxi)