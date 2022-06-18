class Solution {
public:
    
    bool isValid(vector<vector<char>>& board , int row , int col , char c)
    {
        for(int i = 0 ; i < 9 ; i++)
        {
            
            if(board[row][i] == c && i != col)
            {
                return false;
            }
            
            if(board[i][col] == c && i != row)
            {
                return false;
            }
           
            int t1 = 3 * (row / 3) + (i / 3);
            int t2 = 3 * (col / 3) + (i % 3);
            if(board[t1][t2] == c
              && t1!=row && t2 != col)
            {
                return false;
            }
        }
        
        return true;
    }
    
    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        
        for(int row = 0 ; row < 9 ; row++)
        {
            for(int col = 0 ; col < 9 ; col++)
            {
                if(board[row][col] != '.')
                {
                    char dig = board[row][col];
                    // cout << dig << " ";
                    if(!isValid(board , row , col , dig))
                    {
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};