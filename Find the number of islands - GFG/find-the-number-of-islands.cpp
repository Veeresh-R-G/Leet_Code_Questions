//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    void dfs(int row , int col ,vector<vector<bool>>& vis,vector<vector<char>>& grid,int rowLim , int colLim)
    {
        if(row >= rowLim || col>=colLim || row < 0 || col < 0)
        {
            return;
        }
        if(vis[row][col] || grid[row][col] == '0') return;
        vis[row][col] = true;
        
        for(int drow = -1 ; drow <= 1 ;drow++)
        {
            for(int dcol = -1 ; dcol <= 1 ; dcol++)
            {
                
                dfs(row + drow , col + dcol , vis , grid , rowLim ,colLim);
            }
        }
    }
    
  
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        
        vector<vector<bool>> vis(n  , vector<bool>(m , false));
        
        
        int cnt = 0;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                
                if(!vis[i][j] && grid[i][j] == '1')
                {
                    cnt++;
                    dfs(i , j , vis  , grid , n , m);
                }
            }
        }
        
        
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends