class Solution {
public:
    int minJumps(vector<int>& arr) {
        
        
        queue<int> queueInd;
        int steps = 0;
        vector<bool> vis(arr.size() , false);
        
        queueInd.push(0);
        vis[0] = true;
        unordered_map<int , vector<int>> m;
        
        for(auto it = 0 ; it < arr.size() ; it++)
        {
            m[arr[it]].push_back(it);
        }
        
        
        while(!queueInd.empty())
        {
            int n = queueInd.size();
            
            while(n)
            {
                n--;
                
                int currInd = queueInd.front();
                queueInd.pop();
                
                if(currInd == arr.size() - 1)
                {
                    return steps;
                }
                
                
                vector<int>& jump_next = m[arr[currInd]];
                
                jump_next.push_back(currInd + 1);
                jump_next.push_back(currInd - 1);
                
                for(auto nextIndex : jump_next)
                {
                    if(nextIndex >= 0 && nextIndex < arr.size() && vis[nextIndex] == false)
                    {
                        queueInd.push(nextIndex);
                        vis[nextIndex] = true;
                    }
                }  
                
                jump_next.clear();
            }
            steps+=1;
        }
        
        
        return steps == 0 ? -1 : steps;
    }
};