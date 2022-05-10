class Solution {
    
    vector<vector<int>> ans;
public:
    
    void solve(int curr , vector<vector<int>>& ans , int k , int n , vector<int> temp)
    {
        //base case
        if(temp.size() == k)
        {
            int sum = n;
            for(auto i : temp)
            {
                sum = sum - i;
            }
            if(sum == 0)
            {
                ans.push_back(temp);
                return;
            }           
        }
        
        
            for(int i = curr ; i < 10 ; i++)
            {
                
                temp.push_back(i);                
                
                solve(i + 1 ,ans,k,n,temp);
                
                temp.pop_back();
            }
        
    }
        
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        /*
        
            Recursive it is !!
            Backtracking again
            
            
            Base case: 
            if(temp.size() == k && sum(temp) == n)
            {
                    ans.push_back(temp);
                    return;
            }
                        
            
            
            when the vector.size() == k
            that time we append the vector to the ans - vector
            
            then we again backtrack
            remove the number and again try with the next set of numbers
            
        */
        
        // k groups alli it should sum upto n 
        
        //its always that we will be using numbers from 1 --> 9
        
        vector<int> temp;
        solve(1, ans , k , n , temp);
        return ans;
        
        
        
    }
};