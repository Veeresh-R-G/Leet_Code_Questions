class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
     
        int N = mat.size();
        int mid = N / 2;
        
        
        int sum = 0;
        
        
        //Lol no need of two loops nice..Good self - realisation
        for(int i = 0 ; i < N ; i++)
        {
            sum += (mat[i][i] + mat[N - 1 - i][i]);

        }
        
        sum = N % 2 ? sum - mat[mid][mid] : sum;
        
        
        return sum;
    }
};