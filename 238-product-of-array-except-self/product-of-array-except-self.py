class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:

        pro = 1

        for i in nums:
            pro = pro * i

        
        ans = []

        for i in range(len(nums)):
            if nums[i] != 0:
                ans.append(pro // nums[i])
            else:
                print(i)
                temp = 1
                for j in range(len(nums)):
                    if i != j:
                        temp = temp * nums[j]

                ans.append(temp)
        return ans