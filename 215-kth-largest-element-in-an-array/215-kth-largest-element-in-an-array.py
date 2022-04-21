class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        l = sorted(nums, reverse= True)
        return l[k - 1];