class Solution {

private:
    vector<vector<int>> ans;

    void solve(vector<int>&nums , int ind , vector<int> temp)
    {
     
        if(ind >= nums.size()){
            cout << "here " << endl;
            ans.push_back(nums);
            return;
        }

        for(int i = ind ; i < nums.size() ; i++){
           
            swap(nums[i] , nums[ind]);
            solve(nums , ind + 1 , temp);
            swap(nums[i] , nums[ind]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        
        vector<int> temp;
        int ind = 0;
        solve(nums , ind , temp);

        return ans;

    }
};