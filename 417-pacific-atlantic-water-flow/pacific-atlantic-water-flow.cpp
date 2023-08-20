class Solution {
private:


    vector<int> dRow = {-1 , 0 , 1 , 0};
    vector<int> dCol = {0 , 1 , 0 , -1};

    void dfs(int row , int col , int n , int m , int prevHeight ,vector<vector<int>>& heights , 
    vector<vector<bool>>& vis){

        if(row < 0 || col < 0 || row >= n || col >= m || heights[row][col] < prevHeight || vis[row][col]){
                return;
        }

        vis[row][col] = true;

        for(int i = 0 ; i < 4 ; i++){
            int newR = row + dRow[i];
            int newC = col + dCol[i];

            dfs(newR , newC , n , m , heights[row][col]  , heights , vis);
        }



    }    

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();

        //for Atlantic Side
        vector<vector<bool>> vis1(n , vector<bool>(m , false));
        vector<vector<bool>> vis2(n , vector<bool>(m , false));
        
        for(int row = 0 ; row < n ; row++){
            //pacific
            dfs(row, 0 , n , m , heights[row][0] , heights , vis1);
            
            //atlantic
            dfs(row , m - 1 , n , m , heights[row][m - 1] , heights , vis2);
        }

        for(int col = 0 ; col < m ; col++){
            //pacific
            dfs(0 , col , n , m , heights[0][col] , heights , vis1);
            
            //atlantic
             dfs(n - 1 , col , n , m , heights[n - 1][col] , heights , vis2);
        }
        vector<vector<int>> ans;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(vis1[i][j] && vis2[i][j]){
                    ans.push_back({i , j});
                }
            }
        }


        return ans;


       

    }
};