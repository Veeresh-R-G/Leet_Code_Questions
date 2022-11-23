class Solution {
public:
    
    
    bool isValid(vector<vector<char>>& board , char c , int curRow , int curCol)
    {
        //row check && Col check
        for(int i = 0 ; i < 9 ; i++)
        {
            if(board[curRow][i] == c && i != curCol)
            {
                return false;
            }
            
            if(board[i][curCol] == c && i != curRow)
            {
                return false;
            }
            
            //Box Checking
            
            int row = 3 * ( curRow / 3) + (i / 3);
            int col = 3 * ( curCol / 3) + (i % 3);
            
            if(board[row][col] == c && row != curRow && col != curCol)
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
                char temp = board[row][col];
                
                if(temp != '.')
                {
                    if(isValid(board , temp , row , col) == false)
                    {
                        return false;
                    }
                }
                
            }
        }
        
        return true;
    }
};