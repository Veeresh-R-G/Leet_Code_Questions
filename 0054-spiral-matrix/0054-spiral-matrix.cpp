class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int N = matrix.size();
        int M = matrix[0].size();
        
        
        int row = 0;
        int col = 0;
        int rowEnd = N - 1;
        int colEnd = M - 1;
        
        int count = 0;
        int total = N * M;
        
        vector<int> ans;
        
        while(count < total)
        {
            //left to right
            for(int i = col ; count<total && i <= colEnd ; i++)
            {
                ans.push_back(matrix[row][i]);
                count++;
            }
            row++;
            //top to bottom
            for(int i = row ; count<total && i <= rowEnd ; i++)
            {
                ans.push_back(matrix[i][colEnd]);
                count++;
            }
            colEnd--;
            
            //right to left
            for(int i = colEnd ; count<total && i >= col ;i--)
            {
                ans.push_back(matrix[rowEnd][i]);
                count++;
            }
            rowEnd--;
            //bottom to top
            for(int i = rowEnd ; count<total && i >= row ; i--)
            {
                ans.push_back(matrix[i][col]);
                count++;
            }
            col++;
        }
        
        return ans;
        
    }
};