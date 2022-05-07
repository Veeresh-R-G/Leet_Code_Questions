class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        stack <int> stack;
        int second =  -2147483648;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums [i] < second)
                return true;
            while (stack.size() >0 && nums [i] > stack.top()){
                second = stack.top ();
                stack.pop();
            }
                
            stack.push (nums [i]);
        }
        return false;
        
    }
};

// class Solution {

// public:
//     bool find132pattern(vector<int>& nums) {
        
//         /*
//             Brute Force : O(n ^ 3)
            
//             Optimisation : Using A Stack
            
//             Store elements in Decreasing Order !!
            
//         */
        
        
// //         if(nums.size() < 3)
// //         {
// //             return false;
// //         }
        
        
// //         int n = nums.size();
        
// //         for(int x = 0 ; x < n - 2 ; x++)
// //         {
// //             int i = x;
// //             int j = x + 1;
// //             int k = x + 2;
            
        
// //             if((nums[i] < nums[k]) && (nums[k] < nums[j]) && (nums[i] < nums[j]))
// //             {
// //                 return true;
// //             }
// //             continue;
// //         }
        
// //         return false;
//     }
// };