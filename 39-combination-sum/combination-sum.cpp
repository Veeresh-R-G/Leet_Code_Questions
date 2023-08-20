class Solution {

private:
    vector<vector<int>> ans;
    void help(int ind , vector<int>& arr , vector<int>temp , int currSum , int target){
        if(ind >= arr.size() || currSum > target){
            return;
        }


        if(currSum == target){
            ans.push_back(temp);
            return;
        }

        temp.push_back(arr[ind]);
        help(ind , arr , temp , currSum + arr[ind] , target);

        temp.pop_back();
        help(ind + 1 , arr ,temp , currSum , target);
    }
public: 
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<int> temp;
        help(0 , candidates , temp , 0 , target);
        return ans;    
    }
};