class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        
        sort(costs.begin() , costs.end());
        int N = costs.size();
        
        // for(int i = 0 ; i < (N / 2) ; i++)
        // {
        //     int temp = costs[i];
        //     costs[i] = costs[ n - i - 1];
        //     costs[n - i - 1] = temp;
        // }
        int ans = 0;
        
        for(auto kaasu : costs)
        {
            if(kaasu <= coins && coins > 0)
            {
                coins -= kaasu;
                ans++;
            }
        }
        
        return ans;
    }
};