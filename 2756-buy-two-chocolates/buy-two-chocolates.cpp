class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin() , prices.end());

        int cnt = 0;
        int amt = money;

        for(int i = 0 ; i < prices.size() ; i++){

            if(amt >= prices[i]){
                amt -= prices[i];
                cnt++;
            }

            if(cnt == 2){
                break;
            }

        }

        return cnt == 2 ? amt : money;
    }
};