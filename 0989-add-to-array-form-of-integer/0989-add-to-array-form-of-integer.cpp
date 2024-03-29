class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
        int N = num.size();
        for(int i = N - 1 ; i >= 0 ; i--)
        {
            int temp = (num[i] + k);
            num[i] = temp % 10;
            k = (temp) / 10;
        }
        
        while(k > 0)
        {
            num.insert(num.begin() , k % 10);
            k = k / 10;
        }
        
        return num;
    }
};