class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        if(coordinates.size() == 2)
        {
            return true;
        }

        auto p1 = coordinates[0];
        auto p2 = coordinates[1];

        auto deltaX  = (p2[0] - p1[0]);
        auto deltaY = (p2[1] - p1[1]);


        for(int i = 2 ; i < coordinates.size() ; i++)
        {
            auto p_1 = coordinates[i];
            auto p_2 = coordinates[i - 1];

            auto currX = (p_2[0] - p_1[0]);
            auto currY = (p_2[1] - p_1[1]);

            if(deltaY * currX != (deltaX * currY))
            {
                return false;
            } 
        }

        return true;
    }
};