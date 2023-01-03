class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        
        int N = strs.size();
        int M = strs[0].size();
        int c = 0;
        for(int col = 0 ; col < M ; col++)
        {
            for(int row = 0 ; row < N - 1 ; row++)
            {
                if(strs[row + 1][col] < strs[row][col])
                {
                    c++;
                    break;
                }
            }
        }
        
        return c;
    }
};