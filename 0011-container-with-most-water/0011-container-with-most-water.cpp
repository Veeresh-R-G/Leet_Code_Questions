class Solution {
public:
    int maxArea(vector<int>& height) {
        int s = 0;
        int e = height.size() - 1;
        
        int mini = INT_MIN;
        while(s < e)
        {   
            // cout << s << " " << e << endl;
            int w = e - s;
            int h = min(height[s] , height[e]);
            // cout << w << " " << h << endl;
            mini = max(mini , (w * h));
            
            if(height[s] <= height[e]) s++;
            else e--;
            
        }
        
        return mini;
    }
};