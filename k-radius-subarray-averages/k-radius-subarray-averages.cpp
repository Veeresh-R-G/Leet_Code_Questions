class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        
        int N = nums.size();
        vector<int> avgs;

        if(N < (2 * k + 1))
        {
            for(int i = 0 ; i < N ; i++)
            {
                avgs.push_back(-1);
            }

            return avgs;
        }
        
        

        //first k - 1 elements
        long long int sum = 0;
        for(int i = 0  ; i < k ; i++)
        {
            avgs.push_back(-1);
            sum += nums[i] + nums[i + k + 1];
        }

        sum += nums[k];
        int p = 2 * k + 1;
        for(int i = k + 1; i < (nums.size() - k) ; i++)
        {
            avgs.push_back(sum / p);
            sum = sum - nums[i - k - 1];
            sum = sum + nums[i + k];
        }
        avgs.push_back(sum / p);
         for(int i = 0  ; i < k ; i++)
        {
            avgs.push_back(-1);
           
        }
        return avgs;
    }
};