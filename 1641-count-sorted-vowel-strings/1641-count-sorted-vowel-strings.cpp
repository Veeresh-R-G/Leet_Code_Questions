class Solution {
public:
    int countVowelStrings(int n) {
        
        /*
            Try - 1 / Try - 2 was with backtracking ... siglilla
            
            Now Switching to dp : 
            Pattern Observation
        */
        
        // int ans;
        
        vector<int> temp = { 1, 1, 1, 1,1};
        
        vector<int> ans = temp;
        
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 3 ; j >= 0 ; j--)
            {
                ans[j] = ans[j] + ans[j + 1];
            }
        }
        
        // for(auto it : ans)
        // {
        //     cout << it << " ";
        // }
        return ans[0];
    }
};