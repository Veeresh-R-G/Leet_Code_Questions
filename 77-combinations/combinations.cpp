class Solution {

private:
    vector<vector<int>> ans;

    void solve(int n, int ind , vector<int> temp , int k){
        
        if(temp.size() == k){
            ans.push_back(temp);
            return;
        }
        
        
        for(int i = ind ; i <= n ; i++){
            temp.push_back(i);
            solve(n ,i + 1 , temp , k);
            temp.pop_back();
        }




    }
public:
    vector<vector<int>> combine(int n, int k) {
        
        vector<int> v;
        for(int i = 1 ; i <= n ; i++){
            v.push_back(i);
        }
        int ind = 1;
        vector<int> temp;
        solve(n , ind , temp , k);

        return ans;

    }
};