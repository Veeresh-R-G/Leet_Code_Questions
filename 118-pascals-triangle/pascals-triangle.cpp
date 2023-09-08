class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        if(numRows == 1){
            return {{1}};
        }

        if(numRows == 2){
            return {{1} , {1 , 1}};
        }

        vector<vector<int>> ans = {{1} , {1 , 1}};

        for(int row = 2 ; row < numRows ; row++){

            vector<int> temp = {1};
            
            for(int i = 1 ; i <= row - 1 ; i++){

                int ele = ans[row - 1][i - 1] + ans[row - 1][i];
                temp.push_back(ele);    
            }
            temp.push_back(1);
            ans.push_back(temp);

        }

        return ans;
    }
};