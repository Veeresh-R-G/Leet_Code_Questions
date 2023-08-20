class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:

        i = 0
        n = len(nums)
        nums.sort()
        ans = []
        for i , a in enumerate(nums):
            if(a > 0):
                break
            
            if(i > 0 and nums[i - 1] == nums[i]):
                continue

            j = i + 1
            k = n - 1

            while j < k:
                if(nums[i] + nums[j] + nums[k] == 0):
                    ans.append([nums[i] , nums[j] , nums[k]])
                    j += 1
                    k -= 1
                    while(nums[j] == nums[j - 1] and j < k):
                        j += 1
                elif(nums[i] + nums[j] + nums[k] < 0):
                    j += 1
                
                else:
                    k -= 1

                
                
                
                # while(nums[k] == nums[k - 1] and j < k):
                #     k -= 1
            
           

        return ans

