class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
     
        priority_queue<int> pq;
        
        int N = matrix.size();
        int M = matrix[0].size();
        for(int i = 0 ; i < N ; i++)
        {
            for(int j = 0 ; j < M ; j++)
            {
                pq.push(matrix[i][j]);
                if(pq.size() > k)
                {
                    pq.pop();
                }
            }
        }
        
        
        return pq.top();
    }
};