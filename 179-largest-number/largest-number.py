class Solution:
    def largestNumber(self, nums: List[int]) -> str:

        ans = ""
        
        for i in range(len(nums)):
            nums[i] = str(nums[i])
          
        nums.sort(reverse = True)

        flag = False

        while(not flag):
            flag = True
            i = 0
            
            while(i < len(nums) - 1):
                if(nums[i] + nums[i + 1] < nums[i + 1] + nums[i]):
                    nums[i] , nums[i + 1] = nums[i + 1] , nums[i]
                    flag = False
                i += 1

        for i in nums:
            ans += i      

        if(ans == "0"*len(nums)):
            return "0"
        return ans