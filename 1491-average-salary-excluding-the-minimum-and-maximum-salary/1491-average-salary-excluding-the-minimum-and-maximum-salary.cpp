class Solution {
public:
    double average(vector<int>& salary) {
        
        double sum = 0;
        double N = salary.size() - 2;
        
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        for(auto it : salary)
        {   
            mini = min(mini , it);
        }
        for(auto it : salary)
        {
            sum += double(it);
            maxi = max(maxi , it);
        }
        
        sum = sum - mini - maxi;
        return (sum / N);
    }
};