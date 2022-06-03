class NumMatrix {
public:
    
    vector<vector<int>> ans;
    
    NumMatrix(vector<vector<int>>& matrix) {
                    
        
        for(int i = 0 ; i < matrix.size() ; i++)
        {
            vector<int> temp(matrix[0].size() , 0);
            ans.push_back(temp);
        }
        for(int i = 0 ; i < matrix.size() ; i++)
        {
            ans[i][0] = matrix[i][0];
        }
        
        for(int i = 0 ; i < matrix.size() ; i++)
        {
            for(int j = 1 ; j < matrix[0].size() ; j++)
            {
                ans[i][j] = ans[i][j - 1] + matrix[i][j];
            }
        }
        
        for(int i = 0 ;i < matrix.size() ; i++)
        {
            for(int j = 0 ; j < matrix[0].size() ; j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
       
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int sum = 0;
        // cout << "This fund \n";
        // cout << "Ans size === " << ans.size() << endl;
        
        for(int row = row1 ; row<=row2 ; row++)
        {
            sum += ans[row][col2];
            if(col1 > 0)
            {
                sum = sum - ans[row][col1 - 1];
            }
        }
        
        cout << sum << " \n";
        
        
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */