class Solution {
public:
    
    
    void dfs(vector<vector<int>>& image , int sr , int sc , int initColor , int newColor)
    {
        
        if(sr >= image.size() || sr < 0 || sc >= image[0].size() || sc < 0)
        {
            return;
        }
        
        if(image[sr][sc] != initColor) return;
        
        image[sr][sc] = newColor;
         dfs(image , sr + 1 , sc , initColor, newColor);
         dfs(image , sr - 1 , sc , initColor, newColor);
         dfs(image , sr , sc + 1 , initColor, newColor);
         dfs(image , sr , sc - 1 , initColor, newColor);
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        
        int initColor = image[sr][sc];
        int newColor = color;
        
        if(initColor != newColor)
            dfs(image , sr , sc , initColor , newColor);
        
        return image;
        
    }
};