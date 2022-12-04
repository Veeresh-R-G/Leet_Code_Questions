class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        
      
        long long n = nums.size();
        if(n == 1 || n == 0)
        {
            return 0;
        }
        long long ans = 0;
        long long diff = 1e9;
        //Pre Computations
        long long sumFront = 0;
        long long sumBack = 0;
        for(int i = 0 ; i < n ; i++)
        {
            sumBack += nums[i];
        }
        
        long long nFront = 1;
        long long nBack = n - 1;
        
        for(int index = 0 ; index < n ; index++)
        {
            
            sumFront += nums[index];
            sumBack -= nums[index];
            
            long long avgFront = sumFront / nFront;
            long long avgBack = nBack != 0 ? sumBack / nBack : 0;

            long long currDiff = abs(avgFront - avgBack);

            if(currDiff < diff)
            {
                diff = currDiff;
                ans = index;
            }
            
            nFront++;
            nBack--;
        }
        
        return ans;
    }
};