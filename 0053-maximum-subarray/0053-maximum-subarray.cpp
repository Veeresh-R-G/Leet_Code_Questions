class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        //Brute force
        /*
            Calculate all the sub Arrays from every element
            calculate sum of all the sub arrays and pick the max
            
            Kadane's Alogorithm:
            
            1. Include the current element in the sum
            2. maxi = max(maxi , sum)
            3. if(sum < 0) sum = 0
        */
        
        int sum = 0;
        int maxi = nums[0];
        for(int i = 0 ; i < nums.size(); i++)
        {
            //Sum is keeping track of the sum of subArrays here
            sum = sum+ nums[i];
            
            //Storing max values
            maxi = max(maxi , sum);
            
            //If its a negative sum why should we include it since it will decrease our sum further
            if(sum < 0)
            {
                sum = 0;
            }
            
        }
        
        return maxi;
        
    }
};