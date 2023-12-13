class Solution {

private:

    void helper(vector<vector<int>>&mat, vector<int>& temp, bool row){
        int N = mat.size();
        int M = mat[0].size();
        if(row){
            for(int i = 0 ; i < N; i++){
                for(int j = 0; j < M; j++){
                    if(mat[i][j]){
                        temp[i]++;
                    }
                }
            }
            return;
        }

        for(int i = 0 ; i < M; i++){
            for(int j = 0; j < N ; j++){
                if(mat[j][i]){
                    temp[i]++;
                }
            }
        }
    }

public:
    int numSpecial(vector<vector<int>>& mat) {
        
        vector<pair<int , int>> temp;
        int N = mat.size();
        int M = mat[0].size();
        int ans = 0;
        vector<int> rowOne(N, 0);
        vector<int> colOne(M, 0);

        
        //row counting
        helper(mat, rowOne, true);
        for(auto it : rowOne) cout << it <<" ";
        cout << endl;
        //column counting
        helper(mat, colOne, false);
        for(auto it : colOne) cout << it << " ";


        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < M ;j++){
                if(mat[i][j]){
                    if(rowOne[i] == 1 && colOne[j] == 1){
                        ans++;
                    }                   
                }
            }
        }

        return ans;

    }
};