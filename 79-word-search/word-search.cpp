class Solution {

private:

    vector<int> dRow = {-1 , 0 , 1 , 0};
    vector<int> dCol = {0 , 1 , 0 , -1};
    vector<vector<bool>> vis;
    int m , n;

    bool help(vector<vector<char>>& board, string word , int row , int col, int ind){
        

        if(row < 0 || col < 0 || row >= m || col >= n || vis[row][col] || word[ind] != board[row][col]){
            return false;
        }
        
        if(ind == word.size() - 1){
            // cout << board[row][col] << " " << row << " " << col << word[ind];
            return board[row][col] == word[ind];
        }
        vis[row][col] = true;
 
        bool temp = false;
        for(int i = 0 ; i < 4 ; i++){
            temp = temp || help(board , word , row + dRow[i] , col + dCol[i] , ind + 1);
            if(temp) return temp;
        }
         vis[row][col] = false;
        return temp;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        m = board.size();
        n = board[0].size();
        
     
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                
               
                if(board[i][j] == word[0]){
                    vis.resize(m , vector<bool>(n , false));
                    if(help(board , word, i , j , 0)){
                        return true;
                    }
                
                }
            }
            // cout << endl;
        }

        return false;

    }
};