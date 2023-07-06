class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int ans_1 = INT_MIN , ans_2 = INT_MIN;
        int currProd = 1;

        for(int i = 0 ; i < nums.size() ; i++)
        {
            
            currProd *= nums[i];

            ans_1 = max(ans_1 , currProd);

            if(currProd == 0)
            {
                currProd = 1;
            }
        }

        //traverse ever from back to avoid the case when we have only 1 -ver negative
        currProd = 1;

        for(int i = nums.size() - 1; i >= 0 ; i--)
        {
            
            currProd *= nums[i];

            ans_2 = max(ans_2 , currProd);

            if(currProd == 0)
            {
                currProd = 1;
            }
        }

        return max(ans_1 , ans_2);

    }
};