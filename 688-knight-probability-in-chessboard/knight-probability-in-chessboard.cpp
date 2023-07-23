class Solution {


private:

    vector<int> diffx = {-2 , -2 , -1 , 1 , 2, 2, 1, -1};
    vector<int> diffy = {-1 ,1, 2 ,2 , 1 , -1 ,-2 , -2};

    map<vector<int> , double> mp;
    float f(int n, int k, int row, int col){
        
        if(row < 0 || col < 0 || row >= n || col >= n){
            return 0;
        }

        if( k == 0 ) return 1;
        
        if(mp.find({row , col , k}) != mp.end())
        {
            return mp[{row, col , k}];
        }
        
        float ans = 0;
        for(int i = 0 ; i < 8 ; i++){

            int nrow = row + diffx[i];
            int ncol = col + diffy[i];
            ans += (f(n , k - 1 , nrow , ncol)) / 8; 
        }
    
        return mp[{row, col , k}] = ans;

    }
public:
    double knightProbability(int n, int k, int row, int col) {
        
        // vector<vector<vector<double>>> vis(n , vector<vector<double>>(n , vector<double>(k, -1.000)));

    
        double temp = f(n , k , row , col);

        if(k == 0) return 1.000;
        double ans = temp;
        return ans;
    }
};