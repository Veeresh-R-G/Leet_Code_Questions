class Solution {
public:
    
    /*
        
        My Approch was to just store the outputs in a set
        to avoid duplicates
        
        But TC : O(2^n * K * Log(smthg(Set size)))
        Gave me TLE : \U0001f62d\U0001f62d
        
        
        Modified Recursion:
        To avoid duplicates we will check the previously pushed value
        same idhre we will not go to next iteration
        
        
    
    */
    
    void solve(vector<int> inp , vector<int>& out ,vector<vector<int>>&ans , int ind , int K)
    {
        if(K == 0)
        {
            cout << "-------------------\n";
            for(auto it : out)
            {
                cout << it << " ";
            }
            cout << "\n-------------------\n";
            
            
            ans.push_back(out);
            return;
        }
        
        if(K < 0)
        {
            return;
        }
        
        for(int i = ind ; i < inp.size() ; i++)
        {
            if(i > ind && inp[i] == inp[i - 1])
            { 
                continue;
                //This step only is avoiding duplicates
                //if doubt draw recursion tree again
            }
            if(inp[i] > K)
            {
                break;
            }
            cout << inp[i] <<  endl;
            out.push_back(inp[i]);
            solve(inp , out , ans , i + 1 , K - inp[i]);
            out.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& inp, int target) {
        
        
        vector<vector<int>> ans;
        vector<int> out;
        int i = 0;
        sort(inp.begin() , inp.end());
        solve(inp , out , ans , i, target);
        
        return ans;
    }
};