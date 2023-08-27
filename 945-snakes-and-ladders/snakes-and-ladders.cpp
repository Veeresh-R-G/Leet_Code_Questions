class Solution {

private:
    pair<int , int> intToCoord(int n , int len){

        int row = (n - 1) / len;
        int col = (n - 1) % len;

        if(row % 2){
            col = len - col - 1;
        } 

        return {row , col};
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        

        // Square and the moves to get to that square
        queue<pair<int , int>> q;
        int n = board.size();
        reverse(board.begin() , board.end());
        q.push({1 , 0});
        map<int , int> mp;

        while(!q.empty()){

            auto f = q.front();
            q.pop();


            int currSqr = f.first;
            int moves = f.second;

            for(int i = 1 ; i <= 6; i++){
                int nextSqr = currSqr + i;
                pair<int , int> coord = intToCoord(nextSqr , n);

                if(board[coord.first][coord.second] != -1){
                    nextSqr = board[coord.first][coord.second];
                }

                if(nextSqr == n * n){
                    //reached dest
                    return moves + 1;
                }

                if(mp.find(nextSqr) == mp.end()){
                    mp[nextSqr]++;
                    q.push({nextSqr , moves + 1});
                }
            }
        }

        return -1;

    }
};