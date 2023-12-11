class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        
        map<int , int> mp;
        float n = arr.size();

        for(auto it: arr){
            mp[it]++;
        }

        for(auto it:mp){
            float freq = it.second / n;
            if(freq > 0.25){
                return it.first;
            }
        }

        return 6;
    }
};