class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<bool>> vis(n , vector<bool>(m , false));
        queue<pair<pair<int , int> , int>> q;
        vector<vector<int>> ans(n , vector<int>(m , 0));

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                
                if(mat[i][j] == 0){
                    q.push({{i ,j} , 0});
                    vis[i][j] = true;
                }
            }
        }


        vector<int> dRow = {0 , -1 , 0, +1};
        vector<int> dCol = {-1 , 0 , +1 , 0};
        while(!q.empty()){

            auto f = q.front();
            q.pop();

            int row = f.first.first;
            int col = f.first.second;
            int dist = f.second;
            ans[row][col] = dist;

            for(int i = 0 ; i < 4 ; i++){

                int newR = row + dRow[i];
                int newC = col + dCol[i];

                if(newR >= 0 && newC >= 0 && newR < n && newC < m && !vis[newR][newC]){

                    q.push({{newR , newC}, dist + 1});
                    vis[newR][newC] = true;
                }
            }
        }

        return ans;
        
    }
};