class Solution {

private:
    int BS(vector<int>& nums , int target, int left , int right){

        int low = left;
        int high = right;


        while(low <= high){

            int mid = low + (high - low) / 2;

            if(nums[mid] < target){
                low = mid + 1;
            }
            else if(nums[mid] == target){
                return mid;
            }
            else{
                high = mid - 1; 
            }
        }

        return -1;
    }
public:
    int search(vector<int>& nums, int target) {

        //search for pivot
        int left = 0;
        int n = nums.size();
        int right = n -1;

        while(left <= right){
            int mid = left + (right - left) / 2;

            if(nums[mid] > nums[n - 1]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }

        int ind = BS(nums , target , 0 , left - 1);
        if(ind != -1){
            return ind;
        }

        return BS(nums,target , left , n - 1);
    }
};