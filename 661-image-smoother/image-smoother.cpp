class Solution {

private:
    vector<vector<int>> ans;
    vector<int> dx = {-1, -1, 0, 1, 1, 1, 0, -1};
    vector<int> dy = {0, 1, 1, 1, 0, -1, -1, -1};

    bool check(int row, int col, int rowLim , int colLim){

        return row < rowLim && col < colLim && col >= 0 && row >= 0;
    }

    int helper(vector<vector<int>>& img, int row, int col, int rowLim , int colLim){

        int cnt = 1;
        int sum = img[row][col];
        for(int i = 0 ; i < 8; i++){
            int currRow = row + dx[i];
            int currCol = col + dy[i];

            if(check(currRow, currCol, rowLim, colLim)){
                cnt++;
                sum += img[currRow][currCol];
            }
        }

        return (sum / cnt);
    }
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
    
        int n = img.size();
        int m = img[0].size();

        ans.resize(n, vector<int>(m ,0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans[i][j] = helper(img,i,j,n,m);
            }
        }

        return ans;
    }
};