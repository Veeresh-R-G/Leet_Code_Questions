class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        
        int n = prices.size();
        
        int pro = 0;
        int miniPrice = prices[0];
        
        for(int i = 0 ; i < n ; i++)
        {
            if(prices[i] - miniPrice > pro) pro = prices[i] - miniPrice;
            
            miniPrice = min(miniPrice , prices[i]);
        }
        
        return pro;
    }
};