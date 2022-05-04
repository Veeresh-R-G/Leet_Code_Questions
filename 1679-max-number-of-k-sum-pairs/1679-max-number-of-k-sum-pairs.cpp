class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        
        /*
                
                Two - pointer again !!
                Time : O(n*log(n))
                Space : O(1)
            
        */
        if(nums.size() <= 1)
        {
            return 0;
        }
            
        sort(nums.begin() , nums.end());
        int c = 0;
        
        int s = 0;
        int e = nums.size() - 1;
        
        while(s < e)
        {
            if(nums[s] + nums[e] == k)
            {
                c++;
                s++;
                e--;
            }
            else if(nums[s] + nums[e] > k)
            {
                e--;
            }
            else
            {
                //nums[s] + nums[e] < k
                s++;
            }
        }
        
        cout << c;
        
        return c;
    }
};