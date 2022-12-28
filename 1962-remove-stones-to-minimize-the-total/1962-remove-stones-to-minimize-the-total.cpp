class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        int n = piles.size();
        sort(piles.begin() , piles.end());
        priority_queue<int> g;
        for(auto ele : piles)
        {
            g.push(ele);
        }
        while(k)
        {
            k--;
            
            int top = g.top();
            g.pop();
            
            g.push(top - (top / 2));
        }
        
        int sum = 0;
        
        while(!g.empty())
        {
            int top = g.top();
            g.pop();
            sum = sum + top;
        }
        
        return sum;
    }
};