class Solution {
public:
    
    bool isPalin(string s , int b, int e)
    {
        while(b < e)
        {
            if(s[b++] != s[e--])
            {
                return false;
            }
        }
        
        return true;
    }
    
    void solve(string s , vector<vector<string>>& ans , vector<string> out , int ind)
    {
        if(ind == s.length())
        {
            ans.push_back(out);
            return;
        }
        
        for(int i = ind ; i < s.length() ; i++)
        {
            if(isPalin(s , ind , i))
            {
                out.push_back(s.substr(ind , i - ind + 1));
                solve(s , ans , out , i + 1);
                out.pop_back();
            }
        }
        
    }
    
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> ans;
        vector<string> out;
        
        solve(s , ans, out , 0);
        
        return ans;
    }
};