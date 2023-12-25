class Solution {


private:

    vector<int> dp;

    int helper(string& s,int ind){
        if(ind > s.size() || s[ind] == '0'){
            return 0;
        }

        if(ind == s.size() - 1 || ind == s.size()){
            return 1;
        }

        if(dp[ind] != -1){
            return dp[ind];
        }

        int sizeOne = helper(s, ind + 1);
        int sizeTwo = 0;

        string temp = s.substr(ind , 2);

        if(stoi(temp) <= 26 && stoi(temp) > 0){
            sizeTwo = helper(s, ind + 2);
        }

        return dp[ind] = sizeOne + sizeTwo;
    }


public:
    int numDecodings(string s) {
        
        int ind = 0;
        dp.resize(s.size() , -1);

        return helper(s,ind);
    }
};