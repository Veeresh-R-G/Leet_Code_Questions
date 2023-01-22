class Solution {
public:
    
    bool isPalin(string str , int s , int e )
    {
        if(str == "") return false;
        
       
        
        
        
        while(s <= e)
            
        {
            if(str[s] != str[e])
            {
                return false;    
            }
            s++;
            e--;
        }
        
        return true;
        
    }
    
    void f(string s , int N , int ind , vector<string>& temp , vector<vector<string>>& ans)
    {
        if(ind >= N)
        {
            ans.push_back(temp);
            return;
        }
        
        
        for(int i = ind ; i < N ; i++)
        {
            
            if(isPalin(s , ind , i))
            {
                temp.push_back(s.substr(ind , i - ind + 1));
                f(s , N , i + 1 , temp , ans);
                temp.pop_back();
            }
        }
        
        
        
    }
    
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> ans;
        int N = s.size();
        int ind = 0;
        vector<string>temp;
        
        f(s , N , ind , temp  , ans);
        
        return ans;
    }
};