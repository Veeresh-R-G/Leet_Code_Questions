class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> ans(n  , vector<int>(n , 0));
        
        
        int row = 0;
        int rowEnd = n - 1;
        int col = 0;
        int colEnd = n - 1;
        
        
        int count = 1;
        int total = n * n;
        
        while(count <= total)
        {
            for(int i = col ; count <= total && i <= colEnd ;i++)
            {
                ans[row][i] = count;
                count++;
            }
            row++;
            
            for(int i = row ; count <= total && i <= rowEnd ; i++)
            {
                ans[i][colEnd] = count;
                count++;
            }
            colEnd--;
            
            for(int i = colEnd ; count <= total && i >= col ;i--)
            {
                ans[rowEnd][i] = count;
                count++;
            }
            rowEnd--;
            
            for(int i = rowEnd ; count <= total && i >= row ; i--)
            {
                ans[i][col] = count;
                count++;
            }
            col++;            
        }
        
        return ans;
    }
};