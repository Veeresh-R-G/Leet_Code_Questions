class Solution {
public:
    
    void solve(vector<int> inp , vector<int>& out , vector<vector<int>>& ans , int ind, int K)
    {
        if(ind >= inp.size())
        {
            if(K == 0)
            {
                ans.push_back(out);
            }
            return;
        }
        
        if(K < 0)
        {
            return;
        }
        
        if(inp[ind] <= K)
        {
            out.push_back(inp[ind]);
            solve(inp , out , ans , ind , K - inp[ind]);
            out.pop_back();
        }
        
        solve(inp , out , ans , ind + 1 , K);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        
        
        vector<vector<int>> ans;
        vector<int> o;
        int ind = 0;
        
        solve(candidates , o , ans , ind , target);
        
        return ans;
    }
};

/*

-----------------------------------------Approach - 2----------------------
I like approach - 1

vector<vector<int>> ans;
    
    
    /*
        
        Why currIndex --> To avoid multiple same but different ordered answers
                          We are allowing to take multiple time the same object
                          we are restricting to go back
        
        given = [2,3,6,7]
        For example when I have [3] in my temp
        I should only have 3 , 6 , 7 in any order and not have 2 again
        
        because the solution containing 2 will already be counted (if valid)
        when we have [2] in temp !!!!
        
        
        currSum ----> Base Case 
        
        if we take vector.size() >= 1 as base Case (which I was)
        
        Gone !!! I was not counting all the cases because when I have 1 element
        in my temp vector....the base case will be hit and satisfied and it will
        return back
        
        so essentially I am only checking when temp.size() == 1 and not be 
        checking further because I will be hitting the base case everytime!!
        lol took me a while to realise this !!!!
    
    void solve(int currIndex ,  vector<int> &temp , int target  , vector<int>& candi ,int currSum)
    {
        
        if(currSum == target)
        {
            ans.push_back(temp);
            return;
        }
        
        else if(currSum > target)
        {
            return;
        }
        
        for(int i = currIndex ; i < candi.size() ; i++)
        {
            
            temp.push_back(candi[i]);
            currSum += candi[i];
            solve(i,temp , target , candi , currSum);
            currSum -= candi[i];
            temp.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        
        vector<int> temp = {};
        int currSum = 0;
        int index = 0;
        solve(index,temp , target, candidates , currSum);
        
        return ans;
    }

*/