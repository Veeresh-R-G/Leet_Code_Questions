class Solution {
    
     
public:
    
    
    void solve(string digit , string output , int index , vector<string>& ans , unordered_map<int, string> mymap)
    {
        
        //base Case
        if(output.length() == digit.length())    
        {
            ans.push_back(output);
            return;
        }
        
        
        string value =  mymap[digit[index] - '0'];
        cout << value << endl;
        
        for(int i = 0 ; i < value.length() ; i++)
        {
            output.push_back(value[i]);
            solve(digit , output , index + 1 , ans , mymap);
            output.pop_back();
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        
        /*
            recursion this is!!
            
            Backtracking problem this is !!!
            
        */
        
        vector<string> ans = {};
        
        if(digits.length() == 0)
        {
            return ans;
        }
        unordered_map<int, string> mymap;
        mymap[2] = "abc";
        mymap[3] = "def";
        mymap[4] = "ghi";
        mymap[5] = "jkl";
        mymap[6] = "mno";
        mymap[7] = "pqrs";
        mymap[8] = "tuv";
        mymap[9] = "wxyz";
     
        
        
        string output = "";
        int index = 0;
        ans = {};
        
        solve(digits , output ,index , ans, mymap);
        
        return ans;
        
    }
};