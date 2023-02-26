class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int N = matrix.size();
        int M = matrix[0].size();
        
        int left = 0;
        int right = M - 1;
        int top = 0;
        int down = N - 1;
        
        vector<int> ans;
        
        while(left <= right && top <= down)
        {
            
            //Left to Right
            for(int i = left ; i <= right ; i++)
            {
                ans.push_back(matrix[top][i]);
            }
            top++;
            
    
            //Top to down
            for(int i = top ; i <= down ; i++)
            {
                ans.push_back(matrix[i][right]);
            }
            right--;
            
            //Right to Left
            if(top <= down)
            {
                for(int i = right ; i >= left ; i--)
                {
                    ans.push_back(matrix[down][i]);
                }
                down--;
            }
            
            
            //bottom to top
            if(left <= right)
            {
                for(int i = down ; i>= top ; i--)
                {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
            
            
        }
        
        return ans;
    }
};