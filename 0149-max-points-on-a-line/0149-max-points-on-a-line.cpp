class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        int N = points.size();
        
        /*
            For the logic Check Notes.txt on the Repo
        */
        
        /*
            Because 2 points will definitely form a LINE !!!
        */
        
        if(N <= 2)
        {
            return N;
        }
        
        
        
        int ans = 2;
        for(int i = 0 ; i < N ; i++)
        {
            unordered_map<double , int> tempo;
            for(int j = 0 ; j < N ; j++)
            {
                if(i != j)
                {
                    /*
                        atan(y , x) takes 2 args
                    */
                    tempo[atan2(points[j][1] - points[i][1] , points[j][0] - points[i][0])]++;
                }
            }
            
            /*
                The +1 is done to include the point itself 
                points[i]
            */
            for(auto it : tempo)
            {
                ans = max(ans , it.second + 1);
            }
        }
        
        return ans;
        
        
    }
};