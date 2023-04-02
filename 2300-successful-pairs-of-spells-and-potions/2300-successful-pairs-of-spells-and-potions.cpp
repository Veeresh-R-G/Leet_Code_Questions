class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        vector<int> pairs;
        
        int n = spells.size();
        int m = potions.size();
        
        //Smallest * largest is only not cross the limit so the rest of the smaller elements in the 2nd array will also not cross the limit !!!!
        
        //sort this in descending order
        sort(potions.begin() , potions.end());
        long long maxi = potions[m - 1];
       
        for(auto& spell : spells)
        {
            long long minPotion = ceil((1.0 * success) / spell);
            
            if(minPotion > maxi) pairs.push_back(0);
            
            else
            {
                auto minInd = lower_bound(potions.begin() , potions.end() , minPotion) - potions.begin();
                
                pairs.push_back(m - minInd);
            }
        }
        
        return pairs;
        
    }
};