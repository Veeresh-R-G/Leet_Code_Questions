//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    
    
    void dfs(int row , int col ,vector<vector<bool>>& vis,vector<vector<int>>& grid,int rowLim , int colLim)
    {
        if(row >= rowLim || col >= colLim || row < 0 || col < 0)
        {
            return;
        }
        
        if(vis[row][col]) return;
        
        vis[row][col] = true;
        grid[row][col] = 2;
        dfs(row - 1 , col , vis , grid , rowLim , colLim);
        dfs(row + 1, col , vis , grid , rowLim , colLim);
        dfs(row , col - 1 , vis , grid , rowLim , colLim);
        dfs(row , col + 1, vis , grid , rowLim , colLim);
    }
    
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        
        int cnt = 0;
        
        int N = grid.size();
        int M = grid[0].size();
        vector<vector<int>> vis(N , vector<int>(M , 0));
        //okay we cnt use a queue here since simultaneously we can start rotting from more than one rotten
        //oranges ... So oranges at the same level rot at the same time and hence take same time !!
        //So we are using BFS
        
        queue<pair<pair<int , int> , int>> q;
        
        for(int i = 0 ; i < N ;i++)
        {
            for(int j = 0 ; j < M ; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({{i , j}, 0});
                    vis[i][j] = 2;
                }
            }
        }
        
        vector<int> delR = {-1 , 0 , 1 , 0};
        vector<int> delC = {0 , 1 , 0 , -1};
        int tm = 0;
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int tim = q.front().second;
            tm = max(tim , tm);
            q.pop();
            
            
            for(int i = 0 ; i < 4 ; i++)
            {
                int nRow = row + delR[i];
                int nCol = col + delC[i];
                
                //Boundary Checks
                //If its already visited check
                //it should be fresh check
                
                if(nRow < N && nRow >= 0 && nCol < M && nCol >= 0 && vis[nRow][nCol] != 2
                && grid[nRow][nCol] == 1)
                {
                    
                    q.push({{nRow, nCol} , tim + 1});
                    vis[nRow][nCol] = 2;
                }
            }
            
            
            
            
        }
        
        
        //check if the non-visited cell contains a fresh orange still
        for(int i = 0 ; i < N ; i++)
        {
            for(int j = 0 ; j < M ; j++)
            {
                if(vis[i][j] != 2 && grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        
        return tm;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends