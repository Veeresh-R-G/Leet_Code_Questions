class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
     
        int N = tasks.size();
        
        vector<int> ans;
        
        
        vector<vector<int>> temps;
        /*
            Sorting the tasks will make us lose the initial ordering of the tasks 
            that's why we store it as 3rd paramter
            
            { enqueue , processing , index }
        */
        for(int i = 0 ; i < N ; i++)
        {
            temps.push_back({tasks[i][0] , tasks[i][1] , i});
        }
        
        //Sort based on Enqueue time
        sort(temps.begin() , temps.end());
        
        /*
            Priority Queue
            
            pair<int , int> = {processing , index}
            
            sort on 
            1. processing
            
            If same , sort on 
            2. Index 
            
        */
        
        //Min - Heap
        priority_queue < pair<int, int> ,vector<pair<int , int>> ,  greater<> > pq;
        
        long long currTime = 0;
        int index = 0;
        while(index < N || !pq.empty())
        {
            if(pq.empty() && currTime < temps[index][0])
            {
                currTime = temps[index][0];
            }
            
            while(index < N && temps[index][0] <= currTime)
            {
                pq.push({temps[index][1] , temps[index][2]});
                index+=1;
            }
            
            pair<int , int> currTask = pq.top();
            pq.pop();
            
            //Increment time by processing time because it is non premtive
            currTime += currTask.first;
            
            //Push the index
            ans.push_back(currTask.second);
            
        }
        
        
        return ans;
        
        
        
        
    }
};