class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        
        int row = -1;
        int rowDim = matrix.size();
        int colDim = matrix[0].size();
        
        
        
        
        for(int i = 0 ; i < matrix.size() ; i++)
        {
            if(matrix[i][colDim - 1] >= target)
            {
                row = i;
                break;
            }
        }
        
        if(row == -1)
        {
            //This Implies that the element is greater than the last elements               also
            return false;
        }
        int start = 0;
        int end = colDim - 1;
        
        //Binary Search Now !
        while(start <= end)
        {
            int mid = (start + end) / 2;
            
            if(matrix[row][mid] == target)
            {
                return true;
            }
            else if(matrix[row][mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                //matrix[row][mid] > target
                start = mid + 1;
            }
        }
        
        return false;
    }
};