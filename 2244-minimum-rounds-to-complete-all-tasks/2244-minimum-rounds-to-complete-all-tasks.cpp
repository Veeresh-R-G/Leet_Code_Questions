class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        
        map<int , int> m;
        
        for(auto task : tasks)
        {
            m[task]++;
        }
        
        
        int count = 0;
        for(auto it : m)
        {
            if(it.second == 1)
            {
                return -1;
            }
            else
            {
                if(it.second % 3 == 0) count += (it.second / 3);
                else
                {
                    count += (it.second / 3) + 1;
                }
            }
        }
        
        
        return count;
    }
};