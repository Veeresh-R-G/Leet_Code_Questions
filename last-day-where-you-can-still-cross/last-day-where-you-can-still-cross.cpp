class Solution {
public:

    bool solve(int row , int col , int n , int m , vector<vector<int>>& grid,vector<vector<bool>>& vis,vector<vector<int>>& dp)
    {
        
        if (row >= n || col >= m || row < 0 || col < 0 || grid[row][col] == 1|| vis[row][col])
        {
            return false;
        }

        if(row == n - 1)
        {
            return true;
        }
        
        if(dp[row][col] != -1)
        {
            return dp[row][col];
        }
        vis[row][col] = true;
        

        bool left = solve(row , col - 1 , n , m , grid,vis,dp);
        bool right = left || solve(row , col + 1 , n , m , grid,vis,dp);
        bool up = right || left || solve(row - 1 , col , n , m , grid,vis,dp);
        bool down = left || right || up || solve(row + 1 , col , n , m , grid, vis,dp);

        return dp[row][col] = left || right || up || down;
        // return left || right || up || down;

    }

    bool canWalk(vector<vector<int>>&cells , int row , int col , int mid)
    {
        vector<vector<int>> grid(row , vector<int>(col , 0));

        for(auto i = 0 ; i < mid ; i++)
        {
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }

        vector<vector<bool>> vis(row , vector<bool>(col , false));
        vector<vector<int>> dp(row , vector<int>(col , -1));


        for(int i = 0 ; i < col ; i++)
        {
            //land only
            if(grid[0][i] == 0)
            {
                if(solve(0 , i , row , col , grid,vis , dp))
                {
                    return true;
                }
            }
        }

        return false;

    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        
        //all 0's initially
        
        int ans = 0;
        int left = 1;
        int right = cells.size() - 1;

        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(canWalk(cells , row , col , mid))
            {
                ans = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }

        }
        return ans;

    }
};