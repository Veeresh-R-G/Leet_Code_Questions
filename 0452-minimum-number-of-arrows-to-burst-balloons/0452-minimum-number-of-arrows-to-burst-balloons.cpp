class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        if(!points.size()) return 0;
        
        int arrow = 1;
        int N = points.size();
        sort(points.begin() , points.end() , 
            [&](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        }
            );
        
        // for(auto it : points)
        // {
        //     cout << it[0] << " " << it[1] << endl;
        // }
        
        /*
            Logic : Greedy
            
            
            Sort to group the one;s that might overlap
            
            Consider Higher limit of the ballon boundary
            --->xLim
            
            
            keep Checking whether the remaining ballon's starting point falls
            before this higher Limit
            
            If yes then dont increment arrows required
            If no , then increment arrows and then change the limit 
            
            ASTE!!!
        */
        int xLim = points[0][1];
        int curr = 1;
        
        for(curr = 1 ; curr < N ; curr++)
        {
            if(points[curr][0] > xLim)
            {
                xLim = points[curr][1];
                arrow++;
                
            }
        }
//         while(curr < N)
//         {
//             if(points[curr][0] > xLim)
//             {
//                 xLim = points[curr][1];
//                 arrow++;
                
//             }
//             curr++;
//         }
        
        
        return arrow;
    }
};