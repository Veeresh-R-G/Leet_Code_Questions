class Solution {

private:
    vector<vector<vector<bool>>> vis;

    bool isValid(int row , int col , int n){
        
        return row >= 0 && col >= 0 && row < n && col < n;
    }
    void dfs(int row , int col , int type , int n, const vector<string>& grid){
        if(!isValid(row , col , n) || vis[row][col][type]){
            return;
        }

        vis[row][col][type] = true;

        switch(type){
            case 0:
                dfs(row - 1 , col , 2 , n , grid);
                break;
            case 1:
                dfs(row , col + 1 , 3 , n , grid);
                break;
            case 2:
                dfs(row + 1, col , 0 , n , grid);
                break;
            case 3:
                dfs(row , col - 1 , 1, n , grid);
                break;

            default:
                assert(false);
                break;
        }
            

        //internal connections -> Within A cell
        // XOR toggling sike

        //connections for 0 <---> 1 and 2 <---> 3
        if(grid[row][col] != '/'){
            dfs(row , col  , type ^ 1 , n , grid);
        }   

        //connections for 0 <--> 3 and 1 <--> 2 
        if(grid[row][col] != '\\'){
            dfs(row , col , type ^ 3 , n , grid);
        }

        
    }

public:
    int regionsBySlashes(vector<string>& grid) {
        
        //basically check how many connected components are there in the graph

        int regions = 0;
        int n = grid.size();

        vis.resize(n , vector<vector<bool>>(n , vector<bool>(4 , false)));

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                for(int type = 0 ; type < 4 ; type++){
                    if(vis[i][j][type] == false) {
                        dfs(i , j , type , n , grid);
                        regions++;
                    }
                }
                
            }
        }


        return regions;
    }
};