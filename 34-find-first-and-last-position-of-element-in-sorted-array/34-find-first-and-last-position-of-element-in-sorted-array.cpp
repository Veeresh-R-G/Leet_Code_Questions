class Solution {
public:
    vector<int> ans = {-1 , -1};
    
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
        
        //Last pos
        
        int s = 0;
        int e = nums.size() - 1;
        
        while(s <= e)
        {
            int mid = (s) + (e - s)/2; // to Avoid Out of Bound Error
            
            if(nums[mid] < target)
            {
                s = mid + 1;
            }
            
            else if(nums[mid] > target)
            {
                e = mid - 1;
            }
            
            else
            {
                if(mid + 1 < nums.size() && nums[mid + 1] == target)
                {
                    s = mid + 1;
                }
                else
                {
                    ans[1] = mid;
                    break;
                }
            }
        }
        
        s = 0;
        e = nums.size() - 1;
        while(s <= e)
        {
            int mid = (s) + (e - s)/2; // to Avoid Out of Bound Error
            
            if(nums[mid] < target)
            {
                s = mid + 1;
            }
            
            else if(nums[mid] > target)
            {
                e = mid - 1;
            }
            
            else
            {
                if(mid - 1 >= 0 && nums[mid - 1] == target)
                {
                    e = mid - 1;
                }
                else
                {
                    ans[0] = mid;
                    break;
                }
            }
        }
        
        return ans;
        
    }
};