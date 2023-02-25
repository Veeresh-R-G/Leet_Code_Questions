class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int N = prices.size();
        
        int l = 0; //Buy pointer
        int r = 1; // sell pointer
        int maxProfit = 0;
        while(r < N)
        {
            //If profit hai..
            if(prices[r] > prices[l])
            {
                maxProfit = max(maxProfit , prices[r] - prices[l]);
            }
            else
            {
                l = r;
            }
            r++;
        }
        
        return maxProfit;
    }
};