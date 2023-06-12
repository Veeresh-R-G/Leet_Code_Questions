class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        
        if(len(nums) == 0):
            return []
        
        if(len(nums) == 1):
            return [str(nums[0])]
        prev = nums[0]
        ans = []
        i = 1
        tempString = f"{prev}->"
        while(i < len(nums)):
            
            curr = nums[i]
            print(tempString.split("->"))
            if(abs(curr - prev) == 1):
                if((tempString.split("->")[1]) == ''):
                    tempString = tempString + str(curr)

                else:
                    len_curr = len(str(abs(int(tempString.split("->")[1]))))
                    tempString = tempString[:len(tempString) - len_curr] + str(curr)

            else:
                print("Here : " , tempString)
                if(tempString.split("->")[1] == '' ):
                    ans.append(tempString.split("->")[0])

                else:
                    ans.append(tempString)
                
                tempString = f"{curr}->"

            prev = curr
            i += 1
        
        if(tempString.split("->")[1] == '' ):
            ans.append(tempString.split("->")[0])

        else:
            ans.append(tempString)
        
      


        return ans