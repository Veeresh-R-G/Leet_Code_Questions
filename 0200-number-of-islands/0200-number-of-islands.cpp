class Solution {
public:
    
    void dfs(int row , int col , vector<vector<bool>>& vis , vector<vector<char>>& grid)
    {
        if(row >= vis.size() || row < 0 || col >= vis[0].size() || col < 0 || grid[row][col] == '0')
        {
            return;
        }
        if(vis[row][col] == true) return;
        vis[row][col] = true;
        dfs(row + 1, col , vis , grid);
        dfs(row - 1, col , vis , grid);
        dfs(row , col - 1 , vis , grid);
        dfs(row , col + 1 , vis , grid);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        
        int N = grid.size();
        int M = grid[0].size();
        
        vector<vector<bool>> vis(N , vector<bool>(M , false));
        
        
        int count = 0;
        for(int i = 0 ; i < N ; i++)
        {
            for(int j = 0 ; j < M ; j++)
            {
                if(vis[i][j] == false && grid[i][j] == '1')
                {
                    dfs(i , j , vis , grid);
                    count++;
                }
            }
        }
        
        
        return count;
        
        
    }
};