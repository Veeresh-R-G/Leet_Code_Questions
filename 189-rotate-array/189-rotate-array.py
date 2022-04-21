class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if(len(nums) == 1):
        
            return
        
        k = k % len(nums);
        
        l = [0] * len(nums)
        for i in range(len(nums)):
            l[i] = nums[i - k]
            
        for i in range(len(nums)):
            nums[i] = l[i]
        
            
        