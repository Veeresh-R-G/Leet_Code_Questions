

//------------------------ 2 APPROACHES WRITTEN -----------------------------

/*

    Approach - 1
    Recursive
    
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
        
        
            recursion this is!!
            
            Backtracking problem this is !!!
            
        
        
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


*/

class Solution {
    
public:    
    void solve(map<int , string>myMap, string s , int ind , vector<string>& out, string& temp)
{
    if(ind >= s.length())
    {
        out.push_back(temp);
        return;
    }
    
    string curr =  myMap[s[ind] - '0'] ;
    for(int i = 0 ; i < curr.length() ; i++)
    {
        temp.push_back(curr[i]);
        solve(myMap ,s , ind + 1 , out , temp);
        temp.pop_back();
    }
    
}
    
    vector<string> letterCombinations(string digits){        
        
        /*
        
        Non - recursive --> Iterative Solution
        
        
        */
        /*
        if(digits.empty())
        {
            return {};
        }     unordered_map<int, string> mymap;
        mymap[2] = "abc";
        mymap[3] = "def";
        mymap[4] = "ghi";
        mymap[5] = "jkl";
        mymap[6] = "mno";
        mymap[7] = "pqrs";
        mymap[8] = "tuv";
        mymap[9] = "wxyz";
        vector<string> result = {""};
        
        for(auto dig : digits)
        {
            vector<string> temp;
            for(auto curr: mymap[dig - '0'])
            {
                for(auto prev : result)
                {
                    temp.push_back(prev + curr);
                }
            }
            
            result.swap(temp);
            
        }
        
        return result;     
        */
        if(digits.length() == 0) return {};
        map<int , string> myMap;
    myMap.insert(pair<int, string>(1, ""));
    myMap.insert(pair<int, string>(2, "abc"));
    myMap.insert(pair<int, string>(3, "def"));
    myMap.insert(pair<int, string>(4, "ghi"));
    myMap.insert(pair<int, string>(5, "jkl"));
    myMap.insert(pair<int, string>(6, "mno"));
    myMap.insert(pair<int, string>(7, "pqrs"));
    myMap.insert(pair<int, string>(8, "tuv"));
    myMap.insert(pair<int, string>(9, "wxyz"));
    vector<string> out= {};
    string temp = "";
    solve(myMap, digits , 0 , out , temp);
    
    return out;
    }
    
    
};