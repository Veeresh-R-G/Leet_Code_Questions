class Solution {
public:
    
    bool isSafe(int row,int col , vector<string>&board , int n)
    {
        /*
            Only 3 possible moments we should check here
        */
        
//         cout << "-------------------------------\n";
//         for(auto ele : board)
//         {
//             for(auto item : ele)
//             {
//                 cout << item << " ";
                
//             }
//             cout << endl;
//         }
//         cout << "-------------------------------\n";

        
        //DIAGONAL-1
        int t1 ,t2;
        t1 = row , t2 = col;
        while(t1 >= 0 && t2 >=0)
        {
            if(board[t1][t2] == 'Q')
            {
                return false;
            }
            t1--;
            t2--;
        }
        

        
        //DIAGONAL - 2
        t1 = row , t2 = col; // t1 = 0 t2 = 2
        while(t1 < n && t2 >=0)
        {
            if(board[t1][t2] == 'Q')
            {
                return false;
            }
            t1++;
            t2--;
        }

        
        //LEFT
        t1 = row , t2 = col;
        while(t2 >=0)
        {
            if(board[t1][t2] == 'Q')
            {
                return false;
            }
            t2--;
        }

        
        
        
        return true;
    }
    
    void solve(int n , int col , vector<vector<string>> &ans , vector<string>&board)
    {
        if(col == n)
        {
            ans.push_back(board);
            return;
        }
        
        for(int row = 0 ; row < n ; row++)
        {
            if(isSafe(row , col , board , n))
            {
                // cout << row << col << endl;
                board[row][col] = 'Q';
                solve(n , col + 1 , ans , board);
                board[row][col] = '.';
                
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;
        
        vector<string> board(n);
        
        string s(n , '.');
        
        for(int i = 0 ; i < n ; i++)
        {
            board[i]=(s);
        }
        
        solve(n , 0 , ans , board);
        
        return ans;
        
    }
};