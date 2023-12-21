class Solution {

private:
    static bool cmp(const vector<int>&a , const vector<int>&b){
        return a[0] < b[0];
    }
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {


        sort(points.begin() , points.end() , cmp);


        int maxWidth = INT_MIN;


        for(int i = 0 ; i < points.size() - 1 ; i++){

            maxWidth = max(maxWidth , points[i + 1][0] - points[i][0]);
        }

        return maxWidth;


        return 0;
    }
};