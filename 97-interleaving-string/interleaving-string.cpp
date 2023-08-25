class Solution {

private:
    vector<vector<vector<int>>> dp;
    bool solve(int a, int b , int c , string s1 , string s2 , string s3){

        if(c == s3.size()){
            return a == s1.size() && b == s2.size();
        }

        if(dp[a][b][c] != -1){
            return dp[a][b][c];
        }

        bool f = false;
        bool s = false;
        if(s1[a] == s3[c]){
            f = f || solve(a + 1 , b , c + 1 , s1 , s2 , s3);
        }

        if(s2[b] == s3[c]){
            s = s || solve(a , b + 1 , c + 1 , s1 , s2 , s3);
        }

        return  dp[a][b][c] = f || s;
    }
public:


    bool isInterleave(string s1, string s2, string s3) {
        
        int a = 0;
        int b = 0;
        int c = 0;
        dp.resize(s1.size() + 1 , vector<vector<int>>(s2.size() + 1 , vector<int>(s3.size() + 1 , -1)));
        string temp = "";
        return solve(a , b , c , s1 , s2 , s3);
    }
};