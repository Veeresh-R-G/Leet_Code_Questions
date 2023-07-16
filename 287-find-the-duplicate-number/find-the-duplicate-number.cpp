class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        // linked List cycle detection

        int slow = nums[0];
        int fast = nums[0];

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);


        slow = nums[0];
        //to find the entrance of the cycle
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;

    }
};