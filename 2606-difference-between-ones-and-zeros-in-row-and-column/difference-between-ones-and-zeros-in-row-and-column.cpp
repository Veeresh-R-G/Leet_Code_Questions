class Solution {

private:

    void helper(vector<vector<int>>& grid, vector<int>& v, bool row, bool one){


        int N = grid.size();
        int M = grid[0].size();

        if(row){

            if(one){

                for(int i = 0 ; i < N ; i++){
                    for(int j = 0 ; j < M ; j++){
                        if(grid[i][j]){
                            v[i]++;
                        }
                    }
                }
                return;
            }

            for(int i = 0 ; i < N ; i++){
                for(int j = 0 ; j < M ; j++){
                    if(!grid[i][j]){
                        v[i]++;
                    }
                }
            }
            return;
        }

        if(one){
            for(int i = 0 ; i < M ; i++){
                for(int j = 0 ; j < N ; j++){
                    if(grid[j][i]){
                        v[i]++;
                    }
                }
            }
            return;
        }

        for(int i = 0 ; i < M ; i++){
            for(int j = 0 ; j < N ; j++){
                if(!grid[j][i]){
                    v[i]++;
                }
            }
        }
    }

public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {

        int N = grid.size();
        int M = grid[0].size();
        vector<vector<int>> ans(N, vector<int>(M , 0));

        vector<int> rowOne(N , 0);
        vector<int> rowZero(N , 0);
        vector<int> colOne(M , 0);
        vector<int> colZero(M , 0);

        helper(grid, rowOne, true, true);
        helper(grid, rowZero, true, false);
        helper(grid, colOne, false, true);
        helper(grid, colZero, false, false);

        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < M ; j++){

                ans[i][j] = rowOne[i] + colOne[j] - rowZero[i] - colZero[j];

            }
        }


        return ans;

    }
};