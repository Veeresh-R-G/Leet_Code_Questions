class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        
        if(n == 1)
        {
            return {{1}};
        }
        if(n == 2)
        {
            return {{1} , {1, 1}};
        }
        
        vector<vector<int>> ans = {{1} , {1, 1}};

        //n == 4
        for(int i = 2 ; i < n ; i++)
        {
            vector<int> temp;
            temp.push_back(1);
            for(int j = 1 ; j < ans[i- 1].size(); j++)
            {
                int one = ans[i - 1][j];
                int two = ans[i - 1][j - 1];

                int sum = one + two;

                temp.push_back(sum);
            }
            temp.push_back(1);

            ans.push_back(temp);
        }
        return ans;
        
    }
};