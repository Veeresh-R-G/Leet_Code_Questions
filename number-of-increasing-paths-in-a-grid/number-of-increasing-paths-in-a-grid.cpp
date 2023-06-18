class Solution {

private:
    int MOD = 1e9 + 7;
    vector<int> diffRow = {-1 , 0 , 1 , 0};
    vector<int> diffCol = {0, 1 , 0 , -1};

    int f(int row , int col , int N , int M ,vector<vector<int>>& grid ,vector<vector<int>>& dp)
    {
        if(row >= N || col >= M || row < 0 || col < 0)
        {
            return 0;
        }

        if(dp[row][col] != -1)
        {
            return dp[row][col];
        }
        //Counting itself
        int ans = 1;

        for(int i = 0 ; i < 4 ; i++)
        {
            int newX = row + diffRow[i];
            int newY = col + diffCol[i];

            if(!(newX >= N || newY >= M || newX < 0 || newY < 0) && (grid[newX][newY] > grid[row][col]))
            {
                ans = ( (ans) % MOD + (f(newX , newY , N , M , grid , dp)) % MOD ) % MOD;
            }
        }

        return dp[row][col] = ans % MOD;
    }
public:
    int countPaths(vector<vector<int>>& grid) {
        

        int N = grid.size();
        int M = grid[0].size();

        long long count = 0;

        vector<vector<int>> dp(N , vector<int>(M , -1));
        for(int i = 0 ; i < N ; i++)
        {
            for(int j = 0 ; j < M ; j++)
            {
                count = (count % MOD + f(i , j , N , M , grid ,dp) % MOD) % MOD;
            }
        }

        return (int)count % MOD;
    }
};