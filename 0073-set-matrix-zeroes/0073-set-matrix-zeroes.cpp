class Solution {
public:
    
    void make0(vector<vector<int>> &matrix , int row , int col)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        //full row as 0's
        for(int i = 0 ; i < m ;i++)
        {
            matrix[row][i] = 0;
        }

        //full col as 0
        for(int i = 0 ; i < n; i++)
        {
            matrix[i][col] = 0;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        
        
        // Write your code here.
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> temp(n , vector<int>(m , 0));

        //To know the where originally the 0's are kept
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(matrix[i][j] == 0)
                {
                    temp[i][j] = 1;
                }
            }
        }


        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(matrix[i][j] == 0 && temp[i][j] == 1)
                {
                    make0(matrix , i , j);
                }
                continue;
            }
        }
    }
};