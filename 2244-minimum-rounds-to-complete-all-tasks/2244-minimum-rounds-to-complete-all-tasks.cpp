class Solution {
public:
    /*
                ----LOGIC----
                
                If we have freq % 3 == 0 we require (freq / 3) rounds to finish all the tasks
                
                else
                    For any case it will be (freq / 3) + 1
                    
                    
                    
                 let the number be of any form like : (3k+1) / (3k + 2)
                 
                 still the rounds will be (freq / 3) + 1
                 
                 For example : 
                 10 --> 3 + 3 + 2 + 2 == 4 rounds == (10 / 3) + 1 ==> 3 + 1 => 4
                 
                 11 ---> 3 + 3 + 3 + 2 so its still the same
                
                
    */
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
