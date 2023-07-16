class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        if(intervals.size() <= 1)
        {
            return intervals;
        }

        //sort on basis of 1st element of the vector
        sort(intervals.begin() , intervals.end());


        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for(int i = 1 ; i < intervals.size() ; i++)
        {
            auto curr = intervals[i];
            auto temp = ans[ans.size() - 1];
            ans.pop_back();

            if(curr[0] <= temp[1]){
                //overlap happens

                //this setting of the temp[1] will fail for
                //[1 , 4] [2 , 3]
                //-> [1 , 3]
                //but expected => [1 , 4]
                //so we need to take the max
                temp[1] = max(curr[1] , temp[1]);
                ans.push_back(temp);
            }
            else
            {
                //no overlap
                ans.push_back(temp);
                ans.push_back(curr);
            }
        }

        return ans;


        return ans;

    }
};