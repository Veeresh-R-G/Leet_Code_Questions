class Solution {

private:


    void solve(vector<string>& ans , string digits , int ind , string temp,
    unordered_map<int , string>& mp){
        if(temp.size() == digits.size()){
            ans.push_back(temp);
            return;
        }

        int currDigit = digits[ind] - '0';
        string curr = mp[currDigit];

        for(auto it : curr){
            temp.push_back(it);
            solve(ans , digits , ind + 1 , temp,mp);
            temp.pop_back();
        }
        
    }

public:
    vector<string> letterCombinations(string digits) {
        
        if(digits == ""){
            return {};
        }
        vector<string> ans;
        string temp = "";
        unordered_map<int, string> mymap;
        mymap[2] = "abc";
        mymap[3] = "def";
        mymap[4] = "ghi";
        mymap[5] = "jkl";
        mymap[6] = "mno";
        mymap[7] = "pqrs";
        mymap[8] = "tuv";
        mymap[9] = "wxyz";
        int ind = 0;
        solve(ans , digits , ind , temp , mymap);

        return ans;
    }
};