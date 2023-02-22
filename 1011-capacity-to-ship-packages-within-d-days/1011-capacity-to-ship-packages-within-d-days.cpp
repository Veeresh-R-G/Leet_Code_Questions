class Solution {
public:
    bool good(vector<int>& weights, int mid, int days){
        int curSum = 0, cnt = 0;
        for(int i = 0; i < weights.size(); i++){
            if(weights[i] > mid)
                return true;
            if(curSum + weights[i] > mid){
                cnt++;
                curSum = 0;
            }
            curSum += weights[i];
        }
        if(curSum <= mid)  cnt++;
        return cnt > days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0, r = accumulate(weights.begin(), weights.end(), 0);
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(good(weights, mid, days))  l = mid + 1;
            else    r = mid - 1;
        }
        return l;
    }
};